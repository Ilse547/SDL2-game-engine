#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool Fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void clean();

    bool Running();
private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;


};


#endif // GAME_H
