/*
    contains common headers and common definitions
*/
#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <math>

using namespace std;


#define SDL_MAIN_HANDLED //that line must be added before including sdl.h
#include "SDL.h"
#include "SDL_image.h"

// include order is important for defs.h and structs.h
#include "Defs.h"
#include "Strutcs.h"


// The definitions of the screen resolution we want to use. 
// This will also be our window size.
#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720


// to control the speed of the player
#define PLAYER_SPEED 4
// to how fast the player's bullets should move
#define PLAYER_BULLET_SPEED 16

// this macro is used by App struct
#define MAX_KEYBOARD_KEYS 350

#define PLAYER_IMG_PATH "./gfx/player.png"
#define BULLET_IMG_PATH "./gfx/playerBullet.png"



#endif