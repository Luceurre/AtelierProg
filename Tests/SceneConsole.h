//
// Created by pglandon on 4/19/20.
//

#ifndef ATELIERPROG_SCENECONSOLE_H
#define ATELIERPROG_SCENECONSOLE_H

#include <cstdlib>

#include "../API/Scene.h"
#include "../API/WindowManager.h"

class SceneConsole : public Scene {
    SDL_Window *consoleWindow;
    SDL_Renderer *consoleRenderer;

    int r, g, b;
    int nb_color, nb_color_vue;
public:
    std::string descriptor() override;
    int initialize() override;
    int view() override ;
    int model() override ;
};


#endif //ATELIERPROG_SCENECONSOLE_H
