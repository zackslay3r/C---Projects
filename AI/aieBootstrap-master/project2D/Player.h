#pragma once
#include "Object.h"
#include "PlayLoop.h"
#include "Application2D.h"
#include "Node.h"
#include "NodeManager.h"
class Node;
class NodeManager;
class Player : public Object
{
public:
	Player();
	void render();
	void update(float dt);
	/*bool checkCollide(Vector2 shape1Pos, Vector2 shape1Scale, Vector2 shape2Pos, Vector2 shape2Scale);*/
	~Player();
	Node* closestNode;
protected:


	aie::Input* input;
	
};

