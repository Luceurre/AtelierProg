//
// Created by pglandon on 5/2/20.
//

#include "Server.h"

Server::Server(int port, int max_connection) {
    this->sockets = new MySocket[max_connection];
    this->sockets_thread = new std::thread*[max_connection];
    this->max_connection = max_connection;
    this->current_connection = 0;
    this->port = port;

    // On initialise la socket principale

    this->main_socket = socket(PROTOCOL, PROTOCOL_WRAPPER, 0);
    if (main_socket < 0) {
        error("Couldn't create main socket!");
    }
}

void Server::set_max_connection(int new_max_connection) {
    if (this->current_connection > new_max_connection) {
        this->error("Can't reduce max connection! You have too much on going connection!");
    } else {
        this->max_connection = new_max_connection;

        // TODO : realloc memory here.
    }
}

void Server::force_set_max_connection(int new_max_connection) {
    int connection_to_close = new_max_connection - current_connection;
    int local_current_connection = current_connection; // Obligé car current_connection diminue à chaque fois.
    for(int i = 0; i < connection_to_close; ++i) {
        close_connection(sockets[local_current_connection - i]);
    }

    set_max_connection(new_max_connection);
}

void Server::close_connection(MySocket socket) {
    // TODO : properly close the connection.

    forceCloseSocket(socket.socket);
    current_connection--;
}

Server::~Server() {
    listening = false;

    int local_current_connection = current_connection; // Obligé car current_connection diminue à chaque fois.

    // On commencce par fermer toutes les connections
    for (auto outSocket : output_sockets) {
        forceCloseSocket(outSocket.second);
    }

    for (auto inSocket : input_sockets) {
        forceCloseSocket(inSocket.second);
    }

    info("Server shutdown...");

    // On peut libérer le socket
    forceCloseSocket(main_socket);

    connection_thread->join();

    // On a fermé toutes les sockets, normalement elle devrait rendre la main maintenant...
    for (int i = 0; i < local_current_connection; ++i) {
        sockets_thread[i]->join();
    }

    // On détruit le thread d'acceptation.
    delete connection_thread;
    delete sockets_thread;
}

void Server::initialize() {
    sockaddr_in addr{};
    addr.sin_family = PROTOCOL;
    addr.sin_addr.s_addr = INADDR_ANY; // On accepte toutes les connections.
    addr.sin_port = htons(port);

    if (bind(main_socket, (sockaddr *) &addr, sizeof(addr)) < 0) {
        error("Couldn't bind socket on port : " + std::to_string(port));
        return;
    }

    if (listen(main_socket, 2 * max_connection) < 0) {
        error("Couldn't listen socket!");
        return;
    } else {
        info("Server listening on port : " + std::to_string(port));
    }

    // On crée le thread d'appel
    listening = false;
    connection_thread = new std::thread(&Server::accept_connection, this);
}

// Comment choisit-on la condition d'arrêt du thread ?
// problème -> la fonction accept est bloquante
// solution -> lui mettre un temps d'arret, et loop sur une condition.
// nouveau problème -> quel coût à accept ?
// Pour l'instant, on le fait de façon bourrin et on libère juste la socket depuis un autre thread.
void Server::accept_connection() {
    listening = true;
    while (listening) {
        // Normalement main_socket (sauf pour sa destruction) est utilisée uniquement ici.
        // On est donc thread safe.
        MySocket tempSocket{};
        tempSocket.socket = accept(main_socket, &tempSocket.addr, &tempSocket.addr_size);

        if (tempSocket.socket < 0) {
            error("Connection failed!");
        } else {
            if (current_connection < max_connection) {
                // Multithread this ?
                // bô jeu oui, mais nécessaire ?
                // possible même ?
                // ... c'est ce que nous allons voir !
                // Possible ! Mais on a besoin de séparer les sockets d'envoi et de réception...
                // Mise en place d'un protocole d'identification alors..

                /* sockets[current_connection] = tempSocket;
                sockets_thread[current_connection] = new std::thread(&Server::handle_connection, this, &sockets[current_connection]);
                current_connection++;
                info("Added a new connection!"); */

                // On attend l'identification maintenant
                ID_Wrapper id{};
                recv(tempSocket.socket, &id, sizeof(id), 0);

                // TODO : wrap this in a try/catch, we don't know if the client knows the protocol

                // C'est la première connection du client, on lui donne un id et on ferme la connection
                ID new_id = next_ID();
                if (id.state == NOT_IDENTIFIED) {
                    send(tempSocket.socket, &new_id, sizeof(new_id), 0);
                    close(tempSocket.socket);
                } else if (id.state == IDENTIFIED) {
                    // On ajoute la socket dans la bonne map!
                    if (id.st == OUTPUT_SOCKET) {
                        output_sockets.emplace(id.id, tempSocket.socket);
                    } else {
                        // On en profite pour lancer l'écoute sur ces sockets
                        input_sockets.emplace(id.id, tempSocket.socket);
                        sockets_thread[current_connection] = new std::thread(&Server::handle_connection, this, tempSocket.socket);
                    }
                    current_connection++;
                } else {
                    error("Protocol wasn't correctly implemented on client side!");
                }
            } else {
                forceCloseSocket(tempSocket.socket);
                error("Couldn't add connection, server is full");
            }
        }
    }
}

void Server::handle_connection(SOCKET socket) {
    char buffer[MESSAGE_SIZE];

    recv(socket, buffer, MESSAGE_SIZE, 0);

    broadcast(buffer, MESSAGE_SIZE);
}

void Server::broadcast(char *buffer, int buffer_size) {
    for (auto outSocket : output_sockets) {
        send(outSocket.second, buffer, buffer_size, 0);
    }
}

bool Server::wait_til_accept_connection() {
    while (!listening) {
        sleep(1);
    }
}
