/*
     functions concerned with setting up SDL
*/

#include "architec.h"

void App :: init(){
	// create our window using SDL_CreateWindow
	window = SDL_CreateWindow(
		appName.c_str(), 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		screenWidth, 
		screenHeight, 
		windowFlags
	);

	if (window == NULL){
		cout << "Failed to open " << screenWidth <<" x " << screenHeight << " window: " << SDL_GetError() << endl;
		SDL_Quit();
	}

	// next create the main renderer by calling SDL_CreateRenderer
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	if (renderer){
		cout << "Failed to create renderer: " << SDL_GetError() << endl;
		exit(1);
	};
};
	
void  App :: presentScene(){    
	// SDL_RenderPresent takes just one parameter - once again the renderer that we are using.
	SDL_RenderPresent(renderer);
};

void App :: prepareScene(){
	// In prepareScene, we set the colour of SDL renderer using SDL_SetRenderDrawColor. 
	// This function takes five parameters: 
	//     - the pointer to the renderer that we created in init.cpp
	//     - the R channel of the colour that we want to use (from 0 to 255, 0 being darkest and 255 being full)
	//     - the G channel of the colour that we want to use (from 0 to 255, 0 being darkest and 255 being full)
	//     - the B channel of the colour that we want to use (from 0 to 255, 0 being darkest and 255 being full)
	//     - the alpha value (0 is fully transparent whereas 255 is opaque) 
	SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
	SDL_RenderClear(renderer);
};

void App ::  kill(){
	IMG_Quit();

	//Destroy the renderer created above
	SDL_DestroyRenderer(renderer);

	//Destroy the window created above
	SDL_DestroyWindow(window);

	//Close all the systems of SDL initialized at the top
	SDL_Quit();
};

void Entity :: init(App *app_){
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	h = 0;
	w = 0;
	health = 0;
	reload = 0;
	texture = loadTexture(imgPath, entity_, app_);
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
};

void EntityList :: init(Entity *entity_){
	tail = &head;
	
	entity = entity_;
};

void EntityList :: insert(){ //firebullet
	tail->next = entity;
	tail = entity;
};

#endif

/*****************************/
static void doPlayer(void)
{
	player->dx = player->dy = 0;
	
	if (player->reload > 0)
	{
		player->reload--;
	}
	
	if (app.keyboard[SDL_SCANCODE_UP])
	{
		player->dy = -PLAYER_SPEED;
	}
	
	if (app.keyboard[SDL_SCANCODE_DOWN])
	{
		player->dy = PLAYER_SPEED;
	}
	
	if (app.keyboard[SDL_SCANCODE_LEFT])
	{
		player->dx = -PLAYER_SPEED;
	}
	
	if (app.keyboard[SDL_SCANCODE_RIGHT])
	{
		player->dx = PLAYER_SPEED;
	}
	
	if (app.keyboard[SDL_SCANCODE_LCTRL] && player->reload == 0)
	{
		fireBullet();
	}
	
	player->x += player->dx;
	player->y += player->dy;
}