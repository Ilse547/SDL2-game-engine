#include "game.h"
#include <SDL2/SDL.h>
#include "texturemanager.h"
#include "gameobject.h"
#include "game.h"
#include "map.h"

GameObject* player;
GameObject* enemy;
map* Map;


SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool Fullscreen)
{

    int flags = 0;

    if(Fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL managed to init" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
            std::cout << "renderer created" << std::endl;
        }
        isRunning = true;
    }
    player = new GameObject("res/gfx/Player.png", 0, 0);
    enemy = new GameObject("res/gfx/Enemy.png", 50, 50);
    Map = new map();
}

void Game::HandleEvents()
{
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::Update()
{
    cnt++;
    std::cout << cnt << std::endl;

    player->Update();
    enemy->Update();

}

void Game::Render()
{
    SDL_RenderClear(renderer);

    Map->DrawMap();

    player->Render();
    enemy->Render();

    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

