#pragma once
#include "Ally.h"
class Priest :
	public Ally
{
public:
	Priest();

	// Heals the player pointed to by "pPlayer"
	void healingWave(Ally *);
	int getId();
	int getHealth();
	~Priest();

protected:
	virtual bool isPriest() { return true; }
};

