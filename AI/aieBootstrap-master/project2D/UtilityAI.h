#pragma once
#include "Enemy.h"
#include "enemyStateUser.h"
#include <list>
class Enemy;
class UtilityAI
{
public:
	UtilityAI();

	void runAway(Enemy* allEnemies);
	void runAway(enemyStateUser* stateEnemy);
	~UtilityAI();
};

