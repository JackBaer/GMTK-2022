//Header Guard
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include <fstream>


//Constant Values
#define WINDOW_NAME "GMTK-2022"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define TOTAL_TILE_SPRITES 2
#define TILE_WIDTH 32
#define TILE_HEIGHT 32

//Tiles
extern SDL_Rect baseClips[TOTAL_TILE_SPRITES];

void clipTiles();

//End header
#endif
