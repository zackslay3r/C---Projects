#include "PauseState.h"
#include "Renderer2D.h"
#include "Application2D.h"
#include "PlayLoop.h"
#include "Global.h"
using namespace StateMangement;

PauseState::PauseState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm)
{

	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));
	paddleLeft = new Object(50, 250, 5, 300,0,0);
	paddleRight = new Object(1230, 250, 5, 300,0,0);
	Ball = new Object((float)app->getWindowWidth() / 2, (float)app->getWindowHeight() / 2, 20, 20, 200, 200);
	input = aie::Input::getInstance();
}


PauseState::~PauseState()
{

	delete paddleLeft;
	delete paddleRight;
	delete Ball;
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
	PLAY->app->m_2dRenderer->drawText(m_font.get(), "Zack's Game", PLAY->app->getWindowWidth() / 2, PLAY->app->getWindowHeight() / 2);
	PLAY->render();

}