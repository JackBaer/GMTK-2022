#include "gamehandler.h"

//Game Window
GameWindow* window = new GameWindow();

Tile* tile1 = new Tile(0, 0, wood);
Tile* tile2 = new Tile(32, 32, dirt);

//Event Handler
SDL_Event e;

//Main Game Loop
void init() {
  //Initialize Window
  window -> init();

  while(!(window -> quitRequested())) { 
    //Handle events (if any) in queue
    while(SDL_PollEvent(&e) != 0) {
      //If player quits, break game loop
      if(e.type == SDL_QUIT) {
        window -> requestQuit();
      }
    } 
    //Clear before drawing
    window -> clear();

    //Draw Commands 
    tile1 -> getTexture(window -> renderer);
    tile1 -> Tile::render(window -> renderer, 0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE);
    
    tile2 -> getTexture(window -> renderer);
    tile2 -> Tile::render(window -> renderer, 0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE);

    //Render to window
    window -> render();

    //Update Objects
  }
}

