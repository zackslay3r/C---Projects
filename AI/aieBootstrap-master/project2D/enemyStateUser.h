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
// uses the namespace of BehaviourManagement.
using namespace BehaviourManagement;
//Forward declaration of UtilityAI.
class UtilityAI;


class enemyStateUser :
	public Object
{
public:

	enemyStateUser();
	/*
	* enemyStateUser(float positionX, float positionY);
	*
	* This is the a constructor for the enemy state user
	* that takes in two float parameters and sets the enemy's position to that.
	*
	*/
	enemyStateUser(float positionX, float positionY);


	
	/*
	* void render();
	*
	* This is responsible for rendering the enemyState users and returns void.
	*
	*/
	void render();
	/*
	* void update(float dt);
	*
	* This is responsible for updating the enemyState users by taking in deltaTimne as a float and returns void.
	*
	*/
	void update(float dt);
	/*
	* changeToSeek(Object* target);
	*
	* This is responsible for changing the enemyState users seek behaviour weight to 1 and for flee and wander to be set to 0.
	* it takes in an Object* as a parameter and returns void.
	*
	*/
	void changeToSeek(Object* target);
	/*
	* changeToFlee(Object* awayFromTarget);
	*
	* This is responsible for changing the enemyState users flee behaviour weight to 1 and for seek and wander to be set to 0.
	* it takes in an Object* as a parameter and returns void.
	*
	*/
	void changeToFlee(Object* awayFromTarget);
	
	/*
	* changeToWander(Object* target);
	*
	* This is responsible for changing the enemyState users Wander behaviour weight to 1 and for seek and flee to be set to 0.
	* it takes in an Object* as a parameter and returns void.
	*
	*/
	void changeToWander(Object* target);
	
	
	int health;
	Node* currentNode;
	Node* MoveTo;
	Object* target;
	std::string healthString;
	Vector2 previousPos;
	std::list<IBehavior*> m_behaviours;
	std::list<Node*> path, closedSet, openSet;
	UtilityAI* utility;
	gameFSM* enemyFSM;
	

	/*
	* enemyStateUser();
	*
	* This is the default destructor.
	*
	*/
	~enemyStateUser();
};

