#include "gamehandler.h"

//Game Window
GameWindow* window = new GameWindow();

//Event Handler
SDL_Event e;


//Main Game Loop
void init() {
  //Initialize Window
  window -> init();

  while(!window -> quitFlag) {
   
    //Handle events (if any) in queue
    while(SDL_PollEvent(&e) != 0) {
      //If player quits, break game loop
      if(e.type == SDL_QUIT) {
        window -> quitFlag = true;
      }
    } 
    //Clear before drawing
    window -> clear();

    //Draw Commands
 
    //Render to window
    window -> render();

    //Update Objects
  }
}

