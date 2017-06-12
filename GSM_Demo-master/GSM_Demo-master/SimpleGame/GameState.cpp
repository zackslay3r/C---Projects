#include "GameState.h"
#include <Renderer2D.h>



GameState::GameState(SimpleGameApp * _app) : IGameState(_app) 
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

void GameState::render()
{
	m_renderer->begin();
	m_renderer->drawText(m_font.get(), "Game State", 300,300);
	m_renderer->end();

}
