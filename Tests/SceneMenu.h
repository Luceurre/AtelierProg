//
// Created by pglandon on 24/04/2020.
//

#ifndef ATELIERPROG_SCENEMENU_H
#define ATELIERPROG_SCENEMENU_H


#include <SDL_ttf.h>
#include "../API/Scene.h"
#include "../API/Console.h"
#include "../API/Logger.h"
#include "../API/MouseHandler.h"
#include "../Windows/ECS/ECS.h"
#include "../Windows/TextureManager.h"
#include "../Windows/ECS/Components.h"
#include "../API/WindowManager.h"


class SceneMenu : public Scene, public Console, public MouseHandler {
public:
int initialize() override;
int view() override;
int model() override;
int controller() override;
private:
    Manager manager;
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;
};


#endif //ATELIERPROG_SCENEMENU_H
