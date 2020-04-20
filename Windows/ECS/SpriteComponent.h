//
// Created by julien on 19/04/2020.
//

#ifndef ATELIERPROG_SPRITECOMPONENT_H
#define ATELIERPROG_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"


class SpriteComponent : public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:

    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTex(path);
    }

    void setTex(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override {

        transform = &entity->getComponent<TransformComponent>();

        srcRect.h = 500;
        srcRect.w = 400;
        srcRect.x = 100;
        srcRect.y = 0;

        destRect.h = srcRect.h/2;
        destRect.w = srcRect.w/2;
    }

    void update() override {
        destRect.x = int(transform->position.x);
        destRect.y = int(transform->position.y);
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }

};


#endif //ATELIERPROG_SPRITECOMPONENT_H
