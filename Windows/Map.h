//
// Created by julien on 18/04/2020.
//
#pragma once
#ifndef ATELIERPROG_MAP_H
#define ATELIERPROG_MAP_H

#include "Game.h"

class Map {
public:

    Map();
    ~Map();

    void loadMap(int arr[20][25]);
    void drawMap();

private:

    SDL_Rect src, dest;

    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int maps[20][25];
};

#endif //ATELIERPROG_MAP_H
