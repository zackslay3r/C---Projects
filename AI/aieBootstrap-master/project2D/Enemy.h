#pragma once
#include "Object.h"
#include "Node.h"
#include "NodeManager.h"
#include "PlayLoop.h"
#include "Application2D.h"

#include "IBehavior.h"

class Enemy : public Object
{
public:
	Enemy();
	Enemy(float positionX, float positionY);
	~Enemy();

	void render();
	void update(float dt);
	void changeToSeek(Object* target);

	Node* currentNode;
	Node* MoveTo;
	Object* target;

	std::list<IBehavior*> m_behaviours;
	std::list<Node*> path;

};

