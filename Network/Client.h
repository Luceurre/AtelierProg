//
// Created by pglandon on 5/2/20.
//

#ifndef ATELIERPROG_CLIENT_H
#define ATELIERPROG_CLIENT_H

#include <string>
#include <thread>

#include "cross_socket.h"
#include "../API/Logger.h"

class Client : protected Logger {
    sockaddr_in server_addr;
    SOCKET input_socket;
    SOCKET output_socket;
    bool listening;
    ID id;

    std::thread receive_thread;

    void identification();
    void make_sockets();

public:
    Client(const char* ip, int port);
    ~Client();

    void initialize();
    void receive();
    void send_message(char* buffer, int buffer_size);
};


#endif //ATELIERPROG_CLIENT_H
