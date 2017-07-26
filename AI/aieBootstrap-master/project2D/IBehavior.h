#pragma once
#include "Object.h"

class Object;
class IBehavior
{
public:
	IBehavior();
	float behaviourWeight;
	//virtual void Update(Object* pObject,float deltaTime) = 0;
	virtual void Update(Object* objectOne, Object* objectTwo, float deltaTime) = 0;
	~IBehavior();
private:
	

};

