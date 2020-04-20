//
// Created by julien on 20/04/2020.
//

#ifndef ATELIERPROG_TILECOMPONENT_H
#define ATELIERPROG_TILECOMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"

class TileComponent : public Component {
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_Rect tileRect;
    int tileID;
    char* path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id) {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        switch (tileID) {
            case 0:
                path = "assets/water.png";
                break;
            case 1:
                path = "assets/dirt.png";
                break;
            case 2:
                path = "assets/grass.png";
                break;
            default:
                break;
        }
    }

    void init() override {
        entity->addComponents<TransformComponent>(float(tileRect.x), float(tileRect.y), tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponents<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};


#endif //ATELIERPROG_TILECOMPONENT_H
