#include "gamehandler.h"
#include "definitions.h"
#include "objects.h"
#include "tileset.h"
#include <iostream>
#include <vector>

//Game Window
GameWindow* window = new GameWindow();

//Event Handler
SDL_Event e;

//Main Game Loop
void init() {
  //Initialize Window
  window -> init();

  std::vector<Tile> tileset = createTileset();
  //std::vector<Tile> tilemap = setTiles(window -> renderer, tileset);

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
    setTiles(window -> renderer, tileset);
;
    //Render to window
    window -> render();

    //Update Objects
  }
}

