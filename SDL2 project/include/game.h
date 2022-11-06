#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool Fullscreen);

    void HandleEvents();
    void Update();
    bool Running(){return isRunning;}
    void Render();
    void clean();

    static SDL_Renderer *renderer;
private:
    bool isRunning;
    int cnt = 0;
    SDL_Window *window;

};


#endif // GAME_H
