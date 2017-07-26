#pragma once
#include "Object.h"
#include "Node.h"
#include "NodeManager.h"
#include "PlayLoop.h"
#include "Application2D.h"
#include "BehaviourManager.h"

class Enemy : public Object
{
public:
	Enemy();
	Enemy(float positionX, float positionY);
	~Enemy();

	void render();
	void update(float dt);

	Node* currentNode;
	Node* MoveTo;

	BehaviourManager EnemyBehaves;

};

