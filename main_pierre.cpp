//
// Created by pglandon on 4/17/20.
//

#include "Tests/SceneConsole.h"
#include "Sandbox/AManager.h"

#include "API/tools.h"

int main(int argc, char* argv[]) {
    std::string msg = "Bonjour je m'appelle Pierre";
    std::vector<std::string> res = split(msg, ' ');
    for(const auto& r : res) {
        std::cout << r << std::endl;
    }

    SceneConsole console;
    console.initialize();

    console.run();


    return 0;
}