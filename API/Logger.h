//
// Created by pglandon on 4/17/20.
//

#ifndef ATELIERPROG_LOGGER_H
#define ATELIERPROG_LOGGER_H

#include <string>
#include <mutex>
#include <iostream>
#include <sstream>

class Logger {
protected:
    enum LogLevel {
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    static LogLevel logLevel;
    static std::mutex mtx;

    // Generate a string that can describe the class. Should be override.
    static std::string descriptor();

    // Generate s string that can describe the object (by default memory address).
    std::string object_descriptor();

    // Generate a string that describe the error level.
    static std::string error_descriptor(LogLevel ll);

    // Modifie le message pour le rendre plus compréhensible, ajoute les infos sur l'objet, la date, etc...
    void parse_log_message(LogLevel ll, std::string& msg);

    // Ajoute au log le message en fonction de la sévérité.
    void log(LogLevel ll, std::string& msg);

    // Des p'tites fonctions pour éviter d'avoir à spécifier le niveau de log du message.
    void info(std::string& msg);
    void warn(std::string& msg);
    void error(std::string& msg);
    void fatal(std::string& msg);
};


#endif //ATELIERPROG_LOGGER_H
