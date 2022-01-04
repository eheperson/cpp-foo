
#include "Stage.h"


/*
     This file is responsible for handling the actual game logic
*/

void doEntity(App *app_, Entity *entity_){
    entity_->dx = 0;
    entity_->dy = 0;

    if(entity_->reload > 0)
        entity_->reload--;
    if(app_->keyboard[SDL_SCANCODE_UP])
        entity_->dy = -PLAYER_SPEED;
    if(app_->keyboard[SDL_SCANCODE_DOWN])
        entity_->dy = PLAYER_SPEED;
    if(app_->keyboard[SDL_SCANCODE_LEFT])
        entity_->dx = -PLAYER_SPEED;
    if(app_->keyboard[SDL_SCANCODE_RIGHT])
        entity_->dx = -PLAYER_SPEED;
    if(app_->keyboard[SDL_SCANCODE_Q])
        entity_->dy = -PLAYER_SPEED;
}

void doEntityList(EntityList *eList_){
    Entity *b, *prev;

    prev = &(eList_->head);

    for(b = eList_->head.next; b != NULL; b = b->next){
        b->x += b->dx;
        b->y += b->dy;

        if(b->x > SCREEN_WIDTH){
            if(b == eList_->tail)
                eList_->tail = prev;
            
            prev->next = b->next;
            free(b);
            b = prev;
        }
    }
}

void forkEntity(Entity *entity_, EntityList *eList_, App *app_){
    Entity bullet;
    initEntity(&bullet, app_, eList_, BULLET_IMG_PATH);

    eList_->tail->next = &bullet;
    eList_->tail = &bullet;

    bullet.x = entity_->x;
    bullet.y = entity_->y;
    bullet.dx = PLAYER_BULLET_SPEED;
    bullet.health = 1;
    bullet.h += (entity_->h / 2) - (bullet.h / 2);
    entity_->reload = 8;
}

void logic(){

}
// void draw(App *app_, Entity *entity_, Stage *stage_){
//     drawEntity(entity_, app_);
//     drawMultipleEntity(app_, stage_);
// }

