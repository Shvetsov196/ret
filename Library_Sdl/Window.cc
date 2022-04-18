#include "Window.h"
#include <iostream>

Window::Window()
{
	_window = std::shared_ptr<SDL_Window>(
				SDL_CreateWindow("SDL Window",
						SDL_WINDOWPOS_CENTERED_DISPLAY(1),
						SDL_WINDOWPOS_CENTERED_DISPLAY(1),
						WINDOW_WIDTH,
						WINDOW_HEIGHT,
						SDL_WINDOW_SHOWN),
				SDL_DestroyWindow);
		if (_window == nullptr) {
			std::cerr <<
					"Не могу создать окно: " <<
					SDL_GetError() << std::endl;
			exit(1);
		}
	_renderer = std::shared_ptr<SDL_Renderer>(
				SDL_CreateRenderer(
						_window.get(), -1,
						SDL_RENDERER_ACCELERATED |
						SDL_RENDERER_PRESENTVSYNC),
				SDL_DestroyRenderer);
		if (_renderer == nullptr) {
			std::cerr <<
					"Не могу создать рендерер: " <<
					SDL_GetError() << std::endl;
			exit(1);
		}
}
void Window::main_loop()
{
	auto keys = SDL_GetKeyboardState(nullptr);

	SDL_Event event;
		for (;;) {
			// 1) Обработка событий, состояния ввода и т.п.
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT)
					return;
				if (event.type == SDL_KEYDOWN) {
					switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_ESCAPE: return;
					default:
						;
					}
				}
			}
			handle_keys(keys);

			// 2) Изменение состояния программы
			update();

			// 3) Отображение текущего состояния
			render();
			SDL_RenderPresent(_renderer.get());
		}
}
