#include "PlayLoop.h"
#include "Application2D.h"
#include "GSM.h"
#include "Global.h"
#include <string>
#include "Factory.h"

using namespace StateMangement;
playLoop::playLoop()
{

	// These are the two seperate fonts that are used in my game. one for the scores and one for stating the play state.
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 32));
	m_stateFont = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 16));
	
	// This will fill the stack with objects, hence using an object pool.
	Factory::fillBallPool(5);
	Factory::fillPaddlePool(5);
	
	// This will create a paddle as though it is from the factory, however, in the factory it will first check if items are in the object pool,
	// and then get the factory to create items if the pool is empty. hence using facade as well as factory.
	paddleLeft = Factory::makePaddle(50, 250);
	paddleRight = Factory::makePaddle(1230, 250);
	Ball = Factory::makeBall(360, 640);
	// This is used to recieve the input of the players.
	input = aie::Input::getInstance();
	// These are the two scores of the two players that are defaulted to 0.
	ScoreOne = 0;
	ScoreTwo = 0;
	// This is the text displayed when a player wins the game.
	playerWinnerText = " ";
}
playLoop::~playLoop()
{
	// These will ensure that the items get deleted properly.
	delete paddleLeft;
	delete paddleRight;
	delete Ball;
}

playLoop * playLoop::getInstance()
{
	// This will make playloop a singleton, as we only want one play loop in our game.
	static playLoop playloop;
	return &playloop;
}

void playLoop::update(float dt, GSM* gsm)
{
	// This will update the state timer based on DT.
	updateStateTimer(dt);
	
	// This will track player 1's input and move the paddle accordingly.
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		paddleLeft->posY += 200 * dt;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		paddleLeft->posY -= 200 * dt;
	}
	// This will track player 2's input and move the paddle accordingly.
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		paddleRight->posY += 200 * dt;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		paddleRight->posY -= 200 * dt;
	}

	// If player one tried to move out of the bounds of the top or bottom of the screen, send them back.
	if (paddleLeft->posY > 570)
	{
		paddleLeft->posY = 570;
	}
	if (paddleLeft->posY < 150)
	{
		paddleLeft->posY = 150;
	}
	// If player two tried to move out of the bounds of the top or bottom of the screen, send them back.
	if (paddleRight->posY > 570)
	{
		paddleRight->posY = 570;
	}
	if (paddleRight->posY < 150)
	{
		paddleRight->posY = 150;
	}
	// Set the balls movement to be of the balls velocity.
	Ball->posX += Ball->velocityX * dt;
	Ball->posY += Ball->velocityY * dt;
	
	// If it bounces off the top and bottom wall, reflect it back at 45 degrees.
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

	// If the ball goes past player ones paddle, give player two a point and reset the ball.
	if (Ball->posX < 0)
	{
		ScoreTwo++;
		Ball->posX = app->getWindowHeight() / 2;
		Ball->posY = app->getWindowWidth() / 2;
		Ball->velocityY = -Ball->velocityY;
	}

	// If the ball goes past player twos paddle, give player one a point and reset the ball.
	if (Ball->posX > app->getWindowWidth())
	{
		ScoreOne++;
		Ball->posX = app->getWindowHeight() / 2;
		Ball->posY = app->getWindowWidth() / 2;
		Ball->velocityY = -Ball->velocityY;
		
	}
	
	//Check if the ball collides with the left paddle and if it does, reflect it off at 45 degrees.
	if (checkCollide(paddleLeft->posX, paddleLeft->posY, paddleLeft->width, paddleLeft->height, Ball->posX, Ball->posY, Ball->width, Ball->height) == true)
	{
		Ball->velocityX = -Ball->velocityX;



	}
	//Check if the ball collides with the right paddle and if it does, reflect it off at 45 degrees.
	if (checkCollide(paddleRight->posX, paddleRight->posY, paddleRight->width, paddleRight->height, Ball->posX, Ball->posY, Ball->width, Ball->height) == true)
	{
		Ball->velocityX = -Ball->velocityX;


	}
	// If P was pressed, pause the game.
	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		gsm->popState();
		gsm->pushState(PAUSE_STATE);
	}

	// If player ones score is => 5, say that player One has one and after 3 seconds, reset everything and default it to the main menu.
	if (ScoreOne >= 5)
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
			
			paddleLeft->posX = 50;
			paddleLeft->posY = 250;

			paddleRight->posX = 1230;
			paddleRight->posY = 250;

			Ball->posX = 360;
			Ball->posY = 640;

		}
	}
	// If player Two's score is => 5, say that player two has one and after 3 seconds, reset everything and default it to the main menu.
	if (ScoreTwo >= 5)
	{
		winnerTimer = 0.0f;
		playerWinnerText = "Player Two Wins!";
		static float updateClock;
		updateClock += dt;
		if (updateClock >= 3.0f)
		{
			gsm->popState();
			gsm->pushState(MENU_STATE);
			ScoreOne = ScoreTwo = 0;
			updateClock = 0.0f;
			playerWinnerText = " ";

			paddleLeft->posX = 50;
			paddleLeft->posY = 250;

			paddleRight->posX = 1230;
			paddleRight->posY = 250;

			Ball->posX = 360;
			Ball->posY = 640;
		}
	}
}



void playLoop::render()
{
	// Convert the ints to strings.
	std::string scoreoneString = std::to_string(ScoreOne);
	std::string scoretwoString = std::to_string(ScoreTwo);
	
	// The state text and the timer.
	char buffer[32];
	sprintf_s(buffer, "%2.2f", switchStateTimer);
	PLAY->app->m_2dRenderer->drawText(m_stateFont.get(), buffer, 10, 50);
	PLAY->app->m_2dRenderer->drawText(m_stateFont.get(), "Game State", 10, 10);

	// The Score's of player one and two.
	PLAY->app->m_2dRenderer->drawText(m_font.get(), scoreoneString.c_str(), 60, 650);
	PLAY->app->m_2dRenderer->drawText(m_font.get(), scoretwoString.c_str(), 1200, 650);
	// The winner text.
	PLAY->app->m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f);
	PLAY->app->m_2dRenderer->drawText(m_font.get(), playerWinnerText, 360, 640);
	// The paddles and the ball.
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
