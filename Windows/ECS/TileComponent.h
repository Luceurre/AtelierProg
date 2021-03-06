 //
// Created by julien on 20/04/2020.
//

#ifndef ATELIERPROG_TILECOMPONENT_H
#define ATELIERPROG_TILECOMPONENT_H

#include "ECS.h"
#include "SDL.h"

class TileComponent : public Component {
public:

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    Vector2D position;
    TileComponent() = default;

    ~TileComponent() {
        SDL_DestroyTexture(texture);
    }

    TileComponent(int srcX, int srcY, int xpos, int ypos, const char* path) {
        texture = TextureManager::LoadTexture(path, srcRect);

        position.x = xpos;
        position.y = ypos;

        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = 32;

        destRect.x = xpos;
        destRect.y = ypos;
        destRect.w = destRect.h = 64;
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
    }

    void update() override {
        destRect.x = position.x - Game::camera.x;
        destRect.y = position.y - Game::camera.y;
    }

};


#endif //ATELIERPROG_TILECOMPONENT_H
