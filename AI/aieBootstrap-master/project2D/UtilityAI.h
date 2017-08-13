#pragma once
#include "Enemy.h"
#include "enemyStateUser.h"
#include <list>
class Enemy;
/*
* class UtilityAI
*
* This is the Utility AI, which is a AI that I use for checking how much a Flee behaviour should scale.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class UtilityAI
{
public:
	/*
	* UtilityAI();
	*
	* This is the constructor.
	*
	*/
	UtilityAI();
	/*
	* void runAway(Enemy* allEnemies);
	*
	* This is the function responsible for scaling the Flee behaviour weight. it takes in a parameter of Enemy* or enemyStateUser* and returns void.
	*
	*/
	void runAway(Enemy* allEnemies);
	void runAway(enemyStateUser* stateEnemy);
	/*
	* ~UtilityAI();
	*
	* This is the destructor.
	*
	*/
	~UtilityAI();
};

