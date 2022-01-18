#ifndef _SDLTESTLIB_H
#define _SDLTESTLIB_H

#include<iostream>
// #include<GLFW/glfw3.h>
#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"

using namespace std;

void speak();
void stay();

void sdlTest();

#endif