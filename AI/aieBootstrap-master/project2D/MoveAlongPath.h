#pragma once
#include "IBehavior.h"
#include "Global.h"
class MoveAlongPath : public IBehavior
{
public:
	
	MoveAlongPath(Object* myself);
	
	Vector2 Update(float dt);
	~MoveAlongPath();
};

