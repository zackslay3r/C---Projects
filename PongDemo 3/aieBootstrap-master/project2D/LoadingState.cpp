#include "LoadingState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "Global.h"
#include "PlayLoop.h"

using namespace StateMangement;


LoadState::LoadState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm) {
	
	m_font = new aie::Font("./font/consolas.ttf", 16);
	switchStateTimer = 0.0f;
	loadText = "Loading";
}


LoadState::~LoadState() {

	delete m_font;
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
	//change back to 5
	if (switchStateTimer < 1)
	{
		return;
	}

	app->getGSM()->popState();
	app->getGSM()->pushState(MENU_STATE);


}
