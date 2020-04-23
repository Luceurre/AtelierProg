//
// Created by pglandon on 4/23/20.
//

#ifndef ATELIERPROG_GAME_H
#define ATELIERPROG_GAME_H

#include <SDL_ttf.h>

#include "Logger.h"

// fait tout ce qui doit être fait avant le lancement du jeu
// i.e. initialisation des libs et de l'API
class Game : public Logger {
    Game();

    std::string descriptor() override;
};


#endif //ATELIERPROG_GAME_H
