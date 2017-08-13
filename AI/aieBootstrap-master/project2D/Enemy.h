#pragma once
#include "Object.h"
#include "Node.h"
#include "NodeManager.h"
#include "PlayLoop.h"
#include "Application2D.h"
#include "gameFSM.h"
#include "IBehavior.h"
#include "Global.h"
#include "UtilityAI.h"

using namespace BehaviourManagement;
class UtilityAI;
/*
* class Enemy
*
* this is the Enemy class, which will help demonstrate Behaviours, as well
* as demostrating the utilityAI and BlackBoard.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Enemy : public Object
{
public:
	/*
	* Enemy();
	*
	* This is the default constructor.
	* 
	*/
	Enemy();
	/*
	* Enemy(float positionX, float positionY);
	*
	* This is a constructor. it sets the position of the enemy to the two floats of posX and posY. 
	*
	*/
	Enemy(float positionX, float positionY);
	/*
	* ~Enemy();
	*
	* This is the default destructor.
	*
	*/
	~Enemy();
	double health;
	/*
	* void render();
	*
	* this is the render function. it is responsible for rendering the enemy itself and returns void.
	*
	*/
	void render();
	/*
	* void update(float dt);
	*
	* this is the update function. it is responsible for updating the enemy itself
	* it takes the parameter of deltatime which is a float and returns void.
	*
	*/
	void update(float dt);
	/*
	* void changeToSeek();
	*
	* this is the changeToSeek function. it will set all behaviourWeight of the other behaviours 
	* to 0 other then the avoidance behaviour and set Seek to 1 and returns void.
	*
	*/
	void changeToSeek();
	/*
	* void changeToFollowPath();
	*
	* this is the changeToSeek function. it will set all behaviourWeight of the other behaviours
	* to 0 other then the avoidance behaviour and set FollowPath to 1 and returns void.
	*
	*/
	void changeToFollowPath();
	/*
	* void changeToFlee();
	*
	* this is the changeToSeek function. it will set all behaviourWeight of the other behaviours
	* to 0 other then the avoidance behaviour and set flee to 1 and returns void.
	*
	*/
	void changeToFlee();
	/*
	* void changeToWander();
	*
	* this is the changeToSeek function. it will set all behaviourWeight of the other behaviours
	* to 0 other then the avoidance behaviour and set Wander to 1 and returns void.
	*
	*/
	void changeToWander();
	
	
	Node* currentNode;
	Node* MoveTo;
	Object* target;
	float maxSpeed = 150;
	float minSpeed = 0;
	std::string healthString;
	Vector2 previousPos;
	Vector2 desiredVelocity;
	std::list<IBehavior*> m_behaviours;
	std::list<Node*> path, closedSet, openSet;
	UtilityAI* utility;
	std::list<Vector2> feelers;
	//gameFSM* enemyFSM;
};

