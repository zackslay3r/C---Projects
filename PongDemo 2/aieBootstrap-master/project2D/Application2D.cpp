#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Global.h"
#include "GameState.h"
#include "LoadingState.h"

using namespace StateMangement;

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	
	
	
	// makes the game state manager pointer equal to a new instance of a Game State Manager
	gsm = new GSM();

	// Register the states into the m_registeredStates map. these should be registered based upon the enum value on GameStateID for the id and the state should be based on a new instance of the given state (in this case, LoadState.)
	gsm->registerState(LOADING, new LoadState(this));
	gsm->registerState(GAME_STATE, new GameState(this));
	// Then we want to push the state we want to use as the state we start on. 
	gsm->pushState(LOADING);

	// and return true. this will then run the program as it has sucessfully initialized. 
	return true;
}

void Application2D::shutdown() {
	
	/*delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;*/
}

void Application2D::update(float deltaTime) {

	//m_timer += deltaTime;

	//// input example
	//aie::Input* input = aie::Input::getInstance();

	//// use arrow keys to move camera
	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//	m_cameraY += 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//	m_cameraY -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	//	m_cameraX -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//	m_cameraX += 500.0f * deltaTime;

	//// example of audio
	//if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	//	m_audio->play();

	//// exit the application
	//if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	//	quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	//// begin drawing sprites
	//m_2dRenderer->begin();

	//// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	//
	//// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	//// done drawing sprites
	/*m_2dRenderer->end();*/
}