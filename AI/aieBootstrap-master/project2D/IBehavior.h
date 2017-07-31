#pragma once
#include "Object.h"

class Object;
class IBehavior
{
public:

	enum BehaviourNames { SEEK, WANDER, FLEE };
	BehaviourNames type;

	Object* mySelf;
	IBehavior(Object* myself);
	IBehavior();
	float behaviourWeight;
	//virtual void Update(Object* pObject,float deltaTime) = 0;
	virtual void Update( float deltaTime) = 0;
	~IBehavior();
private:
	

};

