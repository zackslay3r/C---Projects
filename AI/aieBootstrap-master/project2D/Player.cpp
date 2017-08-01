#include "Player.h"
#include "NodeManager.h"
#include <list>
NodeManager nodes;
Player::Player()
{
	position.x = 0.0f;
	position.y = 0.0f;
	scale.x = 25.0f;
	scale.y = 25.0f;
	input = aie::Input::getInstance();
}

Player::Player(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	scale.x = 25.0f;
	scale.y = 25.0f;
	input = input = aie::Input::getInstance();

}


void Player::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 255, 51);
	PLAY->app->m_2dRenderer->drawBox(position.x, position.y, scale.x, scale.y);
}

void Player::update(float DT)
{
	if (velocity.x > 100.0f)
	{
		velocity.x = 100.0f;
	}
	if (velocity.y > 100.0f)
	{
		velocity.y = 100.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		velocity.y += 2.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		velocity.y -= 2.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		velocity.x -= 2.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		velocity.x += 2.0f;
	}
	
	
	
	position += velocity * DT;
}

//bool Player::checkCollide(Vector2 shape1Pos, Vector2 shape1Scale, Vector2 shape2Pos, Vector2 shape2Scale)
//{
//	float x1Min = shape1Pos.x - shape1Scale.x / 2.0f;
//	float x1Max = shape1Pos.x + shape1Scale.x / 2.0f;
//	float y1Min = shape1Pos.y - shape1Scale.y / 2.0f;
//	float y1Max = shape1Pos.y - shape1Scale.y / 2.0f;
//
//
//	float x2Min = shape2Pos.x - shape2Scale.x / 2.0f;
//	float x2Max = shape2Pos.x + shape2Scale.x / 2.0f;
//	float y2Min = shape2Pos.y - shape2Scale.y / 2.0f;
//	float y2Max = shape2Pos.y - shape2Scale.y / 2.0f;
//
//	if (x1Max < x2Min || x1Min > x2Max) return false;
//	if (y1Max < y2Min || y1Min > y2Max) return false;
//
//	return true;
//}

Player::~Player()
{
}


