//
// Created by pglandon on 4/17/20.
//

#ifndef ATELIERPROG_LOGGER_H
#define ATELIERPROG_LOGGER_H

#include <string>
#include <iostream>
#include <mutex>

using namespace std;

namespace Logger {
    enum LogLevel {
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    // Pour permettre que les messages s'envoient dans le bon ordre.
    mutex mtx;
    LogLevel currentLevel = LogLevel::INFO;

    // Rajoute le type de message, les timesstamps, etc...
    string& parse_log_message(LogLevel ll, string& msg);

    // Ajoute au log le message en fonction de la sévérité.
    void log(LogLevel ll, string& msg);

    // Des p'tites fonctions pour éviter d'avoir à spécifier le niveau de log du message.
    void info(string& msg);
    void warn(string& msg);
    void error(string& msg);
    void fatal(string& msg);

    const char* parse_log_message(Logger::LogLevel ll, const char* msg) {
        switch (ll) {
            case INFO:
                cout << "[INFO] " ;
                break;

            case WARNING:
                cout << "[WARNING] ";
                break;

            case ERROR:
                cout << "[ERROR] ";
                break;
            case FATAL:
                cout << "[FATAL]";
                break;
            default:
                cout << "";
        }
        return msg;
    }

    void log(Logger::LogLevel ll, const char* msg) {
        if(ll >= Logger::currentLevel) {
            const lock_guard<mutex> lock(mtx);
            cout << parse_log_message(ll, msg) << endl;
        }
    }

    void info(const char* msg) {
        Logger::log(Logger::LogLevel::INFO, msg);
    }

    void warn(const char* msg) {
        Logger::log(Logger::LogLevel::WARNING, msg);
    }

    void error(const char* msg) {
        Logger::log(Logger::LogLevel::ERROR, msg);
    }

    void fatal(const char* msg) {
        Logger::log(Logger::LogLevel::FATAL, msg);
    }
}

#endif //ATELIERPROG_LOGGER_H
