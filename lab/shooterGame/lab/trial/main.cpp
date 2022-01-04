/*
    where the main loop and program entry point exists
*/

// #include <Specs/Common.h>
#include<Specs/Strutcs.h>
#include <Init/Init.h>
#include <Draw/Draw.h>
#include <Input/Input.h>
#include<cstring>

#define PLAYER_IMG_PATH "./gfx/player.png"
#define BULLET_IMG_PATH "./gfx/playerBullet.png"

int main(int argc, char *argv[]){

	App *app;
	Entity *player;
	Entity *bullet;
	Stage *stage;

	app = (App*)malloc(sizeof(App));
	player = (Entity*)malloc(sizeof(Entity));
	bullet = (Entity*)malloc(sizeof(Entity));
	stage = (Stage*)malloc(sizeof(Stage));

	memset(app, 0, sizeof(App));
	memset(player, 0, sizeof(Entity));
	memset(bullet, 0, sizeof(Entity));
	memset(stage, 0, sizeof(Stage));

    // define an app object
    App app;
	app.fire = 0;

    // Entity declaration called player (this variable will be in main.h later).
    Entity player;
    // Entity declaration called bullet (this variable will be in main.h later).
	Entity bullet;
    
    // then call initSDL
    initSDL(&app);

    player.x = 100;
	player.y = 100;
	player.dx = 0;
	player.dy = 0;
	loadTexture(PLAYER_IMG_PATH, &player, &app);

	bullet.health=0;
	bullet.dx =0;
	bullet.dy = 0;
	loadTexture(BULLET_IMG_PATH, &bullet, &app);

	while (1)
	{
        //  For each frame we'll call prepareScene to setup rendering
		prepareScene(&app);

        // collect and process the user input with doInput
		doInput(&app);

		player.x += player.dx;
		player.y += player.dy;

		// Why we are using these app.up etc. variables instead of moving the player in the doKeyDown or doKeyUp?
		//		Those events fire only once when the key is pushed down or up
		//		(or a few more times if we're considering repeat events)
		//		This means that in order to move the player the arrow keys would need to be tapped constantly
		//		to make the ship cross the screen; keyboard repeat events are even worse in this case, as it leads
		//		to jerky movement all over the place. THIS IS NOT WHAT WE WANT.
		//	SETTING THE app.up FAMILY to 1 when a key is pushed down and 0 when the key is released means that the relevant
		//	key need only be held down to keep the player moving and released when we want to player to stop.


        if (app.up) 	// when this is set to 1, player.y will be updated
		{
			player.y -= 4;
		}

		if (app.down) // when this is set to 1, player.y will be updated
		{
			player.y += 4;
		}

		if (app.left) // when this is set to 1, player.x will be updated
		{
			player.x -= 4;
		}

		if (app.right) // when this is set to 1, player.x will be updated
		{
			player.x += 4;
		}
		if (app.fire && bullet.health == 0)
		{
			// to fire the bullet : app.fire must set to 1 and whether the bullet's health is 0.
			// the condition in if statement restricts us from firing the bullet again until its healt is 0
			bullet.x = player.x/2;
			bullet.y = player.y/2;
			bullet.dx = 16;
			bullet.dy = 0;
			bullet.health = 1;
		}

		// we will always be attemoting to move the bullet, whether it is alive or not.
		// we do this by :
		bullet.x += bullet.dx;
		bullet.y += bullet.dy;

		if (bullet.x > SCREEN_WIDTH)
		{	// once the bullet reaches the right-hand side of the screen we set its health to 0.
			bullet.health = 0;
		}

		blit(&player, &app);

		if (bullet.health > 0)
		{
			// we want to draw our bullet using our blint functon
			// we only do this if the health of the bullet is greater than 0.
			blit(&bullet, &app);
		}


        blit(&player, &app);

        // display the scene with presentScene
		presentScene(&app);

        // call SDL_Delay with a value of 16 (milliseconds). 
        // This wait serves to limit our loop to around 62 frames per 
        // second and also prevent the application from running at full 
        // tilt and consuming far too much CPU time.
		SDL_Delay(16);
	}

    killSDL(&app, &player);

	return 0;
}