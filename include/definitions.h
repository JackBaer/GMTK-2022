//Header Guard
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//Constant Values
#define WINDOW_NAME "GMTK-2022"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define TOTAL_TILE_SPRITES 1
#define TILE_WIDTH 32
#define TILE_HEIGHT 32

//Tiles
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum TileType {
  wood = 0,
  dirt = 1
};

SDL_Rect sliceTile(TileType tileType);

//tileClips[tileTypes.wood].x = 16;
//tileClips[tileTypes.wood].y = 48;
//tileClips[tileTypes.wood].w = 32;
//tileClips[tileTypes.wood].h = 32;

//End header
#endif
