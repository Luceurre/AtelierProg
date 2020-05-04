//
// Created by pglandon on 5/2/20.
//

#ifndef ATELIERPROG_CROSS_SOCKET_H
#define ATELIERPROG_CROSS_SOCKET_H

#ifdef WIN64
    #include <winsock2.h>
    #include <Ws2tcpip.h>
    #define ADDR_SIZE int
#elif __unix
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <cstring>
    #include <unistd.h>
#include <cassert>

#define closesocket close
    #define SOCKET int
    #define ADDR_SIZE unsigned int
#endif

#define PROTOCOL AF_INET // IPv4
#define PROTOCOL_WRAPPER SOCK_STREAM // TCP

#define MESSAGE_SIZE 1024

#include <iostream>
#include <chrono>

#define ID int
#define NO_ID 0

// Retient l'ip de l'émetteur en plus.
// Evite d'avoir deux tableaux.
struct MySocket {
    SOCKET socket;
    ADDR_SIZE addr_size;
    sockaddr addr;
};

enum ID_State {
    NOT_IDENTIFIED,
    IDENTIFIED
};

enum Socket_Type {
    INPUT_SOCKET,
    OUTPUT_SOCKET,
    NONE
};

struct ID_Wrapper {
    ID_State state;
    ID id;
    Socket_Type st;
};

int getSO_ERROR(SOCKET fd);

void closeSocket(SOCKET fd);

bool haveInput(SOCKET fd, double timeout);

double getWallTimeEpoch();

bool flushSocketBeforeClose(SOCKET fd, double timeout);

void forceCloseSocket(SOCKET fd);

// Not really unique, but who cares ?
ID next_ID();
#endif //ATELIERPROG_CROSS_SOCKET_H
