/*
 * MyWindow.h
 *
 *  Created on: 3 àïð. 2022 ã.
 *      Author: ÁÇÌÊ
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

class MyWindow: public Window {
public:
	static constexpr int WINDOW_WIDTH  = 500;
	static constexpr int WINDOW_HEIGHT = 500;

	virtual void render() override;
	virtual void setupGL() override;
	virtual void update() override ;
protected:
	double _seconds {0.0};
	double _step {0.0};
	void draw_clock();

public:
	MyWindow();
	virtual ~MyWindow()=default;
};

#endif /* MYWINDOW_H_ */
