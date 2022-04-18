#include "HouseWindow.h"
#include <memory>

HouseWindow::HouseWindow()
:Window(WINDOW_WIDTH, WINDOW_HEIGHT),
 _house_model("House.txt")
{
	SDL_SetWindowTitle(_window.get(), "ff Window");
}

void HouseWindow::update() {
	_angle += 0.7;

}

void HouseWindow::render() {


	glRotated(_angle, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(25.0, 25.0, 15.0,
			  0.0, 0.0, 2.0,
			  0.0, 0.0, 1.0);
	//небо
	glPushMatrix();
	glDisable(GL_LIGHTING);
	Texture::enable();
	_stars.bind();
	draw_sphere(32, 16, 50.0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();

	Texture::disable();

//	glDisable(GL_LIGHTING);
//	//Рисование skybox, skydome ...
//	glEnable(GL_LIGHTING);

	/*
	 * Хотим:
	 * - Плоскость / кривая поверхность - белого цвета (снег)
	 * - В центре елка. Ствол - цилиндр, ветки - несколько конусов
	 * - Вокруг елки несколько снеговиков: 3 сферы, нос - конус, руки - цилиндры, глаза - сферы и тп
	 */

	glBegin(GL_QUADS);
	glNormal3d(0.0, 0.0, 1.0);
	for (int i = -75; i <75; ++i)
		for (int j = -75; j <75; ++j){
			glVertex3d(i+0, j+0, 0.0);
			glVertex3d(i+1, j+0, 0.0);
			glVertex3d(i+1, j+1, 0.0);
			glVertex3d(i+0, j+1, 0.0);
	}
	glEnd();
	//ёлка
	glPushMatrix();
	glTranslated(10.0, 0.0, 0.75);
	Texture::enable();
	_stvol_texture.bind();
	draw_cylinder(12, 0.5, 7.0);
	glTranslated(0.0, 0.0, 2.5);
	_elka_texture.bind();
	draw_cone(12, 4, 5);
	glTranslated(0.0, 0.0, 3.0);
	_elka_texture.bind();
	draw_cone(12, 3, 4);
	glTranslated(0.0, 0.0, 2.5);
	_elka_texture.bind();
	draw_cone(12, 2, 4);
	glPopMatrix();

// снеговик
	glPushMatrix();
	Texture::disable();
	glRotated(_angle, 0.0, 0.0, 1.0);
	glTranslated(0.0, 0.0, 0.75);
	draw_sphere(16, 10, 1.0);
	glTranslated(0.0, 0.0, 1.25);
	draw_sphere(12, 8, 0.7);
	glTranslated(0.0, 0.0, 0.9);
	draw_sphere(10, 6, 0.4);
	//нос
	Texture::enable();
	_nos.bind();
	glRotated(90.0, 1.0, 1.0, 0.0);
	draw_cone(8, 0.1, 1.0);
	_stvol_texture.bind();
	glTranslated(0.05, 0.0, -0.05);
	glRotated(90.0, 1.0, 0.0, 0.0);
	draw_cylinder(8, 0.07, 1.5);
	_stvol_texture.bind();
	glTranslated(-0.10, 0.0, 0.05);
	glRotated(90.0, 0.0, 1.0, 0.0);
	draw_cylinder(8, 0.07, 1.5);
	_pug_texture.bind();
	glTranslated(-0.4, 0.7, 0.5);
	draw_sphere(10, 6, 0.1);
	_pug_texture.bind();
	glTranslated(-0.3, 0.05, 0.3);
	draw_sphere(10, 6, 0.1);
	_pug_texture.bind();
	glTranslated(1.0, -0.4, -0.7);
	draw_sphere(10, 6, 0.05);
	_pug_texture.bind();
	glTranslated(-0.3, 0.0, -0.3);
	draw_sphere(10, 6, 0.05);
	glPopMatrix();
	Texture::disable();


//дом
	Texture::enable();
	glPushMatrix();
	glTranslated(5.0, 5.0, 0.0);
	glRotated(90.0, 0.0, 0.0, 1.0);
	_house_texture.bind();
	_house_model.draw();
	glPopMatrix();


	Texture::disable();

//	_cylinder_texture.bind();
//	_cone_texture.bind();
//	_earth_texture.bind();
//	draw_prism(6, 1, 2);
//	draw_cylinder(12, 1, 2);
//	draw_pyramid(4, 1, 2);
//	draw_cone(12, 1, 2);
//  draw_disco_ball(16, 8, 2.0);
//	draw_sphere(16, 8, 2.0);

}

void HouseWindow::setupGL() {

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glClearColor(0.1f, 0.25f, 0.45f, 1.0f);

	double aspect_ratio = double(width()) / double(height());

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, aspect_ratio, 0.1, 120.0);
	glMatrixMode(GL_MODELVIEW);
}


