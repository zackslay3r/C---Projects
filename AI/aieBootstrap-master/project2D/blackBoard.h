#pragma once
#include <list>
enum eBlackBoardDataType { type_float, type_int, type_char, type_bool, type_pointer };

class Enemy;
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
	Player* player;
	std::list<Enemy*> isSeeking;
	void seekAsWell();
	bool distanceCheck(Enemy* myself,float distance, Enemy* otherEnemy);
	~blackBoard();
};

