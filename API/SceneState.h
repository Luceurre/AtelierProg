//
// Created by pglandon on 4/14/20.
//

#ifndef ATELIERPROG_SCENESTATE_H
#define ATELIERPROG_SCENESTATE_H

#include <string>

using namespace std;


enum SceneState {
    CREATED,
    INITIALIZED,
    RUNNING,
    STOPPED,
    PAUSED
};

string scene_state_to_string(SceneState ss);

string scene_state_to_string(SceneState ss) {
    switch (ss) {
        case CREATED:
            return "CREATED";
        case INITIALIZED:
            return "INITIALIZED";
        case RUNNING:
            return "RUNNING";
        case STOPPED:
            return "STOPPED";
        case PAUSED:
            return "PAUSED";
        default:
            return "";
    }
}

#endif //ATELIERPROG_SCENESTATE_H
