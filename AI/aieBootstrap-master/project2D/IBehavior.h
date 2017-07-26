#pragma once
#include "Object.h"

class Object;
class IBehavior
{
public:
	IBehavior();
	virtual void Update(Object* pObject,float deltaTime) = 0;
	~IBehavior();
private:
	

};

