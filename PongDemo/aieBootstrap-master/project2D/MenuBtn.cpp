#include "MenuBtn.h"
#include <Renderer2D.h>
#include <Font.h>
#include <Texture.h>
#include <Input.h>
#include "ResourceManager.h"

MenuBtn::MenuBtn() {
}

MenuBtn::MenuBtn(const char * labelText, std::function<void()> link,
	float x, float y, aie::Texture * tex)
	: m_labelText(labelText), onClick(link), m_tex(tex) {
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	if (tex != nullptr)
		m_bounds = menuRect{ x, y, (float)tex->getWidth(), (float)tex->getHeight() };
	else
		m_bounds = menuRect{ x, y, (float)m_font->getStringWidth(labelText) + xBorderPadding * 2, 
								(float)m_font->getStringHeight(labelText) + yBorderPadding * 2 };
}

MenuBtn::~MenuBtn() {
}

void MenuBtn::render(aie::Renderer2D * renderer) {
	Point mousePos;
	aie::Input* input = aie::Input::getInstance();
	input->getMouseXY(&mousePos.x, &mousePos.y);

	
	if (m_tex != nullptr) {
		renderer->setUVRect(0, 0, 1, 1);
		renderer->drawSprite(m_tex, m_bounds.x, m_bounds.y, m_bounds.width, m_bounds.height);
	} else {
		// Top
		renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y + m_bounds.height / 2, 
			m_bounds.x + m_bounds.width / 2, m_bounds.y + m_bounds.height / 2);
		// Left
		renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
			m_bounds.x - m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
		// Right
		renderer->drawLine(m_bounds.x + m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
			m_bounds.x + m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
		// Bottom
		renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y - m_bounds.height / 2,
			m_bounds.x + m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
	}
	renderer->drawText(m_font.get(), &m_labelText[0u],
		m_bounds.x - m_font->getStringWidth(&m_labelText[0u]) / 2, m_bounds.y - m_font->getStringHeight(&m_labelText[0u]) / 2);
	
}

bool MenuBtn::hasFocus(Point mousePos) {
	return m_bounds.contains(mousePos);
}

menuRect MenuBtn::getBounds() {
	return m_bounds;
}


