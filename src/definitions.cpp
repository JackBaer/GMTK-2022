#include "definitions.h"
#include <vector>

//std::vector<SDL_Rect> tileClips;

/*
tileClips[0].x = 16;
tileClips[0].y = 48;
tileClips[0].w = TILE_WIDTH;
tileClips[0].h = TILE_HEIGHT;
*/

//tileClips.push_back(wood);

SDL_Rect sliceTile(TileType tileType) {
  SDL_Rect tileClip;

  switch(tileType) {
    case wood:
      tileClip.x = 16;
      tileClip.y = 48;
      tileClip.w = TILE_WIDTH;
      tileClip.h = TILE_HEIGHT;
      break;
    case dirt:
      tileClip.x = 80;
      tileClip.y = 48;
      tileClip.w = TILE_WIDTH;
      tileClip.h = TILE_HEIGHT;
      break;
  }

  return tileClip;
}
