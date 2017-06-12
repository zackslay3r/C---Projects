#include "SimpleGameApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "global.h"
#include "LoadState.h"
#include "GameState.h"

using namespace StateManagement;

SimpleGameApp::SimpleGameApp() {

}

SimpleGameApp::~SimpleGameApp() {

}

bool SimpleGameApp::startup() {
	
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

void SimpleGameApp::shutdown() {

	// when the app shuts down, delete the Game State Manager.
	delete gsm;
}

void SimpleGameApp::update(float deltaTime) {

	// when we run update, we want to update the states that are registered or are in use based on delta time. 
	gsm->updateStates(deltaTime);
}

void SimpleGameApp::draw() {
	// and when we draw/render to the screeen, we want to do it based on the states that are currently in use though our GSM.

	clearScreen();

	gsm->renderStates();

}