


#include "GSM.h"
#include "IState.h"
#include "assert.h"
#include "Exeception.h"


GSM::GSM() {
}


GSM::~GSM() {
	
	

}

void GSM::updateStates(float deltaTime) {

	// We are now going to update the active states based upon the the state itself, and will then update based on the command given (Register, push, pop)
	processCommands();
	// and then we are going to update the active states based on delta time.
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
		(*iter)->update(deltaTime);
}

void GSM::renderStates() {
	// and then we are going to run the render function on all the active states.
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
		(*iter)->render();
}

void GSM::registerState(int ID, IState* state) {
	ICommand command;

	
	command.c_id = ID;
	if (ID <= 0 && ID )
	{
		eTHROW("A state you tried to register has a null ID.");
	}
	command.c_command = ECommand::REGISTER;
	if (state == NULL)
	{
		eTHROW("A state you tried to register has a null state.");
	}
	command.c_state = state;

	m_commands.push_back(command);
}

void GSM::pushState(int ID) {
	ICommand command;
	

	
		command.c_id = ID;
		command.c_command = ECommand::PUSH;
		command.c_state = nullptr;
	
	
		m_commands.push_back(command);
}

void GSM::popState() {

	ICommand command;


	command.c_command = ECommand::POP;
	
	command.c_id = -1;
	command.c_state = nullptr;
	m_commands.push_back(command);
}

IState * GSM::getTopState() {
	if (m_activeStates.max_size() > 0)
	{
		// If we have states on the stack, the 'top' state will be the one at the back
		return m_activeStates.back();
	}
	else
	{
		eTHROW("You tired to get a top state when one does not exist.");
		return nullptr;
	}
	
}

void GSM::processCommands()
{

	for (auto &var: m_commands) {
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
			try
			{
				IState* temp = m_registeredStates[command.c_id];
			}
			catch
				(...)
			{
				eTHROW("You tried to push a state that hasnt been registered.");
			}
			processPushState(command.c_id); 
			break;
		}
		case ECommand::POP:
		{
			try
			{
				processPopState();
			}
			catch
				(...)
			{
				eTHROW("You tried to POP a state that doesnt exist.");
			}
			break;
		}
		default :
		{
			eTHROW("You tried to use a command that does not exist.");
		}
	
		}
	}
	// Clear the command queue after we're done so we don't re-execute old commands
	m_commands.clear();
}

void GSM::proceesRegisterState(int ID, IState * state)
{

	// assign the state to the id.
	m_registeredStates.insert(std::pair<int, IState*>(ID, state));
}

void GSM::processPushState(int ID)
{


	//auto iter = m_registeredStates.begin();

	//if (iter != m_registeredStates.end())
	//{
		// if the iter is matched and its not the end of the container, delete it so that it can get replaced
		m_activeStates.push_back(m_registeredStates[ID]);
	/*}
	else
		assert((iter != m_registeredStates.end()) && ID && "could not find a state with ID!");*/

}

void GSM::processPopState()
{
	if (m_activeStates.max_size() > 0)
	{
		m_activeStates.pop_back();
	}
	else
	{
		eTHROW("m_activeStates does not have anything within its list that you can pop from.");
	}
}
