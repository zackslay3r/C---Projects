#pragma once
#include "IBehavior.h"
#include <map>


class IBehavior;
class BehaviourManager
{
public:
	BehaviourManager();
	~BehaviourManager();

	void updateBehaviours(Object* pObject,float deltaTime);

	void registerBehaviour(int ID, IBehavior* behaviours);

	void pushBehaviour(int ID);

	void popBehaviour();

	IBehavior* getTopBehaviour();

private:
	std::map<int, IBehavior*> m_registeredBehaviours;

	std::list<IBehavior*> m_activeBehaviours;

	enum class ECommand {REGISTER, PUSH, POP};


	struct ICommand
	{
		ECommand c_command;
		int c_id;
		IBehavior* c_behaviour;

	};
	std::list<ICommand> m_commands;

	void processBehaviours();


	void processRegisterBehaviour(int ID, IBehavior* behaviour);

	void processPushBehaviour(int ID);

	void processPopBehaviours();
};

