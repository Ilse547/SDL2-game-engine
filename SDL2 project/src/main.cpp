#include <SDL2/SDL.h>
#include "game.h"


Game *game = nullptr;

int main(int argc, const char* argv[])
{
    const int FPS = 30;
    const int FrameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("your mom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, false);

    while (game->Running())
    {

        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;
        if(FrameDelay > frameTime)
        {
            SDL_Delay(FrameDelay-frameTime);
        }
    }

    game->clean();
}
