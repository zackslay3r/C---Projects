#pragma once
#include "Object.h"
class Wall : public Object
{
public:
	Wall();
	~Wall();

	void render(int posx, int posy);
	void setPos(int posx, int posy);
};

