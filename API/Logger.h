//
// Created by pglandon on 4/14/20.
//

#ifndef ATELIERPROG_LOGGER_H
#define ATELIERPROG_LOGGER_H

#include <string>
#include <iostream>
#include <mutex>

using namespace std;

// Simple Logger, asynchronious for threads compatibility, logs are in console for now.
namespace Logger {
    enum Level {
        FATAL,
        ERROR,
        WARNING,
        INFO
    };

    Level currentLevel = FATAL;
    std::mutex mutex;

    // Returns the prefix message given the level of log
    string pre_message(Level l);
    void info(const string& msg);
    void warn(const string& msg);
    void error(const string& msg);
    void fatal(const string& msg);

    void log(Level l, const string& msg) {
        if(l >= currentLevel) {
            std::lock_guard<std::mutex> lock(mutex); // Print the messages in order
            std::cout << pre_message(l) << msg << std::endl;
        }
    }

    string pre_message(Level l) {
        switch(l) {
            case FATAL:
                return "[FATAL] ";
            case ERROR:
                return "[ERROR] ";
            case WARNING:
                return "[WARNING] ";
            case INFO:
                return "[INFO] ";
            default:
                return "";
        }
    }

    void info(const string& msg) {
        log(INFO, msg);
    }

    void warn(const string& msg) {
        log(WARNING, msg);
    }

    void error(const string& msg) {
        log(ERROR, msg);
    }

    void fatal(const string& msg) {
        log(FATAL, msg);
    }
};

#endif //ATELIERPROG_LOGGER_H
