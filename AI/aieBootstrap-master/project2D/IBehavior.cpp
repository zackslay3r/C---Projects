#include "IBehavior.h"



IBehavior::IBehavior(Object* myself)
{
	mySelf = myself;
	behaviourWeight = 0.0f;
}

IBehavior::IBehavior()
{
}


IBehavior::~IBehavior()
{
}
