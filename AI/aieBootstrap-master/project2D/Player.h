#pragma once
#include "Object.h"
#include "PlayLoop.h"
#include "Application2D.h"
#include "Node.h"
#include "NodeManager.h"
class Node;
class NodeManager;
/*
* class Player
*
* This is the Player class. this will be what the user can control.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Player : public Object
{
public:
	/*
	* Player();
	*
	* This is the Player constructor.
	*
	*/
	Player();
	/*
	* Player(float positionX, float positionY);
	*
	* This is a Player constructor. it takes in two parameters and sets the players position to be based off of the two parameters.
	*
	*/
	Player(float positionX, float positionY);
	
	/*
	* void render();
	*
	* this is the render function. it is responsible for rendering the player object and returns void.
	*
	*/
	void render();
	/*
	* void update(float dt);
	*
	* this is the update function. it is responsible for update the player object, takes in a parameter of type float and returns void.
	*
	*/
	void update(float dt);
	/*
	* ~Player();
	*
	* This is the Player constructor.
	*
	*/
	~Player();
	Node* closestNode;
protected:


	aie::Input* input;
	
};

