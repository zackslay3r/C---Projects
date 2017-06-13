#pragma once
#include <map>
#include <vector>

// Forward declare to let us use the type in this namespace
class Application2D;
class IState;

class GSM {
public:
	GSM();
	~GSM();

	void updateStates(float deltaTime);
	void renderStates();


	void registerState(int ID, IState* state);
	void pushState(int ID);
	void popState();

	IState* getTopState();

private:
	std::map<int, IState*> m_registeredStates;
	std::vector<IState*> m_activeStates;


	// This is an enum class that will have the 3 commands we want. 

	enum class ECommand { REGISTER, PUSH, POP };

	struct ICommand
	{
		ECommand c_command;
		int c_id;
		IState* c_state;

	};
	std::vector<ICommand> m_commands;
	// this command will happen at the beginning of the update to be able to swap states when needed.

	void processCommands();
	void proceesRegisterState(int ID, IState* state);
	void processPushState(int ID);
	void processPopState();
};

