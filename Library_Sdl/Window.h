#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;

struct Window
{
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<SDL_Renderer> _renderer;

	Window();
	virtual ~Window() {}

	virtual void handle_keys(const Uint8 *keys) {}
	virtual void update() {}
	virtual void render() {}
	void main_loop();
};



#endif /* WINDOW_H_ */
