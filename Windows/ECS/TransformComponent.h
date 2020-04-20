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

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;

    TransformComponent() {
        position.Zero();
    }

    TransformComponent(int sc) {
        position.Zero();
        scale = sc;
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int w, int h, int sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override {
        velocity.Zero();
    }

    void update() override {
        position.x += speed*velocity.x;
        position.y += speed*velocity.y;
    }
};

#endif //ATELIERPROG_TRANSFORMCOMPONENT_H
