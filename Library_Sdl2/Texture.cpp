/*
 * Texture.cpp
 *
 *  Created on: 16 ÓÍÚ. 2021 „.
 *      Author: ¡«Ã 
 */
#include <SDL2/SDL_image.h>
#include "Texture.h"

Texture::Texture(std::shared_ptr<SDL_Renderer> &renderer,
		const char *filename):_renderer (renderer) {

	_texture =std::shared_ptr<SDL_Texture>(IMG_LoadTexture(ren(),filename),
					SDL_DestroyTexture);
	SDL_QueryTexture(_texture.get(),nullptr,nullptr,&_width,&_height);
}
void Texture::draw(int x,int y)
{
	SDL_Rect target {x,y, Width(),Height()};
	SDL_RenderCopy(ren(), tex(),nullptr, &target);

}
void Texture::draw(int x,int y,int w,int h)
{
	SDL_Rect target {x,y, w,h};
		SDL_RenderCopy(ren(), tex(),nullptr, &target);
}
void Texture::draw(double x, double y, double angle)
{
	SDL_FRect target {float(x),float(y),float(Width()),float(Height())};
	SDL_FPoint center {target.w/2,target.h/2};
	SDL_RenderCopyExF(ren(), tex(),nullptr, &target,angle,&center,SDL_FLIP_NONE);
}
void Texture::draw(const SDL_FRect &r)
{
	SDL_RenderCopyF(ren(), tex(),nullptr, &r);
}

/*Texture::~Texture() {
	// TODO Auto-generated destructor stub
}*/

