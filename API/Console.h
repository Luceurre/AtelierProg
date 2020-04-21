//
// Created by pglandon on 4/21/20.
//

#ifndef ATELIERPROG_CONSOLE_H
#define ATELIERPROG_CONSOLE_H


#include <vector>
#include <string>
#include <map>

class Console {
    bool isActive;
    void init(std::string consoleName);
static std::map<std::string, Console *> consoles;
};

template<class T>
class ConsoleTemplated : public Console {
public:
    struct Command {
        std::string name;
        void (*callback)(T*);
    };

    std::vector<Command> commands;
};


#endif //ATELIERPROG_CONSOLE_H
