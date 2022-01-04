/*
    common game objects and common game structures definitions

	TODO  changes :
	app > essence or realm ????
	entity > esse ???

	TODO 
	the architecture will be spited to four:
		app <struct>
		world <struct>
		esse <struct> (entity)
		esseChain <struct>
*/
#ifndef _ARCHITEC_H
#define _ARCHITEC_H

// The App struct will hold references to our renderer and window
typedef struct {
	string appName; // shooter
	int screenWidth; // SCREEN_WIDTH
	int screenHeight; // SCREEN_HEIGHT
	int rendererFlags; //SDL_RENDERER_ACCELERATED
	int windowFlags; // SDL_WINDOW_SHOWN
	SDL_Renderer *renderer;
	SDL_Window *window;
	// TODO : input methods will be initialized after developing inputHandler
	// up, down, right, left, fire will track our movement requests.
	// int up;
	// int down;
	// int left;
	// int right;
	// int fire;
	// int keyboard[MAX_KEYBOARD_KEYS]; // instead of up, down, left, right and  fire variables
	// 								 // for holding the keyboard state, we now have one array called keyboard
	// 								 // for holding the state of all keys on the keyboard
	// 								 // (or as many as MAX_KEYBOARD_KEYS allows)
	void init();
	void presentScene();
	void prepareScene();
	void kill();
} App;

typedef struct Entity Entity;
// This Entity struct is going to be used to represent the player. 
// it just holds the x and y coordinates, and the texture that it will use.
struct Entity{
	float x;
	float y;
	int w;
	int h;
	float dx; // to handle delta x of the entity for movement
	float dy; // to handle delta y of the entity for movement
	int health; // healt of zero would mean the entity is dead and could be deleted
	int reload; // will be used to track the player's ability to fire
	string imgPath;
	SDL_Texture *texture;
	Entity *next;  // pointer to another entity called.  this is fo use with linked lists
	void init(App *app_){
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
};

//This will be used to hold information about fighters and bullets.
typedef struct{
	Entity *entity;
	Entity head;
	Entity *tail;

	void init(Entity *entity_);
	void insert();
} EntityList;

#endif
