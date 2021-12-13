/*
    where the main loop and program entry point exists
*/

// #include <Specs/Common.h>
#include<Specs/Strutcs.h>
#include <Init/Init.h>
#include <Draw/Draw.h>
#include <Input/Input.h>

#define PLAYER_IMG_PATH "./gfx/player.png"
#define BULLET_IMG_PATH "./gfx/playerBullet.png"

int main(int argc, char *argv[])
{
    // define an app object
    App app;
	app.fire = 0;

    // Entity declaration called player (this variable will be in main.h later).
    Entity player;
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

        if (app.up)
		{
			player.y -= 4;
		}

		if (app.down)
		{
			player.y += 4;
		}

		if (app.left)
		{
			player.x -= 4;
		}

		if (app.right)
		{
			player.x += 4;
		}
		if (app.fire && bullet.health == 0)
		{
			bullet.x = player.x;
			bullet.y = player.y;
			bullet.dx = 16;
			bullet.dy = 0;
			bullet.health = 1;
		}

		bullet.x += bullet.dx;
		bullet.y += bullet.dy;

		if (bullet.x > SCREEN_WIDTH)
		{
			bullet.health = 0;
		}

		blit(&player, &app);

		if (bullet.health > 0)
		{
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