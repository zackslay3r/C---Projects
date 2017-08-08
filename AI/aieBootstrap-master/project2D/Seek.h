#pragma once
#include "IBehavior.h"
#include "Global.h"
class Seek : public IBehavior
{
public:

	
	
	
	
	Seek(Object* myself);
	
	Vector2 Update(float dt);
	~Seek();
};

