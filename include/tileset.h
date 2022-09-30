//Header Guard
#ifndef TILESET_H
#define TILESET_H

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


//End header
#endif
