#include "Human.h"

Human::Human()
{
	input = aie::Input::getInstance();
}

Human::~Human()
{
}

void Human::update(float dt)
{

	//Respond to player input.
	if (input->isKeyDown(upKey))
	{
		moveUp(dt);
	}
	else if (input->isKeyDown(downKey))
	{
		moveDown(dt);
	}
	else 
	{
		moveStop(dt);
	}

}
