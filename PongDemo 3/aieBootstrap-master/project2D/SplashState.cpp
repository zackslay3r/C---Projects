#include "SplashState.h"
#include <Font.h>
#include "Application2D.h"
#include "Global.h"
#include <Renderer2D.h>
#include "PlayLoop.h"
using namespace StateMangement;
SplashState::SplashState(Application2D * _app, GSM * _gsm) : IState(_app, _gsm) 
{
	m_font = new aie::Font("./font/consolas.ttf", 36);
	switchStateTimer = 0.0f;
	SplashText = "Welcome to Zacks Game! Please press enter to continue!";
	input = aie::Input::getInstance();
}

SplashState::~SplashState()
{
}

void SplashState::update(float dt)
{
	updateStateTimer(dt);
	if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
	{
		app->getGSM()->popState();
		app->getGSM()->pushState(MENU_STATE);
		
	}
}

void SplashState::render()
{
	char buffer[32];
	sprintf_s(buffer, "%2.2f", switchStateTimer);


	PLAY->app->m_2dRenderer->drawText(m_font, buffer, 10, 50);
	PLAY->app->m_2dRenderer->drawText(m_font, "Splash State", 10, 10);
	PLAY->app->m_2dRenderer->drawText(m_font, SplashText, 125, 360);
}

void SplashState::updateStateTimer(float dt)
{
	switchStateTimer += dt;
}
