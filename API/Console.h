//
// Created by pglandon on 4/21/20.
//

#ifndef ATELIERPROG_CONSOLE_H
#define ATELIERPROG_CONSOLE_H


#include <vector>
#include <string>
#include <map>
#include <sstream>

class Console {
    bool isActive = true;
    void init(const std::string& consoleName);
static std::map<std::string, Console *> consoles;

protected:
    static void process_command(const std::vector<std::string>& command, std::stringstream& output_stream);
    virtual void run_command(std::string commandName, std::vector<std::string> commandArgs, std::stringstream& output_stream) = 0;
};

template<class T>
class ConsoleTemplated : public Console {
protected:
    void run_command(std::string commandName, std::vector<std::string> commandArgs, std::stringstream& output_stream) override ;
public:
    struct Command {
        std::string name;
        void (*callback)(T*);
    };

    std::vector<Command> commands;
};



#endif //ATELIERPROG_CONSOLE_H
