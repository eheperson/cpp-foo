/*
    object definitions
*/
#ifndef _STRUTCS_H
#define _STRUTCS_H


#include <iostream>

using namespace std;

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

#include "SDL_image.h"

// The App struct will hold references to our renderer and window
typedef struct {
	int up;
	int down;
	int left;
	int right;
	SDL_Renderer *renderer;
	SDL_Window *window;
	int fire;
} App;

// This Entity struct is going to be used to represent the player. 
// it just holds the x and y coordinates, and the texture that it will use.
typedef struct {
	int x;
	int y;
	int dx;
	int dy;
	int health;
	SDL_Texture *texture;
} Entity;

#endif

