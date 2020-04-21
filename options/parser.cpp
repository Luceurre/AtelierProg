//
// Created by Mathis on 21/04/2020.
//

#include "parser.h"

void parser::parser_write(std::string nom, std::unordered_map<std::string, std::string> dico) {
    std::ofstream myfile;
    myfile.open(nom);
    if (myfile.is_open()){
        for (auto& x: dico) {
            myfile << x.first << ";" << x.second << std::endl;
        }
        myfile.close();
    }
    else {
        std::cout<<"Problem when creating or opening file "<<nom<<std::endl;
    }
}

std::unordered_map<std::string, std::string> parser::parser_read(std::string nom) {

    std::string line;
    std::unordered_map<std::string, std::string> dico;
    std::ifstream myfile(nom);
    if (myfile.is_open()){
        while (std::getline(myfile, line)) {
            int i = 0;
            std::string key;
            while(line[i]!=';'){
                key += line[i];
                i++;
                if (i == line.size()){
                    std::cout << "Warning, " <<nom<< " file corrupted" <<std::endl;
                    break;
                }
            }
            if (i!=line.size()){
                std::string value;
                for (int j=i+1;j<line.size();j++){
                    value += line[j];
                }
                dico.emplace(key,value);
            }
        }
    }
    else {
        std::cout<<"Error while loading "<<nom<<std::endl;
    }

    return dico;
}
