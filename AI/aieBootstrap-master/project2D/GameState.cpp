#include "GameState.h"

#include "Application2D.h"
#include <string>
#include "Global.h"
#include "PlayLoop.h"
using namespace StateMangement;
// Gamestate constructor
GameState::GameState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm)
{
	
}

//Gamestate destructor
GameState::~GameState()
{
	
	
}

// The gamestate and render functions run the playloop.

// The GameState update function.
void GameState::update(float dt)
{
	
	PLAY->update(dt,gsm);
	
	
}

//the gamestate render function.
void GameState::render()
{	
	
	
	
	PLAY->render();
}





