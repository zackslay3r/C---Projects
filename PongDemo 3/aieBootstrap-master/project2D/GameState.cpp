#include "GameState.h"
#include <Renderer2D.h>



GameState::GameState(Application2D * _app) : IState(_app)
{
	m_renderer = new aie::Renderer2D();
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));

}


GameState::~GameState()
{
}

void GameState::update(float dt)
{
}

void GameState::render(aie::Renderer2D*	m_2dRenderer)
{
	m_renderer->begin();
	m_renderer->drawText(m_font.get(), "Game State", 300, 300);
	m_renderer->drawBox(300, 300, 5, 250);
	m_renderer->end();


}