#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "tileset.h"
#include "definitions.h"
#include "objects.h"
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>

std::vector<Tile> createTileset() {
  std::vector<Tile> tileset;
  for(int i = 0; i < TOTAL_TILE_SPRITES; i++) {
    Tile currentTile(0, 0, TileID(i));
    tileset.push_back(currentTile);
  }
  return tileset;
}

std::vector<Tile> setTiles(SDL_Renderer* renderer, std::vector<Tile> tileset) {
  int x = 0;
  int y = 0;

  std::ifstream map("tilemap.map");

  int type;
  TileID tileType;
 
  std::vector<Tile> tilemap;

  while(!map.eof()) {
    map >> type;

    tileType = TileID(type);

    Tile currentTile(x, y, tileType);

    tilemap.push_back(currentTile);

    currentTile.getTexture(renderer); 
    currentTile.render(renderer, x, y, &baseClips[tileType], 0.0, NULL, SDL_FLIP_NONE); 

    x += TILE_WIDTH;
   
    if(((x / TILE_WIDTH) > MAP_WIDTH - 1) && ((y / TILE_HEIGHT) < MAP_HEIGHT - 1)) {
      x = 0;
      y += TILE_HEIGHT;
    }
  }
  
  map.close();

  return tilemap;
}

