#include "gameFSM.h"
#include "IGameState.h"
#
#include <list>

gameFSM::gameFSM()
{
}


gameFSM::~gameFSM()
{
}

void gameFSM::updateStates(float deltaTime)
{
	// We are now going to update the active states based upon the the state itself, and will then update based on the command given (Register, push, pop)
	processCommands();
	// and then we are going to update the active states based on delta time.
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
	{
		(*iter)->update(deltaTime);
	}
}



void gameFSM::registerState(int ID, IGameState * state)
{
	ICommand command;


	command.c_id = ID;

	command.c_command = ECommand::REGISTER;
	
	command.c_state = state;

	m_commands.push_back(command);
}

void gameFSM::pushState(int ID)
{
	ICommand command;



	command.c_id = ID;
	command.c_command = ECommand::PUSH;
	command.c_state = nullptr;


	m_commands.push_back(command);
}

void gameFSM::popState()
{
	ICommand command;


	command.c_command = ECommand::POP;

	command.c_id = -1;
	command.c_state = nullptr;
	m_commands.push_back(command);
}

IGameState * gameFSM::getTopState()
{
	if (m_activeStates.size() > 0)
	{
		// If we have states on the stack, the 'top' state will be the one at the back
		return m_activeStates.back();
	}

}

void gameFSM::processCommands()
{
	for (auto &var : m_commands)
	{

		/* Since an iterator points to the memory location of each item in the list, we'll dereference this
		to get the item itself and make the code easier to read*/
		ICommand &command = var;

		switch (command.c_command)
		{
		case ECommand::REGISTER:
		{
			proceesRegisterState(command.c_id, command.c_state);
			break;
		}
		case ECommand::PUSH:
		{

			IGameState* temp = m_registeredStates[command.c_id];


			processPushState(command.c_id);
			break;
		}
		case ECommand::POP:
		{

			processPopState();



			break;
		}





		
		}
		
	}
	// Clear the command queue after we're done so we don't re-execute old commands
		m_commands.clear();
}


void gameFSM::proceesRegisterState(int ID, IGameState * state)
{
	// assign the state to the id.
	m_registeredStates.insert(std::pair<int, IGameState*> (ID, state));
}

void gameFSM::processPushState(int ID)
{
	// if the iter is matched and its not the end of the container, delete it so that it can get replaced
	m_activeStates.push_back(m_registeredStates[ID]);
	amountOfActive++;
}

void gameFSM::processPopState()
{
	if (m_activeStates.size() > 0)
	{
		m_activeStates.pop_back();
		amountOfActive--;
	}
}
