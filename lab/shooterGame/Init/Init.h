/*
     header file for init.cpp
*/
#ifndef _INIT_H
#define _INIT_H

#include <iostream>

using namespace std;
// #include<Specs/Common.h>

#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

#include "SDL_image.h"

#include<Specs/Strutcs.h>
#include<Specs/Defs.h>


void initSDL(App *app);

void killSDL(App *app_, Entity *entity_);

#endif