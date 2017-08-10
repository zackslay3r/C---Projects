#pragma once
#include "Object.h"

class Object;
class IBehavior
{
public:

	enum BehaviourNames { MOVEALONGPATH, SEEK, WANDER, FLEE, SEPERATION, COHESION, ALIGNMENT, AVOIDANCE };
	BehaviourNames type;

	Object* mySelf;
	IBehavior(Object* myself);
	IBehavior();
	float behaviourWeight;
	//virtual void Update(Object* pObject,float deltaTime) = 0;
	virtual Vector2 Update( float deltaTime) = 0;
	~IBehavior();
private:
	

};

