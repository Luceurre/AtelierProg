//
// Created by pglandon on 4/21/20.
//

#include <iostream>
#include "Console.h"

std::map<std::string, Console *> Console::consoles;

void Console::init_console(const std::string& consoleName) {
    this->isActive = true;
    Console::consoles.emplace(consoleName, this);
    this->commands.emplace("HELP", Console::help);
}

void Console::process_command(const std::vector<std::string>& command, std::stringstream& output_stream) {
    if(command.size() < 2) {
        output_stream << "Usage: consoleName commandName arguments" << std::endl;
        return;
    }
    std::string consoleName = command[0];
    std::string commandName = command[1];
    std::vector<std::string> arguments(command.begin() + 2, command.end());

    auto iter = Console::consoles.find(consoleName);
    if(iter != Console::consoles.end()) {
        iter->second->run_command(commandName, arguments, output_stream);
    } else {
        output_stream << "Console not found!" << std::endl;
    }
}

void Console::run_command(std::string commandName, std::vector<std::string> commandArgs,
                                      std::stringstream &output_stream) {
    auto iter = this->commands.find(commandName);
    if(iter != this->commands.end()) {
        // iter->second->run_command(commandName, arguments, output_stream);
        iter->second(this, commandArgs, output_stream);
    } else {
        output_stream << "Command not found!" << std::endl;
    }
}

void Console::get_consoles_name(std::vector<std::string>& consolesName) {
    for(const auto& console : Console::consoles) {
        consolesName.push_back(console.first);
    }
}

void Console::help(Console *c, const std::vector<std::string> &args, std::stringstream &output) {
    for(const auto& command : c->commands) {
        output << command.first << std::endl;
    }
}