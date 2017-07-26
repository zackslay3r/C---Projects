#include "BehaviourManager.h"



BehaviourManager::BehaviourManager()
{
}


BehaviourManager::~BehaviourManager()
{
}

void BehaviourManager::updateBehaviours(Object* pObject, float deltaTime)
{
	processBehaviours();

	for (auto iter = m_activeBehaviours.begin(); iter != m_activeBehaviours.end(); iter++)
	{
		(*iter)->Update(pObject, deltaTime);
	}
}

void BehaviourManager::registerBehaviour(int ID, IBehavior * behaviour)
{
	ICommand command;

	command.c_id = ID;
	
	command.c_command = ECommand::REGISTER;

	command.c_behaviour = behaviour;

	m_commands.push_back(command);

}

void BehaviourManager::pushBehaviour(int ID)
{
	ICommand command;


	command.c_id = ID;
	command.c_command = ECommand::PUSH;
	command.c_behaviour = nullptr;

	m_commands.push_back(command);
}

void BehaviourManager::popBehaviour()
{
	ICommand command;

	command.c_command = ECommand::POP;

	command.c_id = -1;
	command.c_behaviour = nullptr;
	m_commands.push_back(command);
}

IBehavior * BehaviourManager::getTopBehaviour()
{
	if (m_activeBehaviours.size() > 0)
	{
		return m_activeBehaviours.front();
	}
	else
	{
		return nullptr;
	}
}

void BehaviourManager::processBehaviours()
{
	for (auto &var : m_commands)
	{
		ICommand &command = var;

		switch (command.c_command)
		{
			case ECommand::REGISTER:
			{
				processRegisterBehaviour(command.c_id, command.c_behaviour);
				break;
			}

			case ECommand::PUSH:
			{
				IBehavior* temp = m_registeredBehaviours[command.c_id];
				processPushBehaviour(command.c_id);
				break;
			}

			case ECommand::POP:
			{
				processPopBehaviours();
			}

			m_commands.clear();

		}

	}

}

void BehaviourManager::processRegisterBehaviour(int ID, IBehavior * behaviour)
{
	m_registeredBehaviours.insert(std::pair<int, IBehavior*>(ID, behaviour));
}

void BehaviourManager::processPushBehaviour(int ID)
{
	m_activeBehaviours.push_back(m_registeredBehaviours[ID]);
}

void BehaviourManager::processPopBehaviours()
{
	if (m_activeBehaviours.size() > 0)
	{
		m_activeBehaviours.pop_back();
	}
}
