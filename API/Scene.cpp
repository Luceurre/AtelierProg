//
// Created by pglandon on 4/14/20.
//


#include "Scene.h"

int Scene::nb_scene = 0;

Scene::Scene(SceneLogic *sl, SceneView *sv) {
    this->sceneLogic = sl;
    this->sceneView = sv;
    this->sceneState = CREATED;

    this->id = Scene::nb_scene;
    Scene::nb_scene++;
}

int Scene::initialize() {
    this->set_state(INITIALIZED);
    return 0;
}

void Scene::set_state(SceneState ss) {
    Logger::info("Scene state changed.");
    this->sceneState = ss;
}

string Scene::to_string() {
    std::stringstream string_adress;
    string_adress << this;
    return "Scene id = " + std::to_string(this->id) + " (" + string_adress.str() + ")";
}