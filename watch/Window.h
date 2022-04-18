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
#include <GL/gl.h>
#include <GL/glu.h>



class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 600;
	static constexpr int DEFAULT_HEIGHT = 800;
protected:
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<void> _gl_context;
	int _width,_height;
public:


	Window(int w = DEFAULT_WIDTH,int h = DEFAULT_HEIGHT);
	virtual ~Window(){}
	virtual void setupGL(){}
	virtual void handle_event(const SDL_Event &event){}
	virtual void handle_keys(const Uint8 *keys){}
	virtual void update(){}
	virtual void render(){}
	void main_loop();

	int getHeight() const {
		return _height;
	}

	int getWidth() const {
		return _width;
	}
};



#endif /* WINDOW_H_ */
