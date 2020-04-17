//
// Created by pglandon on 4/17/20.
//

#include "API/Scene.h"

int main(int argc, char *argv[])
{
    auto* t = new Scene();
    t->set_state(SceneState::INITIALIZED);
    return 0;
}