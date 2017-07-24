#pragma once
#include "Object.h"

class Object;
class IBehavior
{
public:
	IBehavior();
	virtual void Update(Object *pObject) = 0;
private:
	~IBehavior();

};

