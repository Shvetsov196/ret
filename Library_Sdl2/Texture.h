/*
 * Texture.h
 *
 *  Created on: 16 ÓÍÚ. 2021 „.
 *      Author: ¡«Ã 
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <iostream>
#include<memory>
#include<SDL2/SDL.h>
class Texture
{
protected:
	int _width,_height;
	std::shared_ptr<SDL_Renderer> _renderer;
	std::shared_ptr<SDL_Texture> _texture;
	SDL_Renderer *ren(){return _renderer.get();}
	SDL_Texture *tex(){return _texture.get();}


public:
	Texture(std::shared_ptr<SDL_Renderer> &renderer,
			const char *filename) ;
	virtual ~Texture()=default;

	virtual void draw(int x, int y);
	virtual void draw(int x, int y, int w, int h);
	virtual void draw(double x, double y, double angle);
	virtual void draw(const SDL_FRect &r);
	int Height() const {
		return _height;
	}

	int Width() const {
		return _width;
	}
};

#endif /* TEXTURE_H_ */
