/*
     functions concerned with setting up SDL
*/

#include "Init.h"

void initSDL(App *app)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0 ;

    // start by calling SDL_Init
    // passing over SDL_INIT_VIDEO to initialize SDL2's video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Couldn't initialize SDL: " << SDL_GetError() << endl;
		exit(1);
	}

	// his line initializes SDL Image, 
	// to allow us to load PNGs and JPGs, to be used as textures. 
	// IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    // create our window using SDL_CreateWindow
	app->window = SDL_CreateWindow(
        "Shooter 01", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
		SDL_WINDOW_SHOWN
		);

	if (app->window == NULL)
	{
		cout << "Failed to open " << SCREEN_WIDTH <<" x " << SCREEN_HEIGHT << " window: " << SDL_GetError() << endl;
		SDL_Quit();
	}


	// int flags=IMG_INIT_PNG;
	// int initted=IMG_Init(flags);
	// if((initted&flags) != flags) {
	// 	cout << "IMG_Init: Failed to init required jpg and png support!" << endl;
	// 	cout << "IMG_Init: " << IMG_GetError() << endl;
	// 	// handle error
	// }


	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");


    // next create the main renderer by calling SDL_CreateRenderer
	app->renderer = SDL_CreateRenderer(app->window, -1, rendererFlags);

	if (!app->renderer)
	{
		cout << "Failed to create renderer: " << SDL_GetError() << endl;
		exit(1);
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}


void killSDL(App *app_, Entity *entity_){

	SDL_DestroyTexture(entity_->texture);

    IMG_Quit();

	//Destroy the renderer created above
    SDL_DestroyRenderer(app_->renderer);

	//Destroy the window created above
    SDL_DestroyWindow(app_->window);

	//Close all the systems of SDL initialized at the top
    SDL_Quit();

};
