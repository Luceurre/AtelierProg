//
// Created by pglandon on 4/17/20.
//

#include "Tests/SceneConsole.h"
#include "Sandbox/AManager.h"

#include "API/tools.h"
#include "Tests/SceneMenu.h"

int main(int argc, char* argv[]) {
    // On check si les libs sont bien installés
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        // fatal("Couldn't init SDL");
        exit(-1);
    }
    if(TTF_Init() == -1) {
        // fatal("Couldn't init SDL_ttf");
        exit(-1);
    }

    auto* scene = new SceneConsole();
    scene->initialize();

    scene->run();



    return 0;
}