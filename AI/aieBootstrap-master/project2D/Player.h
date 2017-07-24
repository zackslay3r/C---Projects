#pragma once
#include "Object.h"
#include "PlayLoop.h"
#include "Application2D.h"
class Player : public Object
{
public:
	Player();
	void render();
	void update(float dt);
	/*bool checkCollide(Vector2 shape1Pos, Vector2 shape1Scale, Vector2 shape2Pos, Vector2 shape2Scale);*/
	~Player();
	
protected:


	aie::Input* input;
};

