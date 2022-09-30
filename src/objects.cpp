#include "objects.h"
#include <iostream>
#include <string>
#include "definitions.h"
#include "tileset.h"

//Constructor
GameWindow::GameWindow(void) {
  window = NULL;
  renderer = NULL;

  quitFlag = NULL;
}

//Initialize main game window
int GameWindow::init() {
  //Initialize desired SDL subsystems
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_AUDIO);
  SDL_Init(SDL_INIT_TIMER);
  SDL_Init(SDL_INIT_EVENTS);

  //Initialize PNG image support
  IMG_Init(IMG_INIT_PNG);

  quitFlag = false;

  Tile::sliceTiles();

  window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  return 1;
}

//Check if window needs to be closed
bool GameWindow::quitRequested() {
  return quitFlag;
}

//Request window close
void GameWindow::requestQuit() {
  quitFlag = true;
}

//Render to window
void GameWindow::render() {
  SDL_RenderPresent(renderer);
}

//Clear window contents
void GameWindow::clear() {
  SDL_RenderClear(renderer);
}

/**************************************************/

//Constructor
Texture::Texture() {
  texture = NULL;

  width = 0;
  height = 0;
}

//Free texture
void Texture::free() {
  if(texture != NULL) {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

//Destructor
Texture::~Texture() {
  free();
}

//Create SDL_Texture from file at provided file path
void Texture::createTexture(std::string path, SDL_Renderer* renderer) {
  free();

  SDL_Texture* newTexture = NULL;

  SDL_Surface* loadedSurface = IMG_Load(path.c_str());

  SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface -> format, 0, 0xFF, 0xFF));

  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  width = loadedSurface -> w;
  height = loadedSurface -> h;

  texture = newTexture;
}


//Render texture to provided renderer with any provided modifiers
void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) {
  SDL_Rect destinationRect = {x, y, width, height};

  if(clip != NULL) {
    destinationRect.w = clip -> w;
    destinationRect.h = clip -> h;
  }

  SDL_RenderCopyEx(renderer, texture, clip, &destinationRect, angle, center, flip);
}

//Access width member
int Texture::getWidth() {
  return width;
}

//Access height member
int Texture::getHeight() {
  return height;
}
/**************************************************/



//Construct Tile object and create collisionBox
Tile::Tile(int x, int y, TileID type) {
  collisionBox.x = x;
  collisionBox.y = y;

  collisionBox.w = TILE_WIDTH;
  collisionBox.h = TILE_HEIGHT;

  tileType = type;
}

//Load the tileset into the provided renderer
void Tile::getTexture(SDL_Renderer* renderer) {
  createTexture("assets/tiles.png", renderer);
}

//Get Tile texture from tileset (based on provided tileType) and render to provided renderer
void Tile::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) {
  SDL_Rect tileClip;
  tileClip = baseClips[tileType];
  //tileClip = sliceTile(tileType, {right, top, left, bottom});
  Texture::render(renderer, collisionBox.x, collisionBox.y, &tileClip);
}

//Access tileType member
TileID Tile::getType() {
  return tileType;
}

//Access collisionBox member
SDL_Rect Tile::getCollider() {
  return collisionBox;
}

//Static method to write Tile variant data to Tileset.txt
void Tile::sliceTiles() {
  clipTiles();
  std::ofstream file;
  //Open file and clear its contents, then close file
  file.open("Tileset.txt", std::ofstream::out | std::ofstream::trunc);
  file.close();
  //Open file in append mode to allow writing of Tile data
  file.open("Tileset.txt", std::ios::app);
  //Iterate through every Tile ID, and create variants of each type of tile
  for(int i = 0 ; i < TOTAL_TILE_SPRITES; i++) {
   
    //Take SDL_Rect clip of current TileID
    SDL_Rect currentClip = baseClips[i];
    
    //Convert each property of clip to std::string
    std::string x = std::to_string(currentClip.x);
    std::string y = std::to_string(currentClip.y);
    std::string w = std::to_string(currentClip.w);
    std::string h = std::to_string(currentClip.h);

    std::string tileName = tileIDs[i];
    //Write each clip property to file, converting the std::string properties to C strings
    file.write(tileName.c_str(), tileName.length());
    file << " ";
    file.write(x.c_str(), x.length());
    file << " ";
    file.write(y.c_str(), y.length());
    file << " ";
    file.write(w.c_str(), w.length());
    file << " ";
    file.write(h.c_str(), h.length());
    file << std::endl;
  }
}
