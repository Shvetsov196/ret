/*
 * MyWindow.cpp
 *
 *  Created on: 3 апр. 2022 г.
 *      Author: БЗМК
 */

#include "MyWindow.h"
#include <cmath>
#include <chrono>
#include <ctime>
MyWindow::MyWindow()
: Window(WINDOW_WIDTH, WINDOW_HEIGHT)
{
	// TODO Auto-generated constructor stub
	SDL_SetWindowTitle(_window.get(),"MY OpenGL");
}

void MyWindow::draw_clock() {
	for (double a = 0.0; a < 360; a += 360.0 / 12.0) {
		glPushMatrix();
		glRotated(a, 0.0, 0.0, 1.0);
		glTranslated(0.0, 0.9, 0.0);
		glBegin(GL_QUADS);
		glColor3d(0.3, 1.0, 1.0);
		glVertex2d(-0.05, 0.05);
		glVertex2d(0.05, 0.05);
		glVertex2d(0.05, -0.05);
		glVertex2d(-0.05, -0.05);
		glEnd();
		glPopMatrix();
	}
	for (double b = 0.0; b < 360.0; b += (360.0 / 12.0) / 5.0) {
		glPushMatrix();
		glRotated(b, 0.0, 0.0, 1.0);
		glTranslated(0.0, 0.9, 0.0);
		glBegin(GL_QUADS);
		glColor3d(0.3, 1.0, 1.0);
		glVertex2d(-0.015, 0.015);
		glVertex2d(0.015, 0.015);
		glVertex2d(0.015, -0.015);
		glVertex2d(-0.015, -0.015);
		glEnd();
		glPopMatrix();
	}
	double hours_angle = fmod(_seconds/3600.0, 60.0)*360/60;
	glRotated(hours_angle, 0.0, 0.0, -1.0);
	glBegin(GL_QUADS);
	glColor3d(0.2, 0.7, 0.0);
	glVertex2d(0.0, 0.0);
	glVertex2d(-0.06, 0.1);
	glVertex2d(0.0, 0.5);
	glVertex2d(0.06, 0.1);
	glEnd();


	double minutes_angle =fmod(_seconds/60.0, 60.0)*360/60;
	glRotated(minutes_angle, 0.0, 0.0, -1.0);
	glBegin(GL_QUADS);
	glColor3d(0.5, 0.5, 0.0);
	glVertex2d(0.0, 0.0);
	glVertex2d(-0.06, 0.1);
	glVertex2d(0.0, 0.75);
	glVertex2d(0.06, 0.1);
	glEnd();


	double seconds_angle = fmod(_seconds, 60) / 60.0 * 360.0;
	glRotated(seconds_angle, 0.0, 0.0, -1.0);
	glBegin(GL_QUADS);
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(0.0, 0.0);
	glVertex2d(-0.05, 0.1);
	glVertex2d(0.0, 0.9);
	glVertex2d(0.05, 0.1);
	glEnd();
}

void MyWindow::render()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(3.0, 3.0, 2.0,
			  0.0, 0.0, 0.0,
			  0.0, 0.0, 1.0);
	//для прокрутки
	glRotated(_step, 0.0, 0.0, 1.0);

		glBegin(GL_QUADS);
		//верх
		glColor3d(0.3, 0.3, 0.3);
		glVertex3d(-1.0, 1.0, 0.0);
		glVertex3d(1.0, 1.0, 0.0);
		glVertex3d(1.0, -1.0, 0.0);
		glVertex3d(-1.0, -1.0, 0.0);
		//перед
		glColor3d(0.8, 0.2, 0.2);
		glVertex3d(-1.0, -1.0, 0.0);
		glVertex3d(1.0, -1.0, 0.0);
		glVertex3d(1.0, -1.0, -0.1);
		glVertex3d(-1.0, -1.0, -0.1);
		//задняя стенка
		glColor3d(0.8, 0.2, 0.2);
		glVertex3d(-1.0, 1.0, 0.0);
		glVertex3d(1.0, 1.0, 0.0);
		glVertex3d(1.0, 1.0, -0.1);
		glVertex3d(-1.0, 1.0, -0.1);
		//правая стенка
		glColor3d(0.192, 0.224, 0.255);
		glVertex3d(1.0, -1.0, 0.0);
		glVertex3d(1.0, 1.0, 0.0);
		glVertex3d(1.0, 1.0, -0.1);
		glVertex3d(1.0, -1.0, -0.1);
		//левая стенка
		glColor3d(0.255, 0.255, 0.8);
		glVertex3d(-1.0, -1.0, 0.0);
		glVertex3d(-1.0, 1.0, 0.0);
		glVertex3d(-1.0, 1.0, -0.1);
		glVertex3d(-1.0, -1.0, -0.1);

		//нижняя плоскость
		glColor3d(0.2, 0.2, 0.2);
		glVertex3d(-1.0, 1.0, -0.1);
		glVertex3d(1.0, 1.0, -0.1);
		glVertex3d(1.0, -1.0, -0.1);
		glVertex3d(-1.0, -1.0, -0.1);

		glEnd();

	glTranslated(0.0, 0.0, 0.04);
	draw_clock();
 //размер точки glPointSize(8.0f);

 //толщина линии glLineWidth(8.0f);
 /*
  * GL_POINT - точка по координатам (от двух до 4 координат)
  * GL_LINES - линия по двум точкам
  * GL_LINE_STRIP - ломанная линия (по всем точкам по порядку)
  * GL_LINE_LOOP - ломанная линия с закрытым контуром (первая точка соединяется
  *  с последней, образуя фигуру)
  * GL_TRIANGLES - по трем точкам образует треугольник
  * GL_QUADS -рисует четырехугольник из двух треугольников (1,2,3 и 1,3,4)
  * GL_TRIANGLE_FAN (123 И 134 И 145 И Т.Д.)
  * GL_TRIANGLE_STRIP(123 И 234 И 345 И 456)
  */

 /*
  * для простых двумерных фигур:
  * 	изменение цвета:
  * 		glColor3d
  * 	двумерные массивы
  * 		glLoadIdentity();-
  * 		100
  * 		010
  * 		001
  *
  * 	*матрица переноса
  * 		glTranslated(0.5,0.5,0), где d является double, а f является float;
  * 	*матрица масштабирования:
  * 			sx|0 |0
  * 			0 |sy|0
  * 			0 |0 |1
  * 			glScaled(0.5,0.2,0.1);
  * 	*матрица поворота
  * 		glRotated(45.0,0.0,0.0,1.0)
  */
 //все точки после этого умножаются на матрицу

 /*
  glRotated(45.0,0.0,0.0,1.0);
  glBegin(GL_TRIANGLES);
 	 glColor3d(1.0, 0.0, 0.0);
 	 glVertex2d(0.0,0.9);
 	 glColor3d(0.0,1.0, 0.0);
 	 glVertex2d(0.9,-0.9);
 	 glColor3d(0.0, 0.0, 1.0);
 	 glVertex2d(-0.9,-0.9);
 glEnd();
 */
}
void MyWindow::setupGL()
{
	glEnable(GL_DEPTH_TEST);


	glClearColor(0.1f,0.25f,0.45f,1.0f);
	/*
	 * прямоугольная проекция
	 * 	gluOortho2D
	 * 	gluOrtho
	 */
	double aspect_ratio=double(getWidth())/double(getHeight());
	glMatrixMode(GL_PROJECTION);
//gluOrtho2D(-aspect_ratio,aspect_ratio,-1,1);
	gluPerspective(45,aspect_ratio,0.1,20.0);
	glMatrixMode(GL_MODELVIEW);

}
void MyWindow::update()
{
	auto now =std::chrono::high_resolution_clock::now();
	auto tt = std::chrono::high_resolution_clock::to_time_t(now);
	auto local_time =*localtime(&tt);
	_seconds = local_time.tm_sec+
			   60*local_time.tm_min+
			   3600*local_time.tm_hour;
	_step+=0.04;
}













