#pragma once
#include <map>
#include <list>
#include "IGameState.h"

class Application2D;
class IGameState;

class gameFSM
{	
public:

	/*
	* GSM();
	*
	* This is the GSM constructor.
	*
	*/
	gameFSM();
	/*
	* ~GSM();
	*
	* This is the GSM destructor.
	*
	*/
	~gameFSM();

	/*	void updateStates(float deltaTime);
	*	This function is responsible for updating the states based on which states are in use and which are just registered.
	*
	*	parameter 1 deltaTime - Delta Time.
	*	@returns void
	*/
	void updateStates(float deltaTime);


	/*	void registerState(int ID, IState* state);
	*	This function is responsible for registering a state into the registered states with an ID and the state itself.
	*
	*	parameter1 ID - the ID of the state to be registered.
	*
	*	parameter2 state - The state we are trying to register.
	*
	*	@returns void
	*/
	void registerState(int ID, IGameState* state);

	/*	void pushState(int ID);
	*	This function is responsible for pushing a state into the active states with an ID.
	*
	*	parameter1 ID - the ID of the state to be pushed.
	*
	*
	*	@returns void
	*/
	void pushState(int ID);
	/*	void popState();
	*	This function is responsible for popping a state from the active states to the registered states.
	*
	*	parameter1 ID - the ID of the state to be registered.
	*
	*
	*	@returns void
	*/
	void popState();


	/*	IState* getTopState();
	*	This function is responsible for getting the first state in the linked list of active states and for the purposes of running that state.
	*
	*
	*
	*	@returns IState* - the top state in the list to be run.
	*/
	IGameState* getTopState();

private:
	// This is using a Binary tree for the registered states.
	std::map<int, IGameState*> m_registeredStates;
	// And uses a linked list for the active states.
	std::list<IGameState*> m_activeStates;


	// This is an enum class that will have the 3 commands we want. 

	enum class ECommand { REGISTER, PUSH, POP };

	struct ICommand
	{
		ECommand c_command;
		int c_id;
		IGameState* c_state;

	};
	std::list<ICommand> m_commands;
	// this command will happen at the beginning of the update to be able to swap states when needed.

	/*	void processCommands();
	*	This function is responsible for processing the pushing, popping and registering of each state.
	*
	*
	*
	*	@returns void
	*/
	void processCommands();
	/*	void proceesRegisterState(int ID, IState* state);
	*	This function is responsible for calling the registerState function with the parameters provided.
	*
	*
	*	parameter1 ID - the ID of the state to be registered.
	*
	*	parameter2 state - The state we are trying to register.
	*
	*	@returns void
	*/
	void proceesRegisterState(int ID, IGameState* state);
	/*	void processPushState(int ID);
	*	This function is responsible for calling the pushState function with the parameters provided.
	*
	*
	*	parameter1 ID - the ID of the state to be registered.
	*
	*
	*	@returns void
	*/
	void processPushState(int ID);
	/*	void processPopState();
	*	This function is responsible for calling the popState function.
	*
	*
	*
	*
	*	@returns void
	*/
	void processPopState();
};

