#pragma once
#include "Object.h"
#include "Node.h"
#include "NodeManager.h"
#include "PlayLoop.h"
#include "Application2D.h"
#include "gameFSM.h"
#include "IBehavior.h"
#include "Global.h"

using namespace BehaviourManagement;
class Enemy : public Object
{
public:
	Enemy();
	Enemy(float positionX, float positionY);
	~Enemy();
	int health;
	void render();
	void update(float dt);
	void changeToSeek(Object* target);
	void changeToFlee(Object* awayFromTarget);
	void changeToWander(Object* target);
	Node* currentNode;
	Node* MoveTo;
	Object* target;
	std::string healthString;
	Vector2 previousPos;
	std::list<IBehavior*> m_behaviours;
	std::list<Node*> path, closedSet, openSet;
	gameFSM* enemyFSM;
};

