/*
    functions related to drawing and rendering
*/


#include "Draw.h"


SDL_Texture *loadTexture(string textureFile_, Entity *entity_, App *app_)
{
    // SDL_Texture* texture;
    // SDL_Surface* surface;
    // surface = IMG_Load(filename_.c_str()); 
    // texture = SDL_CreateTextureFromSurface(app_->renderer, surface); 
    // entity_->texture = texture;
    // SDL_FreeSurface(surface);

    SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", textureFile_.c_str());

	texture = IMG_LoadTexture(app_->renderer, textureFile_.c_str());
    return texture;
}

void blit(Entity *entity_, App *app_)
{
    SDL_Rect dest; //destination

	dest.x = entity_->x;
	dest.y = entity_->y;
    dest.w = entity_->w;
    dest.h = entity_->h;
	SDL_QueryTexture(entity_->texture, NULL, NULL, &dest.w, &dest.h);

    //   SDL_RenderCopy that takes four parameters :
    //     - The first is our trusty renderer and 
    //     - the second is the texture we want to draw. 
    //     - The next two parameters are the rectangular regions of the src texture and the target renderer. 

    // We pass NULL as the src rectangle to tell SDL to copy the entire texture. 
    // The dest rectangle is the x and y coordinates where we want to draw our texture, 
    // with its width and height being the width and height of the source texture.

    // The reason for allowing us to specify the source and dest rectangles is because 
    // we might have a large texture (such as a sprite atlas) that we only want to copy a portion of. 
    // The dest width and height would allow us to resize the source texture at the destination if 
    // we wanted to. For now, we'll keep things 1:1.
	SDL_RenderCopy(app_->renderer, entity_->texture, NULL, &dest);
}


    
void drawEntity(Entity *entity_, App *app_){
    blit(entity_, app_);
}

void drawMultipleEntity(App *app_, Stage *stage_){
    Entity *b;
    for(b = stage_->head.next; b != NULL; b = b->next)
        blit(b, app_);
}