#include "GameStateManager.h"
#include "State.h"
#include "MenuMainState.h"
#include "DrawPlayState.h"
#include "UpdatePlayState.h"

GameStateManager::GameStateManager()
{
	availableStates = ContLib::BinarySearchTree<std::string, State *>();

	activeStates = ContLib::LinkedList<State *>();

    //Register all required states.

    State *pState;

    pState = new UpdatePlayState;
    availableStates.insert(pState->getName(), pState);

    pState = new DrawPlayState;
    availableStates.insert(pState->getName(), pState);

    pState = new MenuMainState;
    availableStates.insert(pState->getName(), pState);

    //Push default state "MenuMainState" on startup.
    activeStates.push_front(pState);

}

GameStateManager::~GameStateManager()
{
}

GameStateManager *GameStateManager::getInstance()
{
    static GameStateManager gameStateManager;

    return &gameStateManager;
}

void GameStateManager::activateState(std::string stateName)
{
	//Skip if state already active.
	for (auto &state : activeStates)
	{
		if (state->getName() == stateName) return;
	}

	//Check state is in list of available registered states.
	if (!availableStates.count(stateName)) throw;

	activeStates.push_front(availableStates[stateName]);

	//Execute enter function for state.
	availableStates[stateName]->enter();
}

void GameStateManager::removeState(std::string stateName)
{

	//Hunt for the state by name in the active states list.
	ContLib::LinkedListIterator<State *> state;
	for (state = activeStates.begin(); state != activeStates.end(); state++)
	{
		if ((*state)->getName() == stateName)
		{
			break;
		}
	}

	//If we found the state in the list, remove it.
	if (state != activeStates.end())
	{
		//Execute leave function for state.
		(*state)->leave();
		activeStates.erase(state);
	}

}