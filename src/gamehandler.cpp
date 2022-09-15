#include "gamehandler.h"

//Game Window
GameWindow* window = new GameWindow();

Tile* tile = new Tile(0, 0, 0);

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
    tile -> getTexture(window -> renderer);
    tile -> Tile::render(window -> renderer, 0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE);

    //Render to window
    window -> render();

    //Update Objects
  }
}

