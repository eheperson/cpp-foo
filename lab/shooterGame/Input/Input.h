/*
    header file for input.cpp
*/
#ifndef _INPUT_H
#define _INPUT_H

#include <iostream>

using namespace std;

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

#include "SDL_image.h"

#include<Specs/Strutcs.h>

// This function simply reads all the recent inputs (keyboard, mouse, etc) from SDL's queue until there are none left
void doInput(App *app_);


void doKeyDown(SDL_KeyboardEvent *event, App *app_);

void doKeyUp(SDL_KeyboardEvent *event, App *app_);

#endif