//
// Created by xdiam on 23/04/2020.
//

#include "SceneButton.h"

int SceneButton::model() {
    return 0;
}

int SceneButton::view() {
    return 0;
}

int SceneButton::controller() {
    return 0;
}

int SceneButton::initialize() {
    Manager manager;
    auto& button(manager.addEntity());
    return 0;
}
