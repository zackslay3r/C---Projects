#pragma once
#include <map>
#include <vector>

// Forward declare to let us use the type in this namespace
class SimpleGameApp;
class IGameState;

class GSM {
public:
	GSM();
	~GSM();

	void updateStates(float deltaTime);
	void renderStates();

	
	void registerState(int ID, IGameState* state);
	void pushState(int ID);
	void popState();

	IGameState* getTopState();

private:
	std::map<int, IGameState*> m_registeredStates;
	std::vector<IGameState*> m_activeStates;
	

	// This is an enum class that will have the 3 commands we want. 

	enum class ECommand {REGISTER, PUSH, POP};

	struct ICommand
	{
		ECommand c_command;
		int c_id;
		IGameState* c_state;

	};
	std::vector<ICommand> m_commands;
	// this command will happen at the beginning of the update to be able to swap states when needed.

	void processCommands();
	void proceesRegisterState(int ID, IGameState* state);
	void processPushState(int ID);
	void processPopState();
};

