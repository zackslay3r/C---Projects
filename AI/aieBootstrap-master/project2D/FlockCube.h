#pragma once

#include "Object.h"
#include "Vector2.h"


class FlockCube :
	public Object
{
public:
	FlockCube(float positionX, float positionY);
	void render();
	void update(float dt);
	float maxSpeed = 200;
	float minSpeed = 0;
	std::list<IBehavior*> m_behaviours;
	Vector2 desiredVelocity;
	~FlockCube();
};

