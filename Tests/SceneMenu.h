//
// Created by pglandon on 24/04/2020.
//

#ifndef ATELIERPROG_SCENEMENU_H
#define ATELIERPROG_SCENEMENU_H


#include "../API/Scene.h"
#include "../API/Console.h"
#include "../API/Logger.h"
#include "../API/MouseHandler.h"
#include "../Windows/ECS/ECS.h"

class SceneMenu : public Scene, public Console, public MouseHandler {
int initialize() override;

private:
    Manager manager;
};


#endif //ATELIERPROG_SCENEMENU_H
