//
// Created by pglandon on 4/17/20.
//

#include "Tests/SceneConsole.h"
#include "Sandbox/AManager.h"

#include "API/tools.h"

int main(int argc, char* argv[]) {
    SceneConsole console;
    console.initialize();

    console.run();


    return 0;
}