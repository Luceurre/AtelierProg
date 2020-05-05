//
// Created by pglan on 02/05/2020.
//

#include <thread>
#include <iostream>
#include <mutex>
#ifdef WIN64
    #include <winsock2.h>
    #include <Ws2tcpip.h>
    #define ADDR_SIZE int
#elif __unix
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <string.h>
#include <unistd.h>

    #define closesocket close
#define SOCKET int
#define ADDR_SIZE unsigned int
#endif

#include "Network/Server.h"
#include "Network/Client.h"

#include <vector>
#include <SDL.h>

using namespace std;

void client();
void server();

mutex out_stream_mutex;
mutex socket_creation;

int main(int argc, char* argv[]) {
    #ifdef WIN64
        int iResult;
        WSADATA wsaData;
        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (iResult != 0) {
            cout << "WSAStartup failed: " << iResult <<"\n";
            return -1;
        }
    #endif
        // C'est parti pour quelques tests !



        // client2.send_message("Va te faire enculer :)", MESSAGE_SIZE);
        /*
        vector<OldClient> clients;

        for(int i = 0; i < 8; ++i) {
            clients.emplace_back("127.0.0.1", 1234);
            clients.back().initialize();
        }
        */
        // clients.back().send_message("Hello World!", MESSAGE_SIZE);

        SDL_Init(SDL_INIT_EVERYTHING);



        Server srv;
        // srv.wait();
        sleep(1);
        Client clt;
        // clt.send_cstring("Hello, World!", 13);
        clt.connect();

        srv.wait();

    return 0;
}

/*

void client() {
    char *msg = "Hello from client!";

    sockaddr_in serv_address;
    unique_lock<mutex> lock(out_stream_mutex);
    cout << "I'm client!"  << endl;
    lock.unlock();

    // Voir serveur, c'est la même chose ici
    SOCKET chaussette = socket(AF_INET, SOCK_STREAM, 0);
    if(chaussette < 0) {
        lock.lock();
        cout << "(OldClient) Couldn't create socket!" << endl;
        lock.unlock();
        return;
    } else {
        lock.lock();
        cout << "(OldClient) Socket created!" << endl;
        lock.unlock();
    }

    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_address.sin_addr)<=0)
    {
        lock.lock();
        cout << "(OldClient) Invalid address!" << endl;
        lock.unlock();
        return;
    }

    unique_lock<mutex> socket_lock(socket_creation);
    int connect_result = connect(chaussette, (struct sockaddr *)&serv_address, sizeof(serv_address));
    socket_creation.unlock();
    if (connect_result < 0) {
        lock.lock();
        cout << "(OldClient) Connection failed!" << endl;
        lock.unlock();
        return;
    } else {
        lock.lock();
        cout << "(OldClient) Connection succeed!" << endl;
        lock.unlock();
    }

    send(chaussette, msg, strlen(msg), 0);
    closesocket(chaussette);
}

void server() {
    unique_lock<mutex> socket_lock(socket_creation);

    sockaddr_in address;
    int buffer_size = 256;
    char buffer[buffer_size];
    int timeout = 3;

    unique_lock<mutex> lock(out_stream_mutex);
    cout << "I'm server!" << endl;
    lock.unlock();


    // Création de la chaussette
    SOCKET chaussette = socket(AF_INET, SOCK_STREAM, 0);
    if(chaussette < 0) {
        lock.lock();
        cout << "(Server) Couldn't create socket!" << endl;
        lock.unlock();
        return;
    } else {
        lock.lock();
        cout << "(Server) Socket created!" << endl;
        lock.unlock();
    }

    // On initialise le port d'écoute
    address.sin_family = AF_INET; // Protocole d'écoule IPv4
    address.sin_addr.s_addr = INADDR_ANY; // On accepte les connections depuis n'importe quelle addresse
    address.sin_port = htons(PORT); // On choisit le port d'écoute.

    int bind_result = bind(chaussette, (sockaddr * )&address, sizeof(address));
    if(bind_result < 0) {
        lock.lock();
        cout << "(Server) Couldn't bind socket!" << endl;
        cout << strerror(errno) << endl;
        lock.unlock();
        return;
    } else {
        lock.lock();
        cout << "(Server) Socket binded!" << endl;
        lock.unlock();
    }

    int listen_result = listen(chaussette, 1);
    if(listen_result < 0) {
        lock.lock();
        cout << "(Server) Couldn't listen socket!" << endl;
        lock.unlock();
        return;
    }

    socket_lock.unlock();

    cout << "Does it wait ?" << endl;

    ADDR_SIZE addr_length = sizeof(address);
    int nouvelle_chaussette = accept(chaussette, (sockaddr *) &address, &addr_length);
    if (nouvelle_chaussette<0) {
        lock.lock();
        cout << "(Server) Couldn't accept connection!" << endl;
        lock.unlock();
        return;
    } else {
        lock.lock();
        cout << "(Server) Connection succeed!" << endl;
        lock.unlock();
    }


    for(int i = 0; i < 2; ++i) {
        int valread = recv(nouvelle_chaussette, buffer, buffer_size, 0);
        cout << "(Server) Message received : " << buffer << endl;
    }

    closesocket(nouvelle_chaussette);
    closesocket(chaussette);
    return;
} */