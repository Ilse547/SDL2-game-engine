#include <SDL2/SDL.h>
#include "game.h"

Game *game = nullptr;

int main(int argc, const char* argv[])
{
    game = new Game();

    game->init("your mom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

    if (game->Running())
    {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    game->clean();
}
