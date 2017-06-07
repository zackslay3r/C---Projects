#pragma once
#include <string>


class IState
{
	IState(); // default constructor.

	virtual ~IState(); //Default destructor

	// Retrieves the name of the state.
	virtual std::string getName() = 0;



	// Enter the current state.
	virtual void enterState() = 0;


	// Exit the current state.
	virtual void leaveState() = 0;



	// Update the current state.
	virtual void updateState() = 0;


	// Execute the draw state function.
	virtual void drawState() = 0;


};