/*
 * Zayac.cpp
 *
 *  Created on: 20 ÓÍÚ. 2021 „.
 *      Author: ¡«Ã 
 */
#include "ZayacWindow.h"
#include "LayerTexture.h"
#include <cmath>

ZayacWindow::ZayacWindow()
: Window(Zayac_Window_Width,Zayac_Window_Height),
  _zayac(_renderer,"image_zayac.png"),
  _cloud(_renderer,"image_cloud.png"),
  _background(_renderer,"image_background.png"),
  _mountains(_renderer,"gori.png",2.0)
{
	x=50.0;
	y=0.0;
	/*
	 y=50;
	 w=_zayac.Width();
	 h=_zayac.Height();
	*/
	phase=0.0;

}

void  ZayacWindow::render_rectangle()
{
SDL_SetRenderDrawColor(_renderer.get(),124,152,255,255);
_background.draw(0,0);
_mountains.draw(0,274,getWidth(),_mountains.Height());
//SDL_RenderClear(_renderer.get());
unsigned i=0;
for (;i<3;++i)
	_cloud.draw(clouds[i]);


_zayac.draw(x,y,(sin(phase)+cos(phase))/3*180/3.141589);
}



void ZayacWindow::handle_keys(const Uint8 *keys)
{
	if(keys[SDL_SCANCODE_RIGHT])x+=4;
	if(keys[SDL_SCANCODE_LEFT])x-=4;
	/*if(keys[SDL_SCANCODE_UP])y-=4;
	if(keys[SDL_SCANCODE_DOWN])y+=4;

	if(keys[SDL_SCANCODE_A])w-=4;
	if(keys[SDL_SCANCODE_D])w+=4;
	if(keys[SDL_SCANCODE_W])h-=4;
	if(keys[SDL_SCANCODE_S])h+=4;*/
}
void ZayacWindow::update()
{
	auto pi= acos(-1.0);
	phase+=pi/90.0;
	x+=6;
	if (x>=getWidth()+250)
		x=-getWidth()+300;
	y= _zayac.Height()*4*(1+0.5*sin(phase));
	for(unsigned i=0;i<6;++i){
		clouds[i].x-=clouds[i].w/32;
		if (clouds[i].x<=-clouds[i].w)
			clouds[i].x=getWidth()+200;
	}
	_mountains.update();

}
