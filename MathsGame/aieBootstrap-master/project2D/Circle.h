#pragma once
#pragma once
#include <Vector2.h>
#include <Matrix3.h>
#include "Application.h"
#include "Object.h"
#include "Input.h"

/*
* class Circle
*
* This class is based on the object class and has the same functions as an Object class, it however has its own Constructor based on the same parameters as 
* the object class, it also has its own Update and Draw function, as well as a bool variable called bounceUp and a vector2 called velocity.
*
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Circle : public Object
{
public:
	/* Circle();
	*
	* This is the default constructor for a Circle object.
	*
	*/
	Circle();
	
	 /* Circle(aie::Texture* texture, aie::Renderer2D*	Renderer);
	*
	* This is a constructor that takes on the texture and the Renderer as parameters.
	*
	* @param aie::Texture* - A texture that will be used for a particular object
	* @param aie::Renderer2D* - A pointer to the Renderer of the bootstrap.
	*/
	Circle(aie::Texture* texture, aie::Renderer2D*	Renderer);

	/* void Update(float DT, aie::Input* Input);
	*
	* This function Updates the values of a circle based upon the parameter of deltaTime (which is game time.) as we as input, which allows the user to input 
	* keyboard commands.
	*
	* @param float DT - This is deltatime.
	* @param aie::Input* - This allows for user input.
	* @returns void
	*/
	void Update(float DT, aie::Input* Input);
	
	/* void Draw();
	*
	* This function draws a circle object to the game screen when it is called based on its sprite, this draw will usually happen in update.
	*
	* @returns void
	*/
	void Draw();

	/* ~Circle();
	*
	* This is the default destructor for a Circle object.
	*
	*/
	~Circle();

	bool bounceUp = true;
	Vector2 velocity;
private:
	
};