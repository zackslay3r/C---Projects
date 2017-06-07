#include "Player.h"
#include "Factory.h"

Player::Player()
{
	clampX = 0.0f;
	clampYMin = 0.0f;
	clampYMax = 0.0f;
	actor = nullptr;
}

Player::~Player()
{
	if (actor != nullptr) FACT->removeActor(actor);
	actor = nullptr;
}

void Player::moveUp(float dt) const
{
	if (actor != nullptr)
	{
		actor->rootEntity->velocity.y = actor->maxVelocity;
	}
}

void Player::moveDown(float dt) const
{
	if (actor != nullptr)
	{
		actor->rootEntity->velocity.y = -actor->maxVelocity;
	}
}

void Player::moveStop(float dt) const
{
	if (actor != nullptr)
	{
		actor->rootEntity->velocity.y = 0.0f;
	}
}


