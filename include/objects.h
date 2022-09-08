//Header Guard
#ifndef OBJECTS_H
#define OBJECTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "definitions.h"

class GameWindow {
  public:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    GameWindow();
    int init();
    void render();
    void clear();

  private:
    //Member data of window dimensions for resizing
    int windowHeight;
    int windowWidth;

    //Flags for window focus/state
    bool hasKeyboardFocus;
    bool hasMouseFocus;
    bool isFullScreen;
    bool isMinimized;
    bool quitFlag;
};

//End header
#endif
