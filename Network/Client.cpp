//
// Created by pglandon on 5/2/20.
//

#include "Client.h"

Client::Client(const char* ip, int port) {
    server_addr = {};
    server_addr.sin_family = PROTOCOL;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    this->input_socket = socket(PROTOCOL, PROTOCOL_WRAPPER, 0);
    this->output_socket = socket(PROTOCOL, PROTOCOL_WRAPPER, 0);
    id = NO_ID;
}

void Client::initialize() {
    identification();
    make_sockets();

    listening = true;
    receive_thread = std::thread(&Client::receive, this);
    /*
    if (connect(client_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Couldn't connect to server : ");
        error(strerror(errno));
        return;
    } else {
        info("Connection succeed!");
    }

    // La


     */
}

void Client::receive() {
    while (listening) {
        sleep(1);

        char buffer[MESSAGE_SIZE];
        info("I'm listening");
        recv(output_socket, buffer, MESSAGE_SIZE, 0);

        info(buffer);
    }
}

void Client::send_message(char *buffer, int buffer_size) {
    info("I'm sending!");
    send(input_socket, buffer, buffer_size, 0);
}

Client::~Client() {
    listening = false;
    close(input_socket);
    close(output_socket);

    receive_thread.join();
}

// TODO : check if identification actually succeed...
void Client::identification() {
    SOCKET client_socket = socket(PROTOCOL, PROTOCOL_WRAPPER, 0);;

    if (connect(client_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Couldn't connect to server : ");
        error(strerror(errno));
        return;
    }
    info("Connection succeed! Begins identification");
    ID_Wrapper new_id{NOT_IDENTIFIED, NO_ID, NONE};

    // On envoie le message comme quoi c'est la 1ere fois que l'on se connecte.
    send(client_socket, &new_id, sizeof(new_id), 0);
    // On recoit notre identification pour discuter avec le serveur.
    recv(client_socket, &id, sizeof(id), 0);

    close(client_socket);

    info("Identification succeed! Client id is : " + std::to_string(id));
}

void Client::make_sockets() {
    if (id == NO_ID) {
        error("Client is not identified yet, call identification() first!");
        return;
    }
    if (connect(input_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Couldn't connect to server : ");
        error(strerror(errno));
        return;
    }
    ID_Wrapper inputWrapper{IDENTIFIED, id, INPUT_SOCKET};
    send(input_socket, &inputWrapper, sizeof(inputWrapper), 0);

    if (connect(output_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Couldn't connect to server : ");
        error(strerror(errno));
        return;
    }
    ID_Wrapper outputWrapper{IDENTIFIED, id, OUTPUT_SOCKET};
    send(output_socket, &outputWrapper, sizeof(outputWrapper), 0);
}
