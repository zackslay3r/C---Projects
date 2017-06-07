#include "Multiball.h"
#include "Factory.h"
#include "AssetManager.h"

Multiball::Multiball()
{

	baseMaxVelocity = 500.0f;
	maxVelocity = baseMaxVelocity;

	//Create root entity.
	rootEntity = FACT->addEntity(Entity::Et::Soccerball);

	rootEntity->setLocalPosition(Vector2());

	rootEntity->stickyReceiver = true;

}

Multiball::~Multiball()
{
	FACT->removeEntity(rootEntity);
}

void Multiball::updatePhysics(float dt)
{

	//Only active actors update.
	if (!active) return;

	//Limit rotation speed.
	MathsLib::clamp(rootEntity->angVelocity, -4.0f, 4.0f);

	//Add to X component of velocity if it's below minimum.
	//This helps prevent balls bouncing between the walls but not moving left or right very fast.
	if (rootEntity->velocity.x > -100.0f && rootEntity->velocity.x < 100.0f)
	{
		float dir = rootEntity->velocity.x >= 0 ? 1.0f : -1.0f;
		rootEntity->velocity.x += 10.0f * dt * dir;
	}

	//Keep velocity above minimum.
	float minVel = maxVelocity;
	float minVelSqr = minVel * minVel;

	float curVelSqr = rootEntity->velocity.magnitudeSqr();

	if (curVelSqr < minVelSqr)
	{
		rootEntity->velocity.normalise();
		if (abs(rootEntity->velocity.x) < 0.5f && abs(rootEntity->velocity.y) < 0.5f)
		{
			rootEntity->velocity = Vector2(rootEntity->velocity.x, (float)mt.rng(-1.0, 1.0));
			rootEntity->velocity.normalise();
		}
		rootEntity->velocity = rootEntity->velocity * minVel;
	}

	//Keep velocity below maximum.
	float maxVel = maxVelocity;
	float maxVelSqr = maxVel * maxVel;

	curVelSqr = rootEntity->velocity.magnitudeSqr();

	if (curVelSqr > maxVelSqr)
	{
		rootEntity->velocity.normalise();
		rootEntity->velocity = rootEntity->velocity * maxVel;
	}
}


void Multiball::update(float dt)
{
	//Get faster over time.
	maxVelocity += 35.0f * dt;
}

void Multiball::explode()
{

	//The multiball doesn't need to explode.
	return;

	//float velXmin = -100.0f;
	//float velXmax = 100.0f;
	//float velYmin = -100.0f;
	//float velYmax = 100.0f;

	//std::vector<Entity *> parts = {
	//	rootEntity
	//};

	////Add all child entities recursively to parts vector array. Passed in by reference.
	//rootEntity->getChildEntities(parts, true);

	//for (Entity *var : parts)
	//{
	//	var->setParent(nullptr);
	//	var->velocity = Vector2((float)mt.rng(velXmin, velXmax), (float)mt.rng(velYmin, velYmax));
	//	var->angVelocity = MathsLib::deg2rad((float)mt.rng(-6.28319f, 6.28319f));
	//	var->setLifeTimeExpiry((float)mt.rng(5.0f, 5.5f));
	//}

	//rootEntity = nullptr;

	//active = false;

	//FACT->removeActor(this);
}
