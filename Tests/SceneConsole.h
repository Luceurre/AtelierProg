//
// Created by pglandon on 4/19/20.
//

#ifndef ATELIERPROG_SCENECONSOLE_H
#define ATELIERPROG_SCENECONSOLE_H

#include <cstdlib>

#include "../API/Scene.h"
#include "../API/WindowManager.h"
#include "../API/Console.h"

class SceneConsole : public Scene, public ConsoleTemplated<SceneConsole> {
    SDL_Window *consoleWindow;
    SDL_Renderer *consoleRenderer;

    int r, g, b;
    int nb_color, nb_color_vue;
public:
    std::string descriptor() override;
    int initialize() override;
    int view() override ;
    int model() override ;

    static void help(SceneConsole*);
};


#endif //ATELIERPROG_SCENECONSOLE_H
