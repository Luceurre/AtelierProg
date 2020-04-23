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
    static std::map<std::string, Console *> consoles;

protected:
    typedef void (*command)(Console*, const std::vector<std::string>&, std::stringstream&);

    static void get_consoles_name(std::vector<std::string>& consolesName);
    static void process_command(const std::vector<std::string>& command, std::stringstream& output_stream);
    virtual void run_command(std::string commandName, std::vector<std::string> commandArgs, std::stringstream& output_stream);
    // Full majuscule sinon ça fonctionne pas pour le nom (ça devrait être réglé plus tard).
    // Override and call super to register, then register the commands
    virtual void init_console(const std::string& consoleName);

    // Attention! Toutes les commandes doivent être :
    // - static
    // - Prendre en premier argument un pointeur vers Console
    // - Prendre en deuxieme argument un vector<string> (les arguments passé à la fonction)
    // - Prendre en troisième argument un stringstream qui permet de renvoyer des messages (comme cout mais pas cout)
    // Les commandes doivent être thread-safe et fonctionner en dehors du main thread (pas de gestions d'event ou de modification direct de la fenêtre, appel au GPU).

    std::map<std::string, command> commands;

    // Common commands should be written here, like for example help or description
    static void help(Console* c, const std::vector<std::string>& args, std::stringstream& output);
};



#endif //ATELIERPROG_CONSOLE_H
