#include "Ally.h"

int g_numAllys = 0;

// This is the constructor. when a new ally is created, it should have these values.
Ally::Ally()
{
	m_health = 0;
	m_armour = 0;
	m_AllyId = 0;
	g_numAllys++;
}


Ally::~Ally()
{
}

int Ally::getNumAllys()
{
	return g_numAllys;
}
