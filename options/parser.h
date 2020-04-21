//
// Created by Mathis on 21/04/2020.
//

#ifndef ATELIERPROG_PARSER_H
#define ATELIERPROG_PARSER_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>


class parser {
public:
    void parser_write(std::string nom,std::unordered_map<std::string,std::string> dico);
    std::unordered_map<std::string,std::string> parser_read(std::string nom);

};


#endif //ATELIERPROG_PARSER_H
