#include "SplashState.h"
#include <Font.h>
#include "Application2D.h"
#include "Global.h"
#include <Renderer2D.h>
#include "PlayLoop.h"
using namespace StateMangement;
SplashState::SplashState(Application2D * _app, GSM * _gsm) : IState(_app, _gsm) 
{
	//This will use one font.
	m_font = new aie::Font("./font/consolas.ttf", 36);
	// THis is the timer for saying how long you have been in the state for.
	switchStateTimer = 0.0f;
	// The welcoming text.
	SplashText = "Welcome to Zacks Game! Please press enter to continue!";
	// And the variable that allows for input.
	input = aie::Input::getInstance();
}

SplashState::~SplashState()
{
}

void SplashState::update(float dt)
{
	// Updates the timer by dt.
	updateStateTimer(dt);
	// if Enter was pressed, pop the splash state and push the Menu state into the active states.

	if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
	{
		app->getGSM()->popState();
		try
		{
			app->getGSM()->pushState(MENU_STATE);
		}
		catch (...)
		{
			eTHROW("You tried to push Menu state which doesnt exist.");
		}
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
