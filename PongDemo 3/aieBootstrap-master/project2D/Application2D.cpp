#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Global.h"
#include "GameState.h"
#include "LoadingState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "PlayLoop.h"
#include "SplashState.h"

using namespace StateMangement;

Application2D::Application2D() {
	
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	
	PLAY->app = this;
	m_2dRenderer = new aie::Renderer2D();
//	m_playerLeft = new Player();
	// makes the game state manager pointer equal to a new instance of a Game State Manager
	gsm = new GSM();

	// Register the states into the m_registeredStates map. these should be registered based upon the enum value on GameStateID for the id and the state should be based on a new instance of the given state (in this case, LoadState.)
	gsm->registerState(SPLASH_STATE, new SplashState(this, gsm));
	gsm->registerState(LOADING, new LoadState(this,gsm));
	gsm->registerState(GAME_STATE, new GameState(this,gsm));
	gsm->registerState(MENU_STATE, new MenuState(this,gsm));
	gsm->registerState(PAUSE_STATE, new PauseState(this, gsm));
	// Then we want to push the state we want to use as the state we start on. 
	gsm->pushState(SPLASH_STATE);
	
	// and return true. this will then run the program as it has sucessfully initialized. 
	return true;
	
}

void Application2D::shutdown() {
	
	/*delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;*/

	delete gsm;

}

void Application2D::update(float deltaTime) {

	// Update the states
	gsm->updateStates(deltaTime);

}

void Application2D::draw() {
	clearScreen();
	// wipe the screen to the background colour
	m_2dRenderer->begin();
	//Render the states.
	gsm->renderStates();
	m_2dRenderer->end();
}