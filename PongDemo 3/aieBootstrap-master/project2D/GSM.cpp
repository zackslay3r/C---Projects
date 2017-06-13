


#include "GSM.h"
#include "IState.h"
#include "assert.h"


GSM::GSM() {
}


GSM::~GSM() {
	
	
	// This will clear all the registered states within m_registeredStates
	//for (auto iter = m_registeredStates.begin(); iter != m_registeredStates.end(); iter++)
	//	delete iter->second;
	//m_registeredStates.clear();
}

void GSM::updateStates(float deltaTime) {

	// We are now going to update the active states based upon the the state itself, and will then update based on the command given (Register, push, pop)
	processCommands();
	// and then we are going to update the active states based on delta time.
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
		(*iter)->update(deltaTime);
}

void GSM::renderStates(aie::Renderer2D*	m_2dRenderer) {
	// and then we are going to run the render function on all the active states.
	for (auto iter = m_activeStates.begin(); iter != m_activeStates.end(); iter++)
		(*iter)->render(m_2dRenderer);
}

void GSM::registerState(int ID, IState* state) {
	ICommand command;

	command.c_id = ID;
	command.c_command = ECommand::REGISTER;
	command.c_state = state;
	m_commands.pushBack(command);
}

void GSM::pushState(int ID) {
	ICommand command;

	command.c_id = ID;
	command.c_command = ECommand::PUSH;
	command.c_state = nullptr;
	m_commands.pushBack(command);
}

void GSM::popState() {

	ICommand command;


	command.c_command = ECommand::POP;
	
	command.c_id = -1;
	command.c_state = nullptr;
	m_commands.pushBack(command);
}

IState * GSM::getTopState() {
	if (m_activeStates.listLength > 0)
	{
		// If we have states on the stack, the 'top' state will be the one at the back
		return m_activeStates.last();
	}
	return nullptr;
}

void GSM::processCommands()
{

	for (auto &var: m_commands) {
		/* Since an iterator points to the memory location of each item in the list, we'll dereference this
		to get the item itself and make the code easier to read*/
		ICommand &command = var;

		switch (command.c_command) {
		case ECommand::REGISTER:	proceesRegisterState(command.c_id, command.c_state); break;
		case ECommand::PUSH:		processPushState(command.c_id); break;
		case ECommand::POP:			processPopState(); break;

			// we could have some error checking here if you like
			//default:
			//throw (Exception... - we could make a custom exception type)
			//return 0xff (or some #defined error_id)
			//return true/false
		}
	}
	// Clear the command queue after we're done so we don't re-execute old commands
	m_commands.deleteList();
}

void GSM::proceesRegisterState(int ID, IState * state)
{

	// assign the state to the id.
	m_registeredStates.AddItem(ID, state);
}

void GSM::processPushState(int ID)
{


	//auto iter = m_registeredStates.begin();

	//if (iter != m_registeredStates.end())
	//{
		// if the iter is matched and its not the end of the container, delete it so that it can get replaced
		m_activeStates.pushBack(m_registeredStates[ID]);
	/*}
	else
		assert((iter != m_registeredStates.end()) && ID && "could not find a state with ID!");*/

}

void GSM::processPopState()
{
	if (m_activeStates.listLength > 0)
	{
		m_activeStates.popBack();
	}
}
