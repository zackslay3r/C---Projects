#pragma once
#include "Object.h"
#include "Node.h"
#include "NodeManager.h"

class Enemy : public Object
{
public:
	Enemy();
	~Enemy();

	void render();
	void update(float dt);

	Node* currentNode;
	Node* MoveTo;

	

};

