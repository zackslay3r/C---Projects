#include <StateMachine\SplashState.h>
#include <Renderer2D.h>
#include <StateMachine\ResourceManager\ResourceManager.h>



SplashState::SplashState(StateDemoApp *_app) : IGameState(_app) 
{
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
}


SplashState::~SplashState()
{
}

void SplashState::update(float dt)
{
}

void SplashState::render(aie::Renderer2D *renderer)
{
	renderer->drawText(m_font.get(), "Splash State", 10, 10);
}
