#include "Enemy.h"
#include "Seek.h"


Enemy::Enemy()
{
	position.x = 0.0f;
	position.y = 0.0f;
	scale.x = 25.0f;
	scale.y = 25.0f;
}

Enemy::Enemy(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	scale.x = 25.0f;
	scale.y = 25.0f;
	//velocity = { 50.0f,50.0f };
}


Enemy::~Enemy()
{
}

void Enemy::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 0, 0);
	PLAY->app->m_2dRenderer->drawBox(position.x, position.y, scale.x, scale.y);
}

void Enemy::update(float dt)
{
	for (auto &behaviours : m_behaviours)
	{
		behaviours->Update(dt);
	}
		position += velocity * dt;
}

void Enemy::changeToSeek(Object * target)
{

}
