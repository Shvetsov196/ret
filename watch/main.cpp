/*
 * main.cpp
 *
 *  Created on: 3 апр. 2022 г.
 *      Author: БЗМК
 */
/*
 * Библиотеки
 *
 * windows+mingw:
 * 		mingw32
 * 		SDL2main
 * 		SDl2
 * 		SDL2_image
 * 		opengl32
 * 		glu32
 * */
#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "HouseWindow.h"
int main(int,char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	try{
		HouseWindow w;

		w.main_loop();
	}catch(const std::exception &e){
		std::cerr<<"Произошла ошибка:\n"<<
				e.what()<<
				std::endl;
		exit(1);
	}




	return 0;
}
