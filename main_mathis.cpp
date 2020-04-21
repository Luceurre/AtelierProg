//
// Created by pglan on 20/04/2020.
//

#include <SDL.h>
#include "options/parser.h"

int main(int argc, char* argv[]) {

    parser options;
    std::unordered_map<std::string,std::string> dico = options.parser_read("options/Options.txt");

    dico.emplace("salut","je fonctionne");
    options.parser_write("options/Options.txt",dico);

    return 0;
}
