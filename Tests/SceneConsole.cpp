//
// Created by pglandon on 4/19/20.
//

#include "SceneConsole.h"

int SceneConsole::initialize() {
    int codeResult = Scene::initialize();

    this->consoleWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    SDL_Window *win = SDL_CreateWindow("GAME", // creates a window
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);

    this->consoleRenderer = SDL_CreateRenderer(win, -1, 0);

    SDL_RenderClear(this->consoleRenderer);
    SDL_RenderPresent(this->consoleRenderer);


    return 0;
}

std::string SceneConsole::descriptor() {
    return "(Console)";
}
