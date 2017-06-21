#include "PauseState.h"
#include "Renderer2D.h"
#include "Application2D.h"
#include "PlayLoop.h"
#include "Global.h"
#include "Factory.h"
using namespace StateMangement;

PauseState::PauseState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm)
{

	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));

	input = aie::Input::getInstance();
}


PauseState::~PauseState()
{


}

void PauseState::update(float dt)
{
	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		gsm->popState();
		gsm->pushState(GAME_STATE);
	}

}

void PauseState::render()
{
	PLAY->app->m_2dRenderer->drawText(m_font.get(), "Paused!", 580, 360);
	PLAY->render();

}