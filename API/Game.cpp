//
// Created by pglandon on 4/23/20.
//

#include "Game.h"

Game::Game() {

    // On check si les libs sont bien installés
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fatal("Couldn't init SDL");
        exit(-1);
    }
    if(TTF_Init() == -1) {
        fatal("Couldn't init SDL_ttf");
        exit(-1);
    }

    // On initialise le SceneManager et on push une scene
}

std::string Game::descriptor() {
    return "(Game)";
}