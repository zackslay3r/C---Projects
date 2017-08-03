#include "fleeState.h"
#include "PlayLoop.h"




fleeState::fleeState(Enemy * _ploop, gameFSM * _gamefsm): IGameState(_ploop, _gamefsm)
{
	
}

void fleeState::update(float dt)
{
	for (auto &enemys : PLAY->enemies)
	{
		enemys->changeToFlee(enemys);
	}
}

fleeState::~fleeState()
{
}
