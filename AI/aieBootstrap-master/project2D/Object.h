#pragma once
#include "../bootstrap/Application.h"
#include "../bootstrap/Renderer2D.h"

/*
* class Object
*
* This is an Object class.
* This is the parent class for every object in my game and all objects have the values within Object.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/

class Object
{
public:
	// These two values are to determine position.
	float posX, posY;
	// These two values are to determine movement along the x and y axis of the screen.
	float velocityX, velocityY;
	// These values help determine the size of a particular object based on widith and height.
	float width, height;
	
	/*
	* Object();
	*
	* This is the Object constructor.
	*
	*/
	Object();


	/// This object class does not need a update function, as we are are going to get the other states to update the objects for us.
	
	/*	 void render();
	*	This function is a virtual function that is responsible for drawing the objects. 
	*
	*	@returns void
	*/
	virtual void render();
	

	// This is the object destructor.
	~Object();

protected:
	
};

