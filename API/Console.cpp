//
// Created by pglandon on 4/21/20.
//

#include "Console.h"

std::vector<Console *> Console::consoles;

void Console::init() {
    this->isActive = true;
    Console::consoles.push_back(this);
}
