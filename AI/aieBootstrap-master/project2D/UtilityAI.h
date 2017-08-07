#pragma once
#include "Enemy.h"
#include <list>
class UtilityAI
{
public:
	UtilityAI();

	void runAway(Enemy* allEnemies);
	~UtilityAI();
};

