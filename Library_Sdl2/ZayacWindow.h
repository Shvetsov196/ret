/*
 * Zayac.h
 *
 *  Created on: 20 ÓÍÚ. 2021 „.
 *      Author: ¡«Ã 
 */

#ifndef ZAYACWINDOW_H_
#define ZAYACWINDOW_H_

#include "Window.h"
#include "Texture.h"
#include "LayerTexture.h"

class ZayacWindow final: public Window
{
private:
	Texture _zayac;
	Texture _cloud;
	Texture _background;
	LayerTexture _mountains;
	double x,y, phase;
	static constexpr int Zayac_Window_Width=600;
	static constexpr int Zayac_Window_Height =800;
	SDL_FRect clouds[6]{
		{2.0, 20.0, 99.0, 54.0},
		{356.0, 140.0, 192.0, 70.0},
		{500.0, 120.0, 160.0, 90.0},
		{50.0,  80.0,  250.0, 182.0},
		{420.0, 500.0, 400.0, 400.0},
		{220.0, 330.0, 500.0, 300.0},
	};
public:
	ZayacWindow();
	virtual ~ZayacWindow() = default;
	virtual void render_rectangle() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void update() override;
};


#endif /* ZAYACWINDOW_H_ */
