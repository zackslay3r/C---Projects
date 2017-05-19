#pragma once
#include "Ally.h"

class Enemy
{
public:
    Enemy();
    virtual ~Enemy();

    
	// a static method is a method that is seperate from the class it is in, but uses the stuff within the scope of a class.
	static int getNumEnemies();
	

	// a virtual function is a function that gets skipped.
	// this first function is skipped so that the derived classes can use their own version.
    // since a virtual function is skipped, we usually make it do nothing.
	virtual void healingSurge(Enemy *)
    {
    }
	// this is again a virtual method so that it can use Orc's getAggression method.



	virtual int getId()
	{
		return 0;
	}

    virtual void move()
    {

    }


	// the virtual method for computing damage.
    virtual void computeDamage(Ally *)
    {
		

    }

	virtual bool isOrc() { return false; }
	virtual bool isHealer() { return false; }


	// thse are variables that all enemy's have.
    int m_health;
    int m_armour;
	int m_enemyId;

	

protected:

};

