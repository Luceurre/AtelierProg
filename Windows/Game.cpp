//
// Created by julien on 17/04/2020.
//

#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
        std::cout << "Subsystems Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "renderer created" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }
    map = new Map();

    // ecs implementation

    tile0.addComponents<TileComponent>(200, 200, 32, 32, 0);
    tile1.addComponents<TileComponent>(250, 250, 32, 32, 1);
    tile1.addComponents<ColliderComponent>("dirt");
    tile2.addComponents<TileComponent>(150, 150, 32, 32, 2);
    tile2.addComponents<ColliderComponent>("grass");

    player.addComponents<TransformComponent>(0, 0, 32, 32, 1);
    player.addComponents<SpriteComponent>("assets/grass.png");
    player.addComponents<KeyboardController>();
    player.addComponents<ColliderComponent>("player");

    wall.addComponents<TransformComponent>(300.0f, 300.0f, 20, 300, 1);
    wall.addComponents<SpriteComponent>("assets/dirt.png");
    wall.addComponents<ColliderComponent>("wall");
}

void Game::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update() {
    manager.refresh();
    manager.update();

    if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)) {
        player.getComponent<TransformComponent>().velocity * -1;
        std::cout << "Wall hit !" << std::endl;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->drawMap();
    manager.draw();
    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}