#include "Enemy.h"

int g_numEnemies = 0;


Enemy::Enemy()
{
    // Initialize these members to something sensible. Derived
    // classes will override this with their own constructors.
    m_health = 0;
    m_armour = 0;
	m_enemyId = 0;
    g_numEnemies++;
}


Enemy::~Enemy()
{
    g_numEnemies--;
}

int Enemy::getNumEnemies()
{
    return g_numEnemies;
}


