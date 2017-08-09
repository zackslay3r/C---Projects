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
class Enemy : public Object
{
public:
	Enemy();
	Enemy(float positionX, float positionY);
	~Enemy();
	int health;
	void render();
	void update(float dt);
	void changeToSeek();
	void changeToFlee();
	void changeToWander();
	Node* currentNode;
	Node* MoveTo;
	Object* target;
	float maxSpeed = 150;
	float minSpeed = 50;
	std::string healthString;
	Vector2 previousPos;
	Vector2 desiredVelocity;
	std::list<IBehavior*> m_behaviours;
	std::list<Node*> path, closedSet, openSet;
	UtilityAI* utility;
	std::list<Vector2> feelers;
	//gameFSM* enemyFSM;
};

