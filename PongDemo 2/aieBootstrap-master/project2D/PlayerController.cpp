#include "PlayerController.h"
#include <Input.h>
#include "Object.h"


CPlayerController::CPlayerController(Object *_parent) : IComponent(_parent)
{
	m_moveUp = false;
	m_moveDown = false;
	m_speed = 50.0f;
}


CPlayerController::~CPlayerController()
{
}

void CPlayerController::update(float dt)
{
	if (m_moveUp) {
		m_parent->getBounds().y += m_speed;
	}

	if (m_moveDown) {
		m_parent->getBounds().y -= m_speed;
	}
}

void CPlayerController::setControls(aie::EInputCodes upKey, aie::EInputCodes downKey)
{
	m_controls[UP] = upKey;
	m_controls[DOWN] = downKey;

}

void CPlayerController::updateControls(aie::Input *input)
{
	if (input->isKeyDown(m_controls[UP]))
		m_moveUp = true;
	if (input->isKeyDown(m_controls[DOWN]))
		m_moveDown = true;

	if (input->isKeyUp(m_controls[UP]))
		m_moveUp = false;
	if (input->isKeyUp(m_controls[DOWN]))
		m_moveDown = false;
}
