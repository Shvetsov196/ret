/*
 * Window.cpp
 *
 *  Created on: 20 окт. 2021 г.
 *      Author: БЗМК
 */
#include "Window.h"
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>


Window::Window(int w, int h):
		_width(w),_height(h)
{
	_window = std::shared_ptr<SDL_Window>(
	SDL_CreateWindow("SDL Windows", SDL_WINDOWPOS_CENTERED_DISPLAY(1),
					SDL_WINDOWPOS_CENTERED_DISPLAY(1), h, w,
					SDL_WINDOW_SHOWN), SDL_DestroyWindow);
	if (_window == nullptr) {
		std::cerr << "error" << SDL_GetError() << std::endl;
		exit(1);
		}
	_renderer = std::shared_ptr<SDL_Renderer>(
	SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC),
				SDL_DestroyRenderer);
		if (_renderer == nullptr) {
			std::cerr << "error" << SDL_GetError() << std::endl;
			exit(1);
		}



}



void Window::main_loop() {

	auto keys = SDL_GetKeyboardState(nullptr);
	SDL_Event event;
	for (;;) {
		//обработка событий
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				exit(0);
			if (event.type==SDL_KEYDOWN){
				switch(event.key.keysym.scancode){
				case SDL_SCANCODE_ESCAPE:return;
				default:
					;
				}
			}
		}
		handle_keys(keys);
		//изменения состояния событий
		update();



		//отображение текущего состояния
		render_rectangle();
		SDL_RenderPresent(_renderer.get());

	}
}
