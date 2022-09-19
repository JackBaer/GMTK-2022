#include "objects.h"


GameWindow::GameWindow(void) {
  window = NULL;
  renderer = NULL;

  quitFlag = NULL;
}

int GameWindow::init() {
  //Initialize desired SDL subsystems
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_AUDIO);
  SDL_Init(SDL_INIT_TIMER);
  SDL_Init(SDL_INIT_EVENTS);

  //Initialize PNG image support
  IMG_Init(IMG_INIT_PNG);

  quitFlag = false;

  window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  return 1;
}

bool GameWindow::quitRequested() {
  return quitFlag;
}

void GameWindow::requestQuit() {
  quitFlag = true;
}

void GameWindow::render() {
  SDL_RenderPresent(renderer);
}

void GameWindow::clear() {
  SDL_RenderClear(renderer);
}

/**************************************************/

Texture::Texture() {
  texture = NULL;

  width = 0;
  height = 0;
}

void Texture::free() {
  if(texture != NULL) {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

Texture::~Texture() {
  free();
}


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


void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) {
  SDL_Rect destinationRect = {x, y, width, height};

  if(clip != NULL) {
    destinationRect.w = clip -> w;
    destinationRect.h = clip -> h;
  }

  SDL_RenderCopyEx(renderer, texture, clip, &destinationRect, angle, center, flip);
}

int Texture::getWidth() {
  return width;
}

int Texture::getHeight() {
  return height;
}
/**************************************************/

Tile::Tile(int x, int y, TileType type) {
  collisionBox.x = x;
  collisionBox.y = y;

  collisionBox.w = TILE_WIDTH;
  collisionBox.h = TILE_HEIGHT;

  tileType = type;
}

void Tile::getTexture(SDL_Renderer* renderer) {
  const int TILE_WOOD = 0;

  SDL_Rect tileClips;
  tileClips.x = 16;
  tileClips.y = 48;
  tileClips.w = TILE_WIDTH;
  tileClips.h = TILE_HEIGHT;

  createTexture("assets/tiles.png", renderer);
}

void Tile::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) {
  SDL_Rect tileClip;
  tileClip = sliceTile(tileType);

  Texture::render(renderer, collisionBox.x, collisionBox.y, &tileClip);
}

int Tile::getType() {
  return tileType;
}

SDL_Rect Tile::getCollider() {
  return collisionBox;
}
