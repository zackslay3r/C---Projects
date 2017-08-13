#pragma once
#include <list>


// Forward declaration of classes.
class Enemy;
class enemyStateUser;
class Player;



/*
* class blackBoard
*
* this is the blackboard class, which enemys will send information to to determine whether or not they will change behaviours based on the influence 
* other enemys.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class blackBoard
{
public:
	blackBoard();


	std::list<Enemy*> activeEnemies;
	std::list<enemyStateUser*> isOtheractiveEnemies;
	Player* player;
	std::list<Enemy*> isSeeking;
	std::list<enemyStateUser*> isOtherSeeking;
	// Make the other enmies seek as well if they are the in range.
	void seekAsWell();
	
	// this function will be called by the enemy in its update to determine whether or not it should seek using the path.
	// it takes a parameter of type Enemy* or enemyStateUser* and returns a bool.
	bool usePathFollow(Enemy* myself);
	bool usePathFollow(enemyStateUser* myself);
	

	// Have these three distance checks so that smartEnemies can check against other smarts, 
	//dumbEnemies can check against dumbs
	// and that smart enemies can check against dumb ones
	bool distanceCheck(Enemy* myself,float distance, Enemy* otherEnemy);
	bool distanceCheck(enemyStateUser* myself, float distance, enemyStateUser* otherEnemy);

	~blackBoard();
};

