#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
#include "ObjectPool.h"


/*
* class Factory
*
* This is the factory class, it is essential in the creation of the objects in my game. 
* With the only purpose of this class to make objects that are either paddles or balls.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/

class Factory
{
public:
	/*
	* Factory();
	*
	* This is the Factory constructor.
	*
	*/
	Factory();
	
	
	// This function is to be able to create a Ball.
	
	/*	static Object* makeBall(float positionX, float positionY);
	*	This function is used to call the Ball(positionX, positionY) constructor to make a ball at that location.
	*
	*	parameter 1 positionX - the x position of the object.
	*	parameter 2 positionY - the Y position of the object.
	*
	*	@returns Object* - a Ball object.
	*/
	static Object* makeBall(float positionX, float positionY);
	

	// This function is to be able to create a Paddle.
	/*	static Object* makePaddle(float positionX, float positionY);
	*	This function is used to call the Paddle(positionX, positionY) constructor to make a paddle at that location.
	*
	*	parameter 1 positionX - the x position of the object.
	*	parameter 2 positionY - the Y position of the object.
	*
	*	@returns Object* - a Paddle object.
	*/
	static Object* makePaddle(float positionX, float positionY);
	

	/*	static void fillBallPool(int n);
	*	This function is used to fill the Ball Stack with Ball objects based on the amount given as a parameter.
	*
	*	parameter 1 n - the amount of objects wanting to be created.
	*
	*	@returns void
	*/
	static void fillBallPool(int n);

	/*	static void fillPaddlePool(int n);
	*	This function is used to fill the Paddle Stack with Paddle objects based on the amount given as a parameter.
	*
	*	parameter 1 n - the amount of objects wanting to be created.
	*
	*	@returns void
	*/
	static void fillPaddlePool(int n);

	/*
	* ~Factory();
	*
	* This is the Factory destructor.
	*
	*/
	~Factory();
};


