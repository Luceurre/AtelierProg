//
// Created by julien on 18/04/2020.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void GameObject::Update() {
    xpos++;
    ypos++;

    srcRect.h = 500;
    srcRect.w = 400;
    srcRect.x = 100;
    srcRect.y = 0;

    destRect.h = srcRect.h/2;
    destRect.w = srcRect.w/2;
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}