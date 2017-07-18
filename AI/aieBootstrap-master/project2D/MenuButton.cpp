//#include "MenuButton.h"
//#include <memory>
//#include <Input.h>
//#include "Font.h"
//#include <Renderer2D.h>
//
//
//MenuButton::MenuButton(const char * labelName, std::function<void()> onClickCallBk, float x, float y, Colour col) : m_labelName(labelName), onClick(onClickCallBk) , m_colour(col)
//{
//	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));
//	m_bounds = boxRec{ x, y, (float)m_font->getStringWidth(labelName) + xBorderPadding * 2,
//		(float)m_font->getStringHeight(labelName) + yBorderPadding * 2 };
//}
//
//MenuButton::~MenuButton()
//{
//}
//
//void MenuButton::render(aie::Renderer2D * renderer)
//{
//	MousePoint mousePos;
//	aie::Input* input = aie::Input::getInstance();
//	input->getMouseXY(&mousePos.x, &mousePos.y);
//	renderer->setRenderColour((hasFocus(mousePos)) ? m_colour.darken() : m_colour);
//
//	 Top of the box
//	renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
//		m_bounds.x + m_bounds.width / 2, m_bounds.y + m_bounds.height / 2);
//	 Left of the box
//	renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
//		m_bounds.x - m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
//	 Right of the box
//	renderer->drawLine(m_bounds.x + m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
//		m_bounds.x + m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
//	 Bottom of the box
//	renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y - m_bounds.height / 2,
//		m_bounds.x + m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
//	
//	renderer->drawText(m_font.get(), &m_labelName[0u],
//		m_bounds.x - m_font->getStringWidth(&m_labelName[0u]) / 2, m_bounds.y - m_font->getStringHeight(&m_labelName[0u]) / 2);
//	renderer->setRenderColour(0xffffffff);
//
//}
//
//bool MenuButton::hasFocus(MousePoint mousePosition)
//{
//	return m_bounds.contains(mousePosition);
//
//}
//
//boxRec MenuButton::getBounds()
//{
//	return m_bounds;
//}
//
//void MenuButton::setColour(Colour c)
//{
//	m_colour = c;
//}
//

