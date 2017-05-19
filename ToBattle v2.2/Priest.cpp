#include "Priest.h"
#include <iostream>


Priest::Priest()
{
	m_health = 50;
}


Priest::~Priest()
{
}

void Priest::healingWave(Ally *pAlly)
{
	if (pAlly->isPlayer())
	{
		std::cout << "You are being healed for 35!" << "\n\n";
		pAlly->m_health += 35;
		//std::cout << "Player's health is now" << pAlly->m_health;
	}
	else if (pAlly->isPriest())
	{
		std::cout << "The priest is healing themselves for 20!" << "\n\n";
		pAlly->m_health += 20;
		//std::cout << "The friendly healer's health is now" << pAlly->m_health;
	}
}

int Priest::getId()
{
	return m_AllyId;
}

int Priest::getHealth()
{
	return m_health;
}