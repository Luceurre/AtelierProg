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

    // 32 x 32 parce que nique ta mère ????????
    // Gros tu casses les couilles
    // Autant la position je m'en bat royal les couilles de ce qu'elle vaut par défault
    // autant le truc qui fait que ça s'affiche pas t'abuse un peu....
    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;

    TransformComponent() {
        position.Zero();
    }

    TransformComponent(int sc) {
        position.x = 400;
        position.y = 320;
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
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};

#endif //ATELIERPROG_TRANSFORMCOMPONENT_H
