/*
    header file for input.cpp
*/
#ifndef _INPUT_H
#define _INPUT_H





// This function simply reads all the recent inputs (keyboard, mouse, etc) from SDL's queue until there are none left
void doInput(App *app_);

void doKeyDown(SDL_KeyboardEvent *event, App *app_);

void doKeyUp(SDL_KeyboardEvent *event, App *app_);

#endif