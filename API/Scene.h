//
// Created by pglandon on 4/14/20.
//

#ifndef ATELIERPROG_SCENE_H
#define ATELIERPROG_SCENE_H

#include <sstream>

#include "SceneLogic.h"
#include "SceneView.h"
#include "SceneState.h"
#include "Logger.h"

class Scene {
public:
    Scene(SceneLogic *sl, SceneView *sv);

    // Load sprites, data, whatever is needed in the scene.
    // returns 0 if the initialization is successful.
    int initialize();
    void set_state(SceneState ss);
    string to_string();
private:
    int id;
    string name;

    SceneLogic *sceneLogic;
    SceneView *sceneView;
    SceneState sceneState;

    static int nb_scene;
};

#endif //ATELIERPROG_SCENE_H
