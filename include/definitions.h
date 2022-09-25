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

#define TILE_IDS \
  X(WOOD, "wood") \
  X(DIRT, "dirt") 

#define X(tile, name) tile,
enum TileID : size_t {
  TILE_IDS
};
#undef X

#define X(tile, name) name,
char const *tileIDs[] = {
  TILE_IDS
};
#undef X

//Tiles
/*
enum TileID {
  wood,
  dirt,
  TileID_MAX = dirt
};
*/
enum TileArgument {
  top,
  right,
  bottom,
  left,
  corner
};

class TileType {
  public:
    TileType(TileID id, std::vector<TileArgument> arguments);
    
    TileID tileID;
    std::vector<TileArgument> tileArguments;
};

extern SDL_Rect baseClips[TOTAL_TILE_SPRITES];

void clipTiles();
//SDL_Rect sliceTile(TileID id, std::vector<TileArgument> arguments);

//void sliceTiles();
//End header
#endif
