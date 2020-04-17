//
// Created by pglandon on 4/17/20.
//

#include "Scene.h"

void Scene::set_state(SceneState newSceneState) {
    // TODO : add some logging here
    std::string log_msg = "Changement d'état de la scène.";
    this->log(Logger::LogLevel::INFO, log_msg);

    this->sceneState = newSceneState;
}

Scene::Scene() {
    std::string msg = "Hello World!";
    sceneState = CREATED;
    this->info(msg);
}

std::string scene_state_descriptor(SceneState sceneState) {
    switch (sceneState) {
        case CREATED:
            return "CREATED";
        case DESTROYED:
            return "DESTROYED";
        case INITIALIZED:
            return "INITIALIZED";
        case RUNNING:
            return "RUNNING";
        case STOPPED:
            return "STOPPED";
        default:
            return "";
    }
}
