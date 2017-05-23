#include <StateMachine\GameStateManager.h>
#include <StateMachine\IGameState.h>
#include <assert.h>


GameStateManager::GameStateManager()
{
}


GameStateManager::~GameStateManager()
{
	for (auto iter = m_registeredStates.begin(); iter != m_registeredStates.end(); iter++)
	{
		delete iter->second;
	}
	m_registeredStates.clear();
}

void GameStateManager::updateStates(float dt)
{
	processCommands();
	// Update all the active states
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
	{
		(*iter)->update(dt);
	}
}

void GameStateManager::renderStates(aie::Renderer2D *renderer)
{
	// Render all the active states
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
	{
		(*iter)->render(renderer);
	};
}

void GameStateManager::setState(int id, IGameState * state)
{
	Command temp;

	temp.cmd = ECommand::SET;
	temp.id = id;
	temp.state = state;
	m_commands.push_back(temp);
}

void GameStateManager::pushState(int id)
{
	Command temp;

	temp.cmd = ECommand::PUSH;
	temp.id = id;
	temp.state = nullptr;
	m_commands.push_back(temp);
}

void GameStateManager::popState()
{
	Command temp;

	temp.cmd = ECommand::POP;
	temp.id = 0;
	temp.state = nullptr;
	m_commands.push_back(temp);
}

IGameState * GameStateManager::getTopState()
{
	if(m_activeStates.size() > 0)
	{ 
		return m_activeStates.back();
	}

	return nullptr;
}

void GameStateManager::processCommands()
{
	for (auto iter = m_commands.begin(); iter != m_commands.end(); iter++)
	{
		Command &c = (*iter);
		switch (c.cmd) 
		{
		case ECommand::PUSH:
			processPushState(c.id);
			break;

		case ECommand::SET:
			ProcessSetState(c.id, c.state);
			break;

		case ECommand::POP:
			processPopState();
			break;

		default:
			assert(false && "Command not found!");
		}
	}

	// this ensures that the commands only get called once.
	m_commands.clear();
}

void GameStateManager::ProcessSetState(int id, IGameState * state)
{
	auto iter = m_registeredStates.find(id);
	if (iter != m_registeredStates.end())
	{
		delete iter->second;
	}

	m_registeredStates[id] = state;
}

void GameStateManager::processPushState(int id)
{

	auto iter = m_registeredStates.find(id);
	if (iter != m_registeredStates.end())
	{
		m_activeStates.push_back(iter->second);
	}
	else
	{
		assert((int)id && "State not found");
	}

}

void GameStateManager::processPopState()
{
	if (m_activeStates.size() > 0)
	{
		m_activeStates.pop_back();
	}
}
