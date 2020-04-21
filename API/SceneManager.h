//
// Created by pglandon on 4/21/20.
//

#ifndef ATELIERPROG_SCENEMANAGER_H
#define ATELIERPROG_SCENEMANAGER_H

#include <vector>

#include "Logger.h"

// Forward Declaration to avoid Circular Definition
class Scene;

class SceneManager : protected Logger {
protected:
    std::string descriptor() override;
private:
    std::vector<Scene*> scenes;
public:
    static SceneManager& getInstance()
    {
        static SceneManager instance;
        return instance;
    }

    SceneManager(SceneManager const&) = delete;
    void operator=(SceneManager const&) = delete;

    SceneManager();
};


#endif //ATELIERPROG_SCENEMANAGER_H
