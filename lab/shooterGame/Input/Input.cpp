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
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				doKeyDown(&event.key, app_);
				break;

			case SDL_KEYUP:
				doKeyUp(&event.key, app_);
				break;

			default:
				break;
		}
	}
}



void doKeyDown(SDL_KeyboardEvent *event, App *app_)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			app_->up = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			app_->down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			app_->left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			app_->right = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_Q)
		{
			app_->fire = 1;
		}
	}
}


void doKeyUp(SDL_KeyboardEvent *event, App *app_)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			app_->up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			app_->down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			app_->left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			app_->right = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_Q)
		{
			app_->fire = 0;
		}
	}
}