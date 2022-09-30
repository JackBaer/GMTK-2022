#include "definitions.h"
#include <iostream>
#include "tileset.h"

/*
#define TILE_IDS \
X(WOOD, "wood") \
X(DIRT, "dirt")

#define X(tile, name) name,
char const *tileIDs[] = {
  TILE_IDS
};
#undef X
#define X(tile, name) tile,
enum TileID : size_t {
  TILE_IDS
};
#undef X
*/

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

/*
TileType::TileType(TileID id, std::vector<TileArgument> arguments) {
  tileID = id;
  tileArguments = arguments;
}
*/
/*
void sliceTiles() {
  //Open tileset file in append mode
  std::ofstream file;
  file.open("Tileset.txt", std::ofstream::out | std::ofstream::trunc);
  file.close();
  file.open("Tileset.txt", std::ios::app);

  char c[]="Sample text";
  //Iterate through every Tile ID
  for(int i = 0; i <= TileID::TileID_MAX; i++) {
    file.write(c, 4);
  }
}
*/
/*
SDL_Rect sliceTile(TileID id, std::vector<TileArgument> arguments) {
  SDL_Rect tileClip;

  bool topFlag = false;
  bool rightFlag = false;
  bool bottomFlag = false;
  bool leftFlag = false;
  bool cornerFlag = false;

  for(int i = 0; i < arguments.size(); i++) {
    switch(arguments[i]) {
      case top:
        topFlag = true;
        break;
      case right:
        rightFlag = true;
        break;
      case bottom:
        bottomFlag = true;
        break;
      case left:
        leftFlag = true;
        break;
      case corner:
        cornerFlag = true;
        break;
    }
  }

  switch(id) {
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

  if(topFlag) {
    tileClip.y -= 4;
    tileClip.h += 4;
  }
  if(rightFlag) {
    tileClip.w += 4;
  }
  if(bottomFlag) {
    tileClip.h += 4;
  }
  if(leftFlag) {
    tileClip.x -= 4;
    tileClip.w += 4;
  }
  //FUNCTIONALITY FOR CORNERS HERE

  return tileClip;
}
*/
