//
// Created by pglandon on 4/17/20.
//

#include "Logger.h"

Logger::LogLevel Logger::logLevel = Logger::LogLevel::INFO;
std::mutex Logger::mtx;

std::string Logger::descriptor() {
    return "(You didn't changed the descriptor!)";
}

std::string Logger::object_descriptor() {
    std::stringstream ss;
    ss << this;
    return "{" + ss.str() + "}";
}

std::string Logger::error_descriptor(Logger::LogLevel ll) {
    switch (ll) {
        case INFO:
            return "[INFO]";
        case WARNING:
            return "[WARNING]";
        case ERROR:
            return "[ERROR]";
        case FATAL:
            return "[FATAL]";
        default:
            return "";
    }
}

void Logger::parse_log_message(Logger::LogLevel ll, std::string& msg) {
    msg = error_descriptor(ll) + " " + descriptor() + " " + object_descriptor() + " " + msg;
}

void Logger::log(Logger::LogLevel ll, std::string& msg) {
    if(ll >= Logger::logLevel) {
        const std::lock_guard<std::mutex> lock(Logger::mtx);
        this->parse_log_message(ll, msg);
        std::cout << msg << std::endl;
    }
}

void Logger::info(std::string& msg) {
    this->log(Logger::LogLevel::INFO, msg);
}

void Logger::warn(std::string& msg) {
    this->log(Logger::LogLevel::WARNING, msg);
}

void Logger::error(std::string& msg) {
    this->log(Logger::LogLevel::ERROR, msg);
}

void Logger::fatal(std::string& msg) {
    this->log(Logger::LogLevel::FATAL, msg);
}