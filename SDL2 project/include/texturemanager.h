#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class TextureManager
{
    public:
    static SDL_Texture* Loadtexture(const char* fileName, SDL_Renderer* ren);

    private:
};

#endif // TEXTUREMANAGER_H
