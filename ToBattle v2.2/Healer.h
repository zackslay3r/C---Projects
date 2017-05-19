#pragma once

#include "Enemy.h"
#include "Orc.h"
#include <iostream>

class Healer : public Enemy
{
public:
    Healer();
    virtual ~Healer();

    // Heals the orc pointed to by "pOrc"
    void healingSurge(Enemy *);
	int getId();
	void heal(Enemy *);
	int getHealth();

protected:


	virtual bool isHealer() { return true; }
    //
    // Members just for Healer go here...
    //
};

