#include "AIHard.h"
#include "Factory.h"

AIHard::AIHard()
{
}

AIHard::~AIHard()
{
}

void AIHard::update(float dt)
{
	if (FACT->ball && FACT->ball->rootEntity->active && actor)
	{
		if (FACT->ball->rootEntity->getWorldPos().y > actor->rootEntity->getWorldPos().y + 5.0f)
		{
			moveUp(dt);
		}
		else if (FACT->ball->rootEntity->getWorldPos().y < actor->rootEntity->getWorldPos().y - 110.0f)
		{
			moveDown(dt);
		}
	}
	else
	{
		moveStop(dt);
	}
}
