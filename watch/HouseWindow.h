/*
 * HouseWindow.h
 *
 *  Created on: 5 àïð. 2022 ã.
 *      Author: ÁÇÌÊ
 */

#ifndef HOUSEWINDOW_H_
#define HOUSEWINDOW_H_

#include "Window.h"
#include "Model.h"
#include "Texture.h"
class HouseWindow: public Window
{
private:
	Model _House_model;
	Texture _house_texture {"Houses.png"};
	double _angle = 0.0;
public:
	static constexpr int WINDOW_WIDTH  = 500;
	static constexpr int WINDOW_HEIGHT = 500;
	virtual void render() override;
	virtual void setupGL() override;
	virtual void update() override ;
public:
	HouseWindow();
	virtual ~HouseWindow() = default;
};

#endif /* HOUSEWINDOW_H_ */
