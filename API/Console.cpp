//
// Created by pglandon on 4/21/20.
//

#include <iostream>
#include "Console.h"

std::map<std::string, Console *> Console::consoles;

void Console::init(const std::string& consoleName) {
    this->isActive = true;
    Console::consoles.emplace(consoleName, this);
}

void Console::process_command(const std::vector<std::string>& command, std::stringstream& output_stream) {
    if(command.size() < 2) {
        output_stream << "Usage: consoleName commandName arguments\n";
        return;
    }
    std::string consoleName = command[0];
    std::string commandName = command[1];
    std::vector<std::string> arguments(command.begin() + 2, command.end());

    auto iter = Console::consoles.find(consoleName);
    if(iter != Console::consoles.end()) {
        iter->second->run_command(commandName, arguments, output_stream);
    }
}

template<class T>
void ConsoleTemplated<T>::run_command(std::string commandName, std::vector<std::string> commandArgs,
                                      std::stringstream &output_stream) {

}
