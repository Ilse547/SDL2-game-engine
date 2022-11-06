#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class TextureManager
{
    public:
    static SDL_Texture* Loadtexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);


    private:
};

#endif // TEXTUREMANAGER_H
