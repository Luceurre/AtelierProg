//
// Created by pglandon on 4/17/20.
//

#include "Scene.h"

void Scene::set_state(SceneState newSceneState) {
    // TODO : add some logging here
    std::string log_msg = "Scene went from " + scene_state_descriptor(this->sceneState) + " to " + scene_state_descriptor(newSceneState);
    this->log(Logger::LogLevel::INFO, log_msg);

    this->sceneState = newSceneState;
}

Scene::Scene() {
    sceneState = CREATED;
    std::string log_msg = "Scene CREATED";
    this->info(log_msg);
}

std::string Scene::descriptor() {
    return "(Scene)";
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
