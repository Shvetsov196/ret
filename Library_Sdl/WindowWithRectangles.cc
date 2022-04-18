#include "WindowWithRectangles.h"

WindowWithRectangles::WindowWithRectangles()
: Window()
{

}

void WindowWithRectangles::handle_keys(const Uint8 *keys)
{
	if (rect2.x <= WINDOW_WIDTH - 315 and keys[SDL_SCANCODE_RIGHT]) rect2.x += 2;
	if (rect2.x >= 100 and keys[SDL_SCANCODE_LEFT])  rect2.x -= 2;
	if (rect2.y <= WINDOW_HEIGHT - 115 and keys[SDL_SCANCODE_DOWN])  rect2.y += 2;
	if (rect2.y >= 100 and keys[SDL_SCANCODE_UP])    rect2.y -= 2;
}

void WindowWithRectangles::render()
{
	SDL_SetRenderDrawColor(_renderer.get(),
			31, 63, 95, 255);
	SDL_RenderClear(_renderer.get());

	SDL_SetRenderDrawColor(_renderer.get(),
			255, 255, 255, 255);
	for (int i = 0; i <= 50; ++i) {
		SDL_SetRenderDrawColor(_renderer.get(),
					255 - 5 * i, 5 * i, 255, 255);
		SDL_RenderDrawLine(_renderer.get(),
				100 + i * 8, 100, 100, 500 - i * 8);
		SDL_RenderDrawLine(_renderer.get(),
				500 - i * 8, 500, 500, 100 + i * 8);
	}
	SDL_SetRenderDrawColor(_renderer.get(),
			255, 63, 63, 255); //RGB, прозрачность
	SDL_RenderFillRect(_renderer.get(), &rect1);

	SDL_SetRenderDrawColor(_renderer.get(),
			63, 255, 63, 255);
	SDL_Rect r;
	if (SDL_IntersectRect(&rect1, &rect2, &r))
		SDL_SetRenderDrawColor(_renderer.get(),
				255, 255, 63, 255);
	SDL_RenderFillRect(_renderer.get(), &rect2);
}

void WindowWithRectangles::update()
{
	// 2) Изменение состояния программы
	rect1.x += rect1_dx;
	rect1.y += rect1_dy;
	if (rect1.x <= 0)                        rect1_dx =  1;
	if (rect1.x + rect1.w >= WINDOW_WIDTH)   rect1_dx = -1;
	if (rect1.y <= 0)                        rect1_dy =  1;
	if (rect1.y + rect1.h >= WINDOW_HEIGHT)  rect1_dy = -1;
}
