#pragma once
#include <map>
#include <vector>
#include <../demo/demoList.h>
#include <../demo/BinaryTree.h>
#include <../bootstrap/Renderer2D.h>

// Forward declare to let us use the type in this namespace
class Application2D;
class IState;

class GSM {
public:
	GSM();
	~GSM();

	void updateStates(float deltaTime);
	void renderStates(aie::Renderer2D*	m_2dRenderer);


	void registerState(int ID, IState* state);
	void pushState(int ID);
	void popState();

	IState* getTopState();

private:
	BinaryTree<int, IState*> m_registeredStates;
	List<IState*> m_activeStates;


	// This is an enum class that will have the 3 commands we want. 

	enum class ECommand { REGISTER, PUSH, POP };

	struct ICommand
	{
		ECommand c_command;
		int c_id;
		IState* c_state;

	};
	List<ICommand> m_commands;
	// this command will happen at the beginning of the update to be able to swap states when needed.

	void processCommands();
	void proceesRegisterState(int ID, IState* state);
	void processPushState(int ID);
	void processPopState();
};

