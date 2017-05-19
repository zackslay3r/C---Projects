#pragma once

class Enemy;
class Ally
{
public:
	
	Ally();
	virtual ~Ally();


	// a static method is a method that is seperate from the class it is in, but uses the stuff within the scope of a class.
	static int getNumAllys();


	// a virtual function is a function that gets skipped.
	// this first function is skipped so that the derived classes can use their own version.
	// since a virtual function is skipped, we usually make it do nothing.
	virtual void healingWave(Ally *)
	{
	}
	// this is again a virtual method so that it can use Orc's getAggression method.
	virtual int getAggression()
	{
		return 0;
	}


	virtual int getId()
	{
		return 0;
	}

	virtual void move()
	{

	}


	// the virtual method for computing damage.
	virtual void computeDamage(Enemy *)
	{


	}
	virtual void playerTurn(int, Ally* [], int, Enemy* [])
	{
	}

	virtual bool isPlayer() { return false; }
	virtual bool isPriest() { return false; }


	// thse are variables that all ally's have.
	int m_health;
	int m_armour;
	int m_AllyId;
};

