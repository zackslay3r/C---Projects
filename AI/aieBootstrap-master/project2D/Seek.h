#pragma once
#include "IBehavior.h"
#include "Global.h"
class Seek : public IBehavior
{
public:

	
	
	

	Seek(Object* myself);
	
	void Update(float dt);
	~Seek();
};

