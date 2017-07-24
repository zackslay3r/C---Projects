#include "Player.h"
#include "NodeManager.h"

NodeManager nodes;
Player::Player()
{
	position.x = 250.0f;
	position.y = 250.0f;
	input = input = aie::Input::getInstance();
}

void Player::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 255, 51);
	PLAY->app->m_2dRenderer->drawCircle(position.x, position.y, 25);
}

void Player::update(float DT)
{
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		position.y += 5.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		position.y -= 5.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		position.x -= 5.0f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		position.x += 5.0f;
	}
}

Player::~Player()
{
}
