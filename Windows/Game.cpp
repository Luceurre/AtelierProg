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

    Map::loadMap("assets/map_16x16.map", 16, 16);

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

    for (auto cc: colliders) {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    //map->drawMap();
    manager.draw();
    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::addTile(int id, int x, int y) {
    auto& tile(manager.addEntity());
    tile.addComponents<TileComponent>(x, y, 32, 32, id);
}