#include "Orc.h"
#include <string>

std::ostream & operator<<(std::ostream & out, WeaponType & w)
{
	switch (w)
	{
	case WeaponType::Axe:
		return out << "Axe";
	case WeaponType::Sword:
		return out << "Sword";
	default:
		return out << "Unknown.";
	}
}



Orc::Orc()
{
    // Override the Enemy variables to values that apply to Orcs
    m_health = 100;
	m_enemyId = 1;
	m_weaponType = WeaponType(((rand() % 1000) < 500 )? 0:1 );
}


Orc::~Orc()
{








}


int Orc::getId()
{
	return m_enemyId;
}

void Orc::computeDamage(Ally *pptr)
#include <cstdlib>
{
	int damage;
	switch (m_weaponType)
	{
	case WeaponType::Sword:
		// write statement here
		damage = 24;
		pptr->m_health -= damage;
		if (pptr->isPlayer())
		{
				std::cout << "You are being attacked for " << damage << "\n\n";
				std::cout << "Your remainding health is" << pptr->m_health << "\n\n";
		
		}

		if (pptr->isPriest())
		{
			std::cout << "Your priest being attacked for " << damage << "\n\n";
			std::cout << "Your priest's remainding health is" << pptr->m_health << "\n\n";
		}
		
		break;
	case WeaponType::Axe:
		damage = 32;
		pptr->m_health -= damage;
		if (pptr->isPlayer())
		{

			std::cout << "You are being attacked for " << damage << "\n\n";
			std::cout << "Your reminding health is" << pptr->m_health << "\n\n";

		}

		if (pptr->isPriest())
		{
			std::cout << "Your priest being attacked for " << damage << "\n\n";
			std::cout << "Your priest's remainding health is" << pptr->m_health << "\n\n";
		}
		
		break;
	
	
	
	default:
		break;
	}
	
}
int Orc::getHealth()
{
	return m_health;
}

//WeaponType Orc::getWeaponType()
//{
//	return m_weaponType;
//}
