#include "game.h"
#include <SDL2/SDL.h>

SDL_Texture* PlayerTex;
SDL_Rect srcR, destR;

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
        if(window)
        {
            std::cout << "window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
            std::cout << "renderer created" << std::endl;
        }
        isRunning = true;
    }

    else{isRunning = false;}

    SDL_Surface* tmpSurface = IMG_Load("res/gfx/Player.png");
    PlayerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
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

    destR.h = 32;
    destR.w = 32;
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    //add stuff to render

    SDL_RenderCopy(renderer, PlayerTex, NULL, &destR);
    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

