#pragma once
#include "Object.h"
class Wall : public Object
{
public:
	Wall(float positionx, float positiony);
	~Wall();

	void render();
	void update(float dt);
	void setPos(int posx, int posy);
};

