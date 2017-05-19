#pragma once

#include <iostream>
#include <stdio.h>
#include "Enemy.h"
#include "Ally.h"
// creates a weapon type for an Orc to hold
// the different weaponType will affect what damage the orc does.
enum WeaponType { Axe, Sword };
// This function allows us to output the weapontype the Orc has that they are attacking with.
std::ostream & operator<<(std::ostream & out, WeaponType & w);
// This is a 'Orc' class which is a child of enemy.
// and it contains all the values of an enemy class with as well as 

// weaponType and aggression levels.
// both affecting how much an orc will dmamage you.
class Orc : public Enemy
{
public:
    Orc();
    virtual ~Orc();

    int getAggression();
	int getId();
	int getHealth();
	void computeDamage(Ally *);
	WeaponType m_weaponType;
	

protected:
	
	virtual bool isOrc() { return true; }
	
};

