#pragma once
#include "GameState.h"

#define PLAY playLoop::getInstance()

class playLoop
{
public:
	static playLoop *getInstance();
	
	Application2D *app;
	void update(float dt, GSM* gsm);
	void render();
private:
	playLoop();
	~playLoop();
	std::unique_ptr<aie::Font> m_font;
	bool checkCollide(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
	int ScoreOne, ScoreTwo;
	Object* paddleLeft;
	Object* paddleRight;
	Object* Ball;
	aie::Input *input;
};