#pragma once
#include "Object.h"
class Wall : public Object
{
public:
	/*
	* Object(float positionx, float positiony);
	*
	* This is the Wall constructor. it takes in two float parameters and sets the position
	* of the wall based on the parameters passed in.
	*
	*/
	Wall(float positionx, float positiony);
	
	/*
	* ~Wall();
	*
	* This is the walls destructor.
	*
	*/
	~Wall();

	/*
	* void render();
	*
	* This is the render function, which will render the wall onto the screen. and returns void.
	*
	*/
	void render();
	


	void update(float dt);

	/*
	* void setPos(int posx, int posy);
	*
	* This is the setPos function, which will set the position of the wall based on the parameters of two floats
	* and returns type void.
	*
	*/
	void setPos(float posx, float posy);
};

