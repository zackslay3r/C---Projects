#pragma once
#include <cstdlib>
#include "Ally.h"
enum class playerWeapon { Axe, Sword };
class Player : public Ally
{
public:
	Player();
	virtual ~Player();
	void computeDamage(Enemy *);
	int getId();
	int getHealth();
	playerWeapon m_playerWeapon;
	void setWeapon(playerWeapon pWeapon);


private:

	virtual bool isPlayer() { return true; }

};

