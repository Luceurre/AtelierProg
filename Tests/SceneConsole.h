//
// Created by pglandon on 4/19/20.
//

#ifndef ATELIERPROG_SCENECONSOLE_H
#define ATELIERPROG_SCENECONSOLE_H

#include "../API/Scene.h"

class SceneConsole : public Scene {
    SDL_Window *consoleWindow;
    SDL_Renderer *consoleRenderer;

public:
    std::string descriptor() override;
    int initialize() override;
};


#endif //ATELIERPROG_SCENECONSOLE_H
