/*
    handles input, such as reading the keyboard.
*/

#include "Input.h"

void doInput(App *app_)
{
	SDL_Event event;
	

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT: // SDL_QUIT : SDL event type 
				exit(0);
				break;

			case SDL_KEYDOWN: // SDL_KEYDOWN : SDL event type 
				doKeyDown(&event.key, app_);
				break;

			case SDL_KEYUP: // SDL_KEYDOWN : SDL event type 
				doKeyUp(&event.key, app_);
				break;

			default:
				break;
		}
	}
}


// Old doKeyDown()
// void doKeyDown(SDL_KeyboardEvent *event, App *app_){
// 	// we will testing the scan_Code of the keyboard event to see which key it was
// 	// see : https://wiki.libsdl/prg/SDL_Scancode
// 	if (event->repeat == 0){ // to see whetever or not the keyboard event that was sent was a result of keyboard repeat event
// 		// Note : In the main, we want to ignore keyboard repeat events; these could queue up and cause some unexpected
// 		// 		  things to happen, and so we only want to deal with events where the key has been pushed down or up for the first timr
// 		if (event->keysym.scancode == SDL_SCANCODE_UP)
// 			app_->up = 1;
// 		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
// 			app_->down = 1;
// 		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
// 			app_->left = 1;
// 		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
// 			app_->right = 1;
// 		if (event->keysym.scancode == SDL_SCANCODE_Q)
// 			app_->fire = 1;
// 	}
// }
void doKeyDown(SDL_KeyboardEvent *event, App *app_){
	if(event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
		app_->keyboard[event->keysym.scancode] = 1;
}

// OLD doKeyUp()
// void doKeyUp(SDL_KeyboardEvent *event, App *app_){
// 	if (event->repeat == 0){
// 		if (event->keysym.scancode == SDL_SCANCODE_UP){
// 			app_->up = 0;
// 		}
// 		if (event->keysym.scancode == SDL_SCANCODE_DOWN){
// 			app_->down = 0;
// 		}
// 		if (event->keysym.scancode == SDL_SCANCODE_LEFT){
// 			app_->left = 0;
// 		}
// 		if (event->keysym.scancode == SDL_SCANCODE_RIGHT){
// 			app_->right = 0;
// 		}
// 		if (event->keysym.scancode == SDL_SCANCODE_Q){
// 			app_->fire = 0;
// 		}
// 	  }
// }
void doKeyUp(SDL_KeyboardEvent *event, App *app_){
	if(event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
		app_->keyboard[event->keysym.scancode] = 0;
}