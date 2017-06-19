#pragma once
#include "../bootstrap/Application.h"
#include "../bootstrap/Renderer2D.h"


// This is an Object class.
// This is the parent class for every object in my game and all objects have the values within Object.
class Object
{
public:
	// These two values are to determine position.
	float posX, posY;
	// These two values are to determine movement along the x and y axis of the screen.
	float velocityX, velocityY;
	// These values help determine the size of a particular object based on widith and height.
	float width, height;
	
	// This is the Object default constructor.
	Object();

	//Object(float PosX, float PosY, float width, float height,float veloX, float veloY);

	//void SetUp(float PosX = 0, float PosY = 0, float velocityX = 0, float velocityY = 0);
	
	// These two functions will be overwritten by child classes versions of the same function.
	virtual void Update(float DT);
	virtual void Draw();
	

	// This is the object destructor.
	~Object();

protected:
	
};

