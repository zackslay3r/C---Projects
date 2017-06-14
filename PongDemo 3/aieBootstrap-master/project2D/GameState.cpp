#include "GameState.h"

#include "Application2D.h"
#include <string>
#include "Global.h"
#include "PlayLoop.h"
using namespace StateMangement;
GameState::GameState(Application2D *_app, GSM *_gsm) : IState(_app, _gsm)
{
	
}


GameState::~GameState()
{
	
	
}

void GameState::update(float dt)
{
	PLAY->update(dt,gsm);
}

void GameState::render()
{
	PLAY->render();
}



