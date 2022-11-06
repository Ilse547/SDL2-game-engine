#pragma once
#ifndef MAP_H
#define MAP_H
#include "game.h"


class map
{
    public:
        map();
        ~map();

        void LoadMap(int arr[20][25]);
        void DrawMap();

    private:
        SDL_Rect src, dest;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;
        SDL_Texture* air;
        SDL_Texture* clouds;
        SDL_Texture* cloudRU;
        SDL_Texture* cloudRL;
        SDL_Texture* cloudDR;
        SDL_Texture* cloudDL;


        int Map[20][25];
};

#endif // MAP_H
