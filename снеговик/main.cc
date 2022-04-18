/*
 * mingw32
 * SDL2main
 * SDL2
 * SDL2_image
 * opengl32
 * glu32
 */
#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
//#include "Window.h"
//#include "MyWindow.h"
#include "HouseWindow.h"

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	try{
		//Window w;
		//MyWindow w;
		HouseWindow w;

		w.main_loop();
	} catch (const std::exception &e) {
		std::cerr << "��������� ������:\n" <<
				e.what() <<
				std::endl;
		exit(1);
	}

	return 0;
}
