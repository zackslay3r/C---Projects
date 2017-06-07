#include "Actor.h"
#include "Factory.h"
#include "Player.h"

Actor::Actor()
{
	//Actor active by default.
	active = true;
	
	player = nullptr;

	rootEntity = nullptr;

	baseMaxVelocity = 0.0f;

	maxVelocity = baseMaxVelocity;
}

Actor::~Actor()
{
	if (player != nullptr)
	{
		player->actor = nullptr;
	}
}

void Actor::randomDirection(float speed) const
{
	rootEntity->velocity = Vector2(mt.rng(0, 1) ? -1.0f : 1.0f, (float)mt.rng(-0.5, 0.5)).normalised();
	rootEntity->velocity = rootEntity->velocity * speed;
}
