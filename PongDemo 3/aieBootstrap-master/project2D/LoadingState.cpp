#include "LoadingState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "Global.h"
#include "PlayLoop.h"

using namespace StateMangement;


LoadState::LoadState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm) {
	
	m_font = new aie::Font("./font/consolas.ttf", 16);
	m_instructFont = new aie::Font("./font/consolas.ttf", 22);
	switchStateTimer = 0.0f;
	loadText = "Loading";
	playerControls = "Left Player = W for Up, S for Down, Right Player = Up Key for Up, Down Key for down. First to 5 Wins!";
}


LoadState::~LoadState() {

	delete m_font;
	delete m_instructFont;
}

void LoadState::update(float deltaTime) {

	updateLoadText(deltaTime);
	updateStateTimer(deltaTime);
}

void LoadState::render() {
	char buffer[32];
	sprintf_s(buffer, "%2.2f", switchStateTimer);

	
	PLAY->app->m_2dRenderer->drawText(m_font, buffer, 10, 50);
	PLAY->app->m_2dRenderer->drawText(m_font, loadText, 10, 10);
	PLAY->app->m_2dRenderer->drawText(m_instructFont, playerControls, 0, 360);
	
}

void LoadState::updateLoadText(float deltaTime)
{
	static float updateClock;
	static int checkNum;
	updateClock += deltaTime;


	if (updateClock < delayTime) return;

	switch (checkNum) {
	case 0:
		loadText = "Loading";
		break;
	case 1:
		loadText = "Loading .";
		break;
	case 2:
		loadText = "Loading . .";
		break;
	case 3:
		loadText = "Loading . . .";
		checkNum = -1;
		break;
	}
	checkNum++;
	updateClock = 0;
}

void LoadState::updateStateTimer(float deltaTime)
{
	switchStateTimer += deltaTime;

	if (switchStateTimer >= 5)
	{
		//return;
	app->getGSM()->popState();
	app->getGSM()->pushState(GAME_STATE);
	}

	


}
