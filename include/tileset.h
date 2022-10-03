//Header Guard
#ifndef TILESET_H
#define TILESET_H

#include <vector>

#define TILE_IDS \
X(WOOD, "wood") \
X(DIRT, "dirt")

#define X(tile, name) name,
inline char const *tileIDs[] = {
  TILE_IDS
};
#undef X
#define X(tile, name) tile,
enum TileID : size_t {
  TILE_IDS
};
#undef X

class Tile;

//Creates a vector of Tile objects to be referenced to when building tilemap
std::vector<Tile> createTileset();

//Reads tilemap data and, using provided tileset, renders them in window at the correct positions
std::vector<Tile> setTiles(SDL_Renderer* renderer, std::vector<Tile> tileset);

//End header
#endif
