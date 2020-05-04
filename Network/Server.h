//
// Created by pglandon on 5/2/20.
//

#ifndef ATELIERPROG_SERVER_H
#define ATELIERPROG_SERVER_H

#include "cross_socket.h"
#include "../API/Logger.h"

#include <vector>
#include <thread>
#include <map>

#define DEFAULT_MAX_SIMULTANEOUS_CONNECTION 8
#define DEFAULT_PORT 1234

// Crée un serveur.
// Le nombre de connections maximale est de 8
class Server : protected Logger {
    // Highway sockets
    std::map<ID, SOCKET> input_sockets;
    std::map<ID, SOCKET> output_sockets;

    MySocket* sockets;
    SOCKET main_socket;
    int max_connection;
    int current_connection;
    int port;

    bool listening;

    // Pointer here because I need to explicitely call the destructor
    std::thread* connection_thread;
    std::thread** sockets_thread;


    // Change le nombre maximum de connection au serveur.
    // Can't actually changed it, listening is non-blocking... anyway...
    void set_max_connection(int new_max_connection);
    void force_set_max_connection(int new_max_connection);
    void close_connection(MySocket socket);

    // Create a thread to listen to new incomming connection.
    void accept_connection();
    // Each connection should be handle in a different thread, in this function.
    void handle_connection(SOCKET socket);

    void broadcast(char *buffer, int buffer_size);

public:
    // On commence à écouter, on accepte les connections, mais on ne lance pas encore de logique.
    // On aurait pu reprendre la structure d'une scene ? Probablement, tant pis...
    void initialize();

    explicit Server(int port = DEFAULT_PORT, int max_connection = DEFAULT_MAX_SIMULTANEOUS_CONNECTION);
    ~Server();

    bool wait_til_accept_connection();
};


#endif //ATELIERPROG_SERVER_H
