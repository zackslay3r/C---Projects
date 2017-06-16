#include "PlayLoop.h"
#include "Application2D.h"
#include "GSM.h"
#include "Global.h"
#include <string>
#include "Factory.h"
using namespace StateMangement;
playLoop::playLoop()
{

	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));
	m_stateFont = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 16));
	/*paddleLeft = new Object(50, 250, 5, 300, 0,0);
	paddleRight = new Object(1230, 250, 5, 300, 0, 0);
	Ball = new Object(360, 640, 20, 20, 200, 200);*/
	paddleLeft = Factory::makePaddle(50, 250);
	paddleRight = Factory::makePaddle(1230, 250);
	Ball = Factory::makeBall(360, 640);
	input = aie::Input::getInstance();
	ScoreOne = 0;
	ScoreTwo = 0;
	playerWinnerText = " ";
}
playLoop::~playLoop()
{
	delete paddleLeft;
	delete paddleRight;
	delete Ball;
}

playLoop * playLoop::getInstance()
{
	static playLoop playloop;

	return &playloop;
}

void playLoop::update(float dt, GSM* gsm)
{
	
	updateStateTimer(dt);
	
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		paddleLeft->posY += 100 * dt;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		paddleLeft->posY -= 100 * dt;
	}
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		paddleRight->posY += 100 * dt;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		paddleRight->posY -= 100 * dt;
	}

	if (paddleLeft->posY > 570)
	{
		paddleLeft->posY = 570;
	}
	if (paddleLeft->posY < 150)
	{
		paddleLeft->posY = 150;
	}

	if (paddleRight->posY > 570)
	{
		paddleRight->posY = 570;
	}
	if (paddleRight->posY < 150)
	{
		paddleRight->posY = 150;
	}
	Ball->posX += Ball->velocityX * dt;
	Ball->posY += Ball->velocityY * dt;
	if (Ball->posY + 10 > app->getWindowHeight())
	{
		Ball->velocityY = -Ball->velocityY;
		Ball->posY = app->getWindowHeight() - 10;
	}
	if (Ball->posY - 10 < 0)
	{
		Ball->velocityY = -Ball->velocityY;
		Ball->posY = 10;
	}

	if (Ball->posX < 0)
	{
		ScoreTwo++;
		Ball->posX = app->getWindowHeight() / 2;
		Ball->posY = app->getWindowWidth() / 2;
	}
	if (Ball->posX > app->getWindowWidth())
	{
		ScoreOne++;
		Ball->posX = app->getWindowHeight() / 2;
		Ball->posY = app->getWindowWidth() / 2;
	}

	if (checkCollide(paddleLeft->posX, paddleLeft->posY, paddleLeft->width, paddleLeft->height, Ball->posX, Ball->posY, Ball->width, Ball->height) == true)
	{
		Ball->velocityX = -Ball->velocityX;



	}

	if (checkCollide(paddleRight->posX, paddleRight->posY, paddleRight->width, paddleRight->height, Ball->posX, Ball->posY, Ball->width, Ball->height) == true)
	{
		Ball->velocityX = -Ball->velocityX;


	}
	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		gsm->popState();
		gsm->pushState(PAUSE_STATE);
	}

	if (ScoreOne == 5)
	{
		winnerTimer = 0.0f;
		playerWinnerText = "Player One Wins!";
		static float updateClock;
		updateClock += dt;

		if (updateClock >= 3.0f)
		{
			gsm->popState();
			gsm->pushState(MENU_STATE);
			ScoreOne = ScoreTwo = 0;
			updateClock = 0.0f;
			playerWinnerText = " ";
		}
	}

	if (ScoreTwo == 5)
	{
		winnerTimer = 0.0f;
		playerWinnerText = "Player Two Wins!";
		static float updateClock;
		updateClock += dt;
		if (updateClock >= 3.0f)
		{
			gsm->popState();
			gsm->pushState(MENU_STATE);
			//gsm->registerState(GAME_STATE, new GameState(, gsm));
			ScoreOne = ScoreTwo = 0;
			updateClock = 0.0f;
			playerWinnerText = " ";
		}
	}
}



void playLoop::render()
{
	std::string scoreoneString = std::to_string(ScoreOne);
	std::string scoretwoString = std::to_string(ScoreTwo);
	
	char buffer[32];
	sprintf_s(buffer, "%2.2f", switchStateTimer);
	PLAY->app->m_2dRenderer->drawText(m_stateFont.get(), buffer, 10, 50);
	PLAY->app->m_2dRenderer->drawText(m_stateFont.get(), "Game State", 10, 10);


	PLAY->app->m_2dRenderer->drawText(m_font.get(), scoreoneString.c_str(), 60, 650);
	PLAY->app->m_2dRenderer->drawText(m_font.get(), scoretwoString.c_str(), 1200, 650);
	PLAY->app->m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f);
	PLAY->app->m_2dRenderer->drawText(m_font.get(), playerWinnerText, 360, 640);
	PLAY->app->m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	paddleLeft->Draw();
	paddleRight->Draw();
	Ball->Draw();



}
bool playLoop::checkCollide(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2)
{
	int x1Min = x1 - width1 / 2;
	int x1Max = x1 + width1 / 2;
	int y1Max = y1 + height1 / 2;
	int y1Min = y1 - height1 / 2;

	// AABB 2
	int x2Min = x2 - width2 / 2;
	int x2Max = x2 + width2 / 2;
	int y2Max = y2 + height2 / 2;
	int y2Min = y2 - height2 / 2;

	if (x1Max < x2Min || x1Min > x2Max) return false;
	if (y1Max < y2Min || y1Min > y2Max) return false;

	return true;
}

void playLoop::updateStateTimer(float dt)
{
	switchStateTimer += dt;
}
