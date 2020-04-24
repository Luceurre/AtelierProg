//
// Created by xdiam on 23/04/2020.
//

#ifndef ATELIERPROG_SCENEBUTTON_H
#define ATELIERPROG_SCENEBUTTON_H

#include "../Windows/ECS/ECS.h"
#include "../API/Scene.h"

class SceneButton:public Scene {
    virtual int model();
    virtual int view();
    virtual int controller();
    virtual int initialize()
};


#endif //ATELIERPROG_SCENEBUTTON_H
