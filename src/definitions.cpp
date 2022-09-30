#include "definitions.h"
#include <iostream>
#include "tileset.h"

SDL_Rect baseClips[TOTAL_TILE_SPRITES];

void clipTiles() {
  SDL_Rect woodRect;
  woodRect.x = 16;
  woodRect.y = 48;
  woodRect.w = TILE_WIDTH;
  woodRect.h = TILE_HEIGHT;
  baseClips[TileID::WOOD] = woodRect;

  SDL_Rect dirtRect;
  dirtRect.x = 80;
  dirtRect.y = 48;
  dirtRect.w = TILE_WIDTH;
  dirtRect.h = TILE_HEIGHT;
  baseClips[TileID::DIRT] = dirtRect;
}


