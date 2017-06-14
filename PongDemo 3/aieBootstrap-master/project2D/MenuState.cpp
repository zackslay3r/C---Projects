#include "MenuState.h"
#include <Renderer2D.h>
#include "GSM.h"
#include "Application2D.h"
#include "Global.h"

using namespace StateMangement;
MenuState::MenuState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm)
{
	m_renderer = new aie::Renderer2D();
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));
	WhatsSelected = 0;
	maxMenuOption = 1;
	input = aie::Input::getInstance();

}


MenuState::~MenuState()
{
}

void MenuState::update(float dt)
{

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
			gsm->pushState(GAME_STATE);
		};
		if (WhatsSelected == 1)
		{
			app->quit();

		}
	
		
		
	}
}

void MenuState::render(aie::Renderer2D*	m_2dRenderer)
{
	
	m_renderer->begin();
	m_renderer->setRenderColour(0.1f, 0.1f, 0.1f, 1.0f);
	m_renderer->drawBox(590, 520, 300, 60);

	m_renderer->setRenderColour(0.5f, 0.5f, 0.5f, 1.0f);
	m_renderer->drawText(m_font.get(), "Zack's Game", 500, 500);
	if (WhatsSelected == 0)
	{
		m_renderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);
		
	}
	else
	{
		m_renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	m_renderer->drawText(m_font.get(), "Play Game", 500, 400);

	if (WhatsSelected == 1)
	{
		m_renderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);

	}
	else
	{
		m_renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	m_renderer->drawText(m_font.get(), "Quit", 500, 350);
	
	
	m_renderer->end();


}

