//
// Created by pglandon on 4/21/20.
//

#include "Console.h"

std::map<std::string, Console *> Console::consoles;

void Console::init(std::string consoleName) {
    this->isActive = true;
    Console::consoles.emplace(consoleName, this);
}
