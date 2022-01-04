#include "temp.h"

void doPlayer(Entity *entity_, App *app_){
	entity_->dx = entity_->dy = 0;

	if (entity_->reload > 0)
	{
		entity_->reload--;
	}

	if (app_->keyboard[SDL_SCANCODE_UP])
	{
		entity_->dy = -PLAYER_SPEED;
	}

	if (app_->keyboard[SDL_SCANCODE_DOWN])
	{
		entity_->dy = PLAYER_SPEED;
	}

	if (app_->keyboard[SDL_SCANCODE_LEFT])
	{
		entity_->dx = -PLAYER_SPEED;
	}

	if (app_->keyboard[SDL_SCANCODE_RIGHT])
	{
		entity_->dx = PLAYER_SPEED;
	}

	if (app_->keyboard[SDL_SCANCODE_LCTRL] && entity_->reload == 0)
	{
		fireBullet();
	}

	entity_->x += entity_->dx;
	entity_->y += entity_->dy;
}


void fireBullet(void){
	Entity *bullet;

	bullet = malloc(sizeof(Entity));
	memset(bullet, 0, sizeof(Entity));
	stage.bulletTail->next = bullet;
	stage.bulletTail = bullet;

	bullet->x = player->x;
	bullet->y = player->y;
	bullet->dx = PLAYER_BULLET_SPEED;
	bullet->health = 1;
	bullet->texture = bulletTexture;
	SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

	bullet->y += (player->h / 2) - (bullet->h / 2);

	player->reload = 8;
}

void doBullets(void){
	Entity *b, *prev;

	prev = &stage.bulletHead;

	for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
	{
		b->x += b->dx;
		b->y += b->dy;

		if (b->x > SCREEN_WIDTH)
		{
			if (b == stage.bulletTail)
			{
				stage.bulletTail = prev;
			}

			prev->next = b->next;
			free(b);
			b = prev;
		}

		prev = b;
	}
}

void logic(void){
	doPlayer();
	doBullets();
}

void draw(void){
	drawPlayer();
	drawBullets();
}

void drawPlayer(void){
	blit(player->texture, player->x, player->y);
}

void drawBullets(void){
	Entity *b;
	for (b = stage.bulletHead.next ; b != NULL ; b = b->next){
		blit(b->texture, b->x, b->y);
	}
}

static void capFrameRate(long *then, float *remainder)
{
	long wait, frameTime;

	wait = 16 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}