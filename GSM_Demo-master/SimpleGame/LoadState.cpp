#include "LoadState.h"
#include <Renderer2D.h>
#include <Font.h>


LoadState::LoadState() {
	m_renderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 16);

	loadText = "Loading";
}


LoadState::~LoadState() {
	delete m_renderer;
	delete m_font;
}

void LoadState::update(float deltaTime) {
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

void LoadState::render() {
	m_renderer->begin();
	m_renderer->drawText(m_font, loadText, 10, 10);
	m_renderer->end();
}
