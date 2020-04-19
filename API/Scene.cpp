//
// Created by pglandon on 4/17/20.
//

#include "Scene.h"

void Scene::set_state(SceneState newSceneState) {
    const std::lock_guard<std::mutex> lock(this->mtx_state);

    std::string log_msg = "Scene went from " + scene_state_descriptor(this->sceneState) + " to " + scene_state_descriptor(newSceneState);
    this->log(Logger::LogLevel::INFO, log_msg);

    this->sceneState = newSceneState;
}

Scene::Scene() : Scene(nullptr, nullptr) {

}

std::string Scene::descriptor() {
    return "(Scene)";
}

Scene::Scene(SceneView* sceneView, SceneLogic* sceneLogic) {
    this->sceneLogic = sceneLogic;
    this->sceneView = sceneView;
    this->sceneState = CREATED;
    this->model_refresh_rate = DEFAULT_MODEL_REFRESH_RATE;
    this->model_loop_time_ms = 1000 / DEFAULT_MODEL_REFRESH_RATE;
    this->fps = UNCAPPED;
    this->view_loop_time_ms = 0;

    std::string log_msg = "Scene CREATED";
    this->info(log_msg);
    log_msg = "FPS set to UNCAPPED";
    this->info(log_msg);
    log_msg = "Model refresh rate set to " + std::to_string(DEFAULT_MODEL_REFRESH_RATE) +"Hz";
    this->info(log_msg);
}

int Scene::initialize() {
    this->set_state(INITIALIZED);

    return 0;
}

int Scene::run() {
    this->set_state(RUNNING);

    this->thread_model = std::thread(&Scene::run_model, this);
    this->thread_view = std::thread(&Scene::run_view, this);
    this->thread_controller = std::thread(&Scene::run_controller, this);

    this->thread_model.join();
    this->thread_view.join();
    this->thread_controller.join();

    return 0;
}

int Scene::run_controller() {
    return 0;
}

int Scene::run_view() {
    int currentTime = SDL_GetTicks();
    int lastTime = 0;
    std::string msg;

    while (this->get_state() == RUNNING) {
        lastTime = currentTime;

        // Call the things to do...
        this->view();

        currentTime = SDL_GetTicks();
        int elapsed_time = currentTime - lastTime; // Temps passé à faire des trucs en ms
        if (this->fps != UNCAPPED) {
            if (elapsed_time <= this->view_loop_time_ms) {
                msg = "Waiting " + std::to_string(this->model_loop_time_ms - elapsed_time) + "ms";
                this->info(msg);
                SDL_Delay(this->model_loop_time_ms - elapsed_time);
                currentTime = SDL_GetTicks();
            } else {
                msg = "Can't keep up, run_view is " + std::to_string(elapsed_time - this->model_loop_time_ms) +
                      "ms late!";
                this->warn(msg);
            }
        }
    }

    return 0;
}

int Scene::run_model() {
    int currentTime = SDL_GetTicks();
    int lastTime = 0;
    std::string msg;

    while (this->get_state() == RUNNING) {
        lastTime = currentTime;

        // Call the things to do...
        this->model();

        currentTime = SDL_GetTicks();
        int elapsed_time = currentTime - lastTime; // Temps passé à faire des trucs en ms
        if(elapsed_time <= this->model_loop_time_ms) {
            msg = "Waiting " + std::to_string(this->model_loop_time_ms - elapsed_time) + "ms";
            this->info(msg);
            SDL_Delay(this->model_loop_time_ms - elapsed_time);
            currentTime = SDL_GetTicks();
        } else {
            msg = "Can't keep up, run_model is "  + std::to_string(elapsed_time - this->model_loop_time_ms) + "ms late!";
            this->warn(msg);
        }
    }

    return 0;
}

SceneState Scene::get_state() {
    return this->sceneState;
}

int Scene::controller() {
    return 0;
}

int Scene::view() {
    return 0;
}

int Scene::model() {
    if(SDL_GetTicks() > 10000) {
        this->set_state(STOPPED);
    }

    return 0;
}

std::string scene_state_descriptor(SceneState sceneState) {
    switch (sceneState) {
        case CREATED:
            return "CREATED";
        case DESTROYED:
            return "DESTROYED";
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
