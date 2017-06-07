#include "AISimple.h"
#include "Factory.h"

AISimple::AISimple()
{
	hesitateTimer = 0.0f;
	hesitateChanceTimer = 3.0f;
}

AISimple::~AISimple()
{
}

void AISimple::update(float dt)
{

	//Turn off hesitation after timer expires.
	if (hesitateTimer < GCLK->getTimeSeconds()) hesitateTimer = 0.0f;

	//Chance to hesitate.
	if (!hesitateTimer && hesitateChanceTimer < GCLK->getTimeSeconds())
	{
		hesitateChanceTimer = (float)GCLK->getTimeSeconds() + 3.0f;
		double randChance = mt.rng(0, 1);
		if (randChance == 0)
		{
			hesitateTimer = (float)GCLK->getTimeSeconds() + (float)mt.rng(0.0, 2.0);
		}
		else
		{
			hesitateTimer = 0;
		}
	}

	//Hesitate if timer active.
	if (hesitateTimer)
	{
		moveStop(dt);
		return;
	}

	if (FACT->ball && FACT->ball->rootEntity->active && actor)
	{
		if (FACT->ball->rootEntity->getWorldPos().y > actor->rootEntity->getWorldPos().y + 40.0f)
		{
			moveUp(dt);
		}

		if (FACT->ball->rootEntity->getWorldPos().y < actor->rootEntity->getWorldPos().y - 150.0f)
		{
			moveDown(dt);
		}
	}
	else
	{
		moveStop(dt);
	}
}
