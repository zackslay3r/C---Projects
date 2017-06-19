#include "MenuState.h"
#include <Renderer2D.h>
#include "GSM.h"
#include "Application2D.h"
#include "Global.h"
#include "PlayLoop.h"

using namespace StateMangement;
MenuState::MenuState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm)
{
	
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));
	WhatsSelected = 0;
	maxMenuOption = 1;
	input = aie::Input::getInstance();
	switchStateTimer = 0.0f;

}


MenuState::~MenuState()
{
}

void MenuState::update(float dt)
{
	updateStateTimer(dt);
	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
	{
		WhatsSelected++;
		if (WhatsSelected > maxMenuOption) WhatsSelected = maxMenuOption;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_UP))
	{
		WhatsSelected--;
		if (WhatsSelected < 0) WhatsSelected = 0;
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
	{
		if (WhatsSelected == 0) 
		{
			gsm->popState();
			gsm->pushState(LOADING);
		};
		if (WhatsSelected == 1)
		{
			app->quit();

		}
	
		
		
	}
}

void MenuState::render()
{
	char buffer[32];
	sprintf_s(buffer, "%2.2f", switchStateTimer);


	PLAY->app->m_2dRenderer->drawText(m_font.get(), buffer, 10, 50);
	PLAY->app->m_2dRenderer->drawText(m_font.get(), "Menu State", 10, 10);

	
	PLAY->app->m_2dRenderer->setRenderColour(0.1f, 0.1f, 0.1f, 1.0f);
	PLAY->app->m_2dRenderer->drawBox(590, 520, 300, 60);

	PLAY->app->m_2dRenderer->setRenderColour(0.5f, 0.5f, 0.5f, 1.0f);
	PLAY->app->m_2dRenderer->drawText(m_font.get(), "Zack's Game", 500, 500);
	if (WhatsSelected == 0)
	{
		PLAY->app->m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);
		
	}
	else
	{
		PLAY->app->m_2dRenderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	PLAY->app->m_2dRenderer->drawText(m_font.get(), "Play Game", 500, 400);

	if (WhatsSelected == 1)
	{
		PLAY->app->m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);

	}
	else
	{
		PLAY->app->m_2dRenderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	PLAY->app->m_2dRenderer->drawText(m_font.get(), "Quit", 500, 350);
	



}

void MenuState::updateStateTimer(float dt)
{
	switchStateTimer += dt;
}

