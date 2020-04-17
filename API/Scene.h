//
// Created by pglandon on 4/17/20.
//

#ifndef ATELIERPROG_SCENE_H
#define ATELIERPROG_SCENE_H

#include <string>
#include "Logger.h"
#include "SceneView.h"
#include "SceneLogic.h"

// Une scène le plus général possible.
// sert de base à l'ensemble de l'API

enum SceneState {
    CREATED,
    INITIALIZED,
    RUNNING,
    STOPPED,
    DESTROYED
};

std::string scene_state_descriptor(SceneState sceneState);

class Scene : protected Logger {
public:
    Scene(SceneView* sceneView, SceneLogic* sceneLogic);
    void set_state(SceneState newSceneState);

protected:
    std::string descriptor() override;

    // Ce qui se rapporte à la vue de la scène.
    SceneView* sceneView;
    // Ce qui se rapporte au modèle de la scène.
    SceneLogic* sceneLogic;
private:
    // L'état dans lequel se trouve la scène.
    SceneState sceneState;
};


#endif //ATELIERPROG_SCENE_H
