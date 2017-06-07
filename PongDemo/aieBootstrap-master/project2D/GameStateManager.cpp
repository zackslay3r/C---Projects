#include "GameStateManager.h"
#include <Renderer2D.h>
#include <assert.h>
#include "IGameState.h"

GameStateManager::GameStateManager() {
}


GameStateManager::~GameStateManager() {
	for (auto iter = m_registeredStates.begin(); iter != m_registeredStates.end(); iter++)
		delete iter->second;
	m_registeredStates.clear();
}

void GameStateManager::updateStates(float dt) {
	processCommands();

	for (auto iter = myStates.begin(); iter != myStates.end(); iter++)
		(*iter)->update(dt);
}

void GameStateManager::renderStates(aie::Renderer2D * renderer) {
	for (auto iter = myStates.begin(); iter != myStates.end(); iter++)
		(*iter)->render(renderer);
}

void GameStateManager::setState(int ID, IGameState * state) {
	Command cmd;
	cmd.cmd = ECommand::SET;
	cmd.ID = ID;
	cmd.pState = state;

	m_commands.pushFront(cmd);
}

void GameStateManager::pushState(int ID) {
	Command cmd;
	cmd.cmd = ECommand::PUSH;
	cmd.ID = ID;
	cmd.pState = nullptr;

	m_commands.pushFront(cmd);
}

void GameStateManager::popState() {
	Command cmd;
	cmd.cmd = ECommand::POP;
	cmd.ID = -1;
	cmd.pState = nullptr;

	m_commands.pushFront(cmd);
}

IGameState * GameStateManager::getTopState() {
	if (myStates.ListLength > 0)
		return myStates.end();

	return nullptr;
}

void GameStateManager::processCommands() {
	for (auto iter = m_commands.begin(); iter != m_commands.end(); iter++) {
		Command &cmd = (*iter);
		switch (cmd.cmd) {
		case ECommand::SET:
			processSetState(cmd.ID, cmd.pState);
			break;
		case ECommand::PUSH:
			processPushState(cmd.ID);
			break;
		case ECommand::POP:
			processPopState();
			break;
		}
	}
	m_commands.deleteList();
}

void GameStateManager::processSetState(int ID, IGameState * state) {
	auto iter = m_registeredStates.find(ID);
	if (iter != m_registeredStates.end()) {
		// Erase the old state if it already exists
		delete iter->second;
	}
	m_registeredStates[ID] = state;
}

void GameStateManager::processPushState(int ID) {
	auto iter = m_registeredStates.find(ID);
	if (iter != m_registeredStates.end()) {
		// Push the state back onto the stack
		myStates.pushFront(iter->second);
	}
	else {
		assert(ID && "State ID not found");
	}
}

void GameStateManager::processPopState() {
	if (myStates.listLength > 0)
		myStates.popFront();
}