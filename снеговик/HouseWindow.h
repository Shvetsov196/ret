#ifndef HOUSEWINDOW_H_
#define HOUSEWINDOW_H_
#include "Window.h"
#include "Model.h"
#include "Texture.h"
#include "Primitives.h"

class HouseWindow: public Window
{
private:
	Model _house_model;
	Texture _house_texture {"Houses.png"};
	Texture _stvol_texture {"stvol.jpg"};
	Texture _elka_texture {"elka.jpg"};
	Texture _pugovki_texture {"texture002.png"};
	Texture _stars {"stars_milky_way.jpg"};
	Texture _nos{"texture001.png"};
	Texture _pug_texture {"pugovki.png"};
	double _angle = 0.0;


public:
	static constexpr int WINDOW_WIDTH = 500;
	static constexpr int WINDOW_HEIGHT = 500;

	virtual void update() override;
	virtual void render() override;
	virtual void setupGL() override;

public:
	HouseWindow();
	virtual ~HouseWindow() = default;
};

#endif /* HOUSEWINDOW_H_ */
