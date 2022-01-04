/*
    header file for draw.cpp
*/
#ifndef _DRAW_H
#define _DRAW_H

#include <iostream>
#include <string>

using namespace std;

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"
#include "SDL_image.h"

#include<Specs/Strutcs.h>

// function to deal with preparing to render
void prepareScene(App *app);

// function to deal with displaying render
void presentScene(App *app);

// This function is fairly simple. 
// It calls the SDL Image function IMG_LoadTexture to load an image and return it as a texture.
void loadTexture(string filename_, Entity *entity_, App *app);

// The blit function simply draws the specified texture on screen at the specified x and y coordinates. 
// The actual drawing code is performed by an SDL function called SDL_RenderCopy
void blit(Entity *entity_, App *app_);

#endif
