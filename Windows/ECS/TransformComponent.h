//
// Created by julien on 19/04/2020.
//
#pragma once
#ifndef ATELIERPROG_TRANSFORMCOMPONENT_H
#define ATELIERPROG_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

struct TransformComponent : public Component {

public:

    Vector2D position;
    Vector2D velocity;

    int speed = 3;

    TransformComponent() {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void init() override {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    }

    void update() override {
        position.x += speed*velocity.x;
        position.y += speed*velocity.y;
    }
};

#endif //ATELIERPROG_TRANSFORMCOMPONENT_H
