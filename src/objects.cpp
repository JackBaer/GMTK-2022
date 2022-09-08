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

  window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  return 1;
}

void GameWindow::render() {
  SDL_RenderPresent(renderer);
}

void GameWindow::clear() {
  SDL_RenderClear(renderer);
}
