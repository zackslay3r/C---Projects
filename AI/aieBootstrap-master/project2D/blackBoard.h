#pragma once
#include <list>
enum eBlackBoardDataType { type_float, type_int, type_char, type_bool, type_pointer };

class Enemy;
class enemyStateUser;
class Player;
//struct BlackBoardData 
//{
//	eBlackBoardDataType type;
//};
//
//union type
//{
//	float floatValue;
//	int intValue;
//	char charValue;
//	bool boolValue;
//	void* pointerValue;
//};



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
	bool usePathFollow(Enemy* myself);
	bool usePathFollow(enemyStateUser* myself);
	

	// Have these three distance checks so that smartEnemies can check against other smarts, 
	//dumbEnemies can check against dumbs
	// and that smart enemies can check against dumb ones
	bool distanceCheck(Enemy* myself,float distance, Enemy* otherEnemy);
	bool distanceCheck(enemyStateUser* myself, float distance, enemyStateUser* otherEnemy);

	~blackBoard();
};

