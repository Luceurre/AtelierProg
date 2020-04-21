//
// Created by mathis on 20/04/2020.
//

#include <SDL.h>
#include "options/options.h"

int main(int argc, char* argv[]) {

    options opt("options/Options.txt");

    opt.set_option("sound","0");
    opt.read("options/Options.txt");
    opt.write("options/Options.txt");

    return 0;
}
