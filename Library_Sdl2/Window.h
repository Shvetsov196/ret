/*
 * Window.hh
 *
 *  Created on: 16 ÓÍÚ. 2021 „.
 *      Author: ¡«Ã 
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <iostream>


class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 600;
	static constexpr int DEFAULT_HEIGHT = 800;
protected:
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<SDL_Renderer> _renderer;
	int _width,_height;
public:


	Window(int w = DEFAULT_WIDTH,int h = DEFAULT_HEIGHT);
	virtual ~Window(){}
	virtual void handle_keys(const Uint8 *keys){}
	virtual void update(){}
	virtual void render_rectangle(){}
	void main_loop();

	int getHeight() const {
		return _height;
	}

	int getWidth() const {
		return _width;
	}
};



#endif /* WINDOW_H_ */
