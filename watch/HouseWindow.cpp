/*
 * HouseWindow.cpp
 *
 *  Created on: 5 àïð. 2022 ã.
 *      Author: ÁÇÌÊ
 */

#include "HouseWindow.h"

static Model::VerticesType HOUSE_VERTICES
 {
 {1.0f,-2.0f,0.0f} ,
 {1.0f,2.0f,0.0f}  ,
 {-1.0f,2.0f,0.0f} ,
 {-1.0f,-2.0f,0.0f},
 {1.0f,-2.0f,2.5f} ,
 {1.0f,0.0f,2.5f}  ,
 {1.0f,2.0f,2.5f}  ,
 {-1.0f,2.0f,2.5f} ,
 {-1.0f,0.0f,2.5f} ,
 {-1.0f,-2.0f,2.5f},
 {0.0f,2.0f,3.5f}  ,
 {0.0f,0.0f,3.5f}
 };
static Model::FacesType HOUSE_FACES
 {
	{0,1,2,3}   ,{9,4,0,3}  ,
	{7,9,3,2}   ,{10,11,8,7},
	{11,5,8}    ,{4,6,1,0}  ,
	{10,7,2,1,6},{9,8,5,4} ,
	{11,10,6,5}
 };
static Model::NormalsType HOUSE_NORMALS{
	{0.0f,0.0f,-1.0f},
	{0.0f,-1.0f,0.0f},
	{-1.0f,0.0f,0.0f},
	{-0.707107f,0.0f,0.707107f},
	{0.0f,-1.0f,0.0f},
	{1.0f,0.0f,0.0f},
	{0.0f,1.0f,0.0f},
	{0.0f,0.0f,1.0f},
	{0.707107f,0.0f,0.707107f},
};
static Model::TexCoordsType HOUSE_TEX_COORDS{
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}},
	{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f}}
};

static void null_deleter(void*){}

HouseWindow::HouseWindow()
: Window(WINDOW_WIDTH, WINDOW_HEIGHT),
  _House_model("HouseModel.txt")
{
	SDL_SetWindowTitle(_window.get(),"House GL");
}
void HouseWindow::update()
{
	_angle+=0.09;
}
void HouseWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(6.0, 6.0, 4.5,
			  0.0, 0.0, 1.5,
			  0.0, 0.0, 1.0);
	glRotated(_angle,0.0,0.0,1.0);
	Texture::enable();
	_house_texture.bind();
	_House_model.draw();
}

void HouseWindow::setupGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.1f, 0.25f, 0.45f, 1.0f);
	double aspect_ratio=double(getWidth())/double(getHeight());
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45,aspect_ratio,0.1,20.0);
	glMatrixMode(GL_MODELVIEW);
}
