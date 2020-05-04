//
// Created by pglandon on 5/3/20.
//

#include "cross_socket.h"

int getSO_ERROR(SOCKET fd) {
    int err = 1;
    socklen_t len = sizeof err;
    if (-1 == getsockopt(fd, SOL_SOCKET, SO_ERROR, (char *)&err, &len))
        perror("getSO_ERROR");
    if (err)
        errno = err;              // set errno to the socket SO_ERROR
    return err;
}

void closeSocket(SOCKET fd) {      // *not* the Windows closesocket()
    if (fd >= 0) {
        getSO_ERROR(fd); // first clear any errors, which can cause close to fail
        if (shutdown(fd, SHUT_RDWR) < 0) // secondly, terminate the 'reliable' delivery
            if (errno != ENOTCONN && errno != EINVAL) // SGI causes EINVAL
                perror("shutdown");
        if (close(fd) < 0) // finally call close()
            perror("close");
    }
}

bool haveInput(SOCKET fd, double timeout) {
    int status;
    fd_set fds;

    struct timeval tv{};
    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    tv.tv_sec = (long)timeout;
    tv.tv_usec = (long)((timeout - tv.tv_sec) * 1000000);

    while (1) {
        if (!(status = select(fd + 1, &fds, 0, 0, &tv)))
            return false;
        else if (status > 0 && FD_ISSET(fd, &fds))
            return true;
        else if (status > 0) {
            std::cout << "I'm confused!" << std::endl;
            exit(-1);
        }
        else if (errno != EINTR) {
            std::cout << "select" << std::endl;
            exit(-1);
        }
    }
}

double getWallTimeEpoch() {
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

bool flushSocketBeforeClose(SOCKET fd, double timeout) {
    const double start = getWallTimeEpoch();
    char discard[99];
    static_assert(SHUT_WR == 1, "SHUT_WR == 1");
    if (shutdown(fd, 1) != -1) {
        while (getWallTimeEpoch() < start + timeout) {
            while (haveInput(fd, 0.01)) {
                if (!read(fd, discard, sizeof(discard))) {
                    return true;
                }
            }
        }
    }
    return false;
}

void forceCloseSocket(SOCKET fd) {
    if (!flushSocketBeforeClose(fd, 0.1)) // can block for 2s
        printf("Warning: Cannot gracefully close socket\n");
    closeSocket(fd);
}

ID next_ID() {
    return rand() % RAND_MAX + 1;
}