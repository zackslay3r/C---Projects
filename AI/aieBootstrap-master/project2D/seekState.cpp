#include "seekState.h"
#include "PlayLoop.h"
#include "Global.h"


using namespace BehaviourManagement;
seekState::seekState(Enemy * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
}

void seekState::update(float dt)
{
	for (auto &enemys : PLAY->enemies)
	{
		enemys->position.x += 100 * dt;
	}
}

seekState::~seekState()
{
}
