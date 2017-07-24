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
	~Player();

protected:


	aie::Input* input;
};

