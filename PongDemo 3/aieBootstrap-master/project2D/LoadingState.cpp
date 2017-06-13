#include "LoadingState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "Global.h"

using namespace StateMangement;


LoadState::LoadState(Application2D * _app) : IState(_app) {
	m_renderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 16);
	switchStateTimer = 0.0f;
	loadText = "Loading";
}


LoadState::~LoadState() {
	delete m_renderer;
	delete m_font;
}

void LoadState::update(float deltaTime) {

	updateLoadText(deltaTime);
	updateStateTimer(deltaTime);
}

void LoadState::render(aie::Renderer2D*	m_2dRenderer) {
	char buffer[32];
	sprintf_s(buffer, "%2.2f", switchStateTimer);

	m_renderer->begin();
	m_renderer->drawText(m_font, buffer, 10, 50);
	m_renderer->drawText(m_font, loadText, 10, 10);
	m_renderer->end();
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
	if (switchStateTimer < 5)
	{
		return;
	}

	app->getGSM()->popState();
	app->getGSM()->pushState(GAME_STATE);

}
