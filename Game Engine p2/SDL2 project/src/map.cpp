#include "map.h"
#include "texturemanager.h"

int lvl1[20][25] = {
    {6,5,0,0,6,4,4,5,0,0,0,0,0,0,0,0,0,6,4,5,0,0,0,0,0},
    {7,8,0,0,7,4,8,0,0,0,0,0,0,0,0,0,0,7,4,8,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,6,4,5,0,0,0,0,0,0,0,6,5,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,4,4,4,0,0,0,0,0,0,0,7,8,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,7,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

map::map()
{
    dirt = TextureManager::Loadtexture("res/gfx/Dirt.png");
    grass = TextureManager::Loadtexture("res/gfx/Grass.png");
    water = TextureManager::Loadtexture("res/gfx/Water.png");
    air = TextureManager::Loadtexture("res/gfx/Air.png");
    clouds = TextureManager::Loadtexture("res/gfx/Clouds.png");
    cloudRU = TextureManager::Loadtexture("res/gfx/CloudUR.png");
    cloudRL = TextureManager::Loadtexture("res/gfx/CloudUL.png");
    cloudDL = TextureManager::Loadtexture("res/gfx/CloudDL.png");
    cloudDR = TextureManager::Loadtexture("res/gfx/CloudDR.png");


    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;
    dest.x = dest.y = 0;
}

void map::LoadMap(int arr[20][25])
{
    for(int row = 0; row < 20; row++)
    {
    for (int column = 0; column < 25; column++)
    {
        Map[row][column] = arr[row][column];

    }
    }
}

void map::DrawMap()
{

    int type = 0;
    for(int row = 0; row < 20; row++)
    {
        for (int column = 0; column < 25; column++)
        {
            type = Map[row][column];
            dest.x = column * 32;
            dest.y = row * 32;

            switch (type)
            {
            case 0:
                TextureManager::Draw(air, src, dest);
                break;
            case 1:
                TextureManager::Draw(grass, src, dest);
                break;
            case 2:
                TextureManager::Draw(dirt, src, dest);
                break;
            case 3:
                TextureManager::Draw(water, src, dest);
                break;
            case 4:
                TextureManager::Draw(clouds, src, dest);
                break;
            case 5:
                TextureManager::Draw(cloudRU, src, dest);
                break;
            case 6:
                TextureManager::Draw(cloudRL, src, dest);
                break;
            case 7:
                TextureManager::Draw(cloudDL, src, dest);
                break;
            case 8:
                TextureManager::Draw(cloudDR, src, dest);
                break;
            default:
                break;
            }

        }
    }
}
