//
// Created by julien on 18/04/2020.
//
#pragma once
#ifndef ATELIERPROG_MAP_H
#define ATELIERPROG_MAP_H

#include <iostream>

class Map {
public:

    Map();
    ~Map();

    void loadMap(std::string path, int sizeX, int sizeY);

private:
};

#endif //ATELIERPROG_MAP_H
