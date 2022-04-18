/*
 * LayerTexture.h
 *
 *  Created on: 23 окт. 2021 г.
 *      Author: БЗМК
 */

#ifndef LAYERTEXTURE_H_
#define LAYERTEXTURE_H_

#include "Texture.h"

class LayerTexture: public Texture {
protected:
	double _speed  {};  //в пикселях/тик
	double _offset {};  // в пикселях
public:
	LayerTexture(std::shared_ptr<SDL_Renderer> &renderer,
			const char *filename,double spd);
    virtual ~LayerTexture()=default;


	//virtual void draw(int x, int y);
	virtual void draw(int x, int y, int w, int h)override;
	//virtual void draw(double x, double y, double angle);
	//virtual void draw(const SDL_FRect &r);

	virtual void update();

};

#endif /* LAYERTEXTURE_H_ */
