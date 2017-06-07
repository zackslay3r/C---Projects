#pragma once
typedef List<IGameState*> stateLL;
#include <../demo/demoList.h>
#include <map>

namespace aie {

	class Renderer2D;
}
class IGameState;

class GameStateManager {

public:
	GameStateManager();
	~GameStateManager();

	void updateStates(float dt);
	void renderStates(aie::Renderer2D *renderer);

	void setState(int ID, IGameState *state);
	void pushState(int ID);
	void popState();

	IGameState *getTopState();


private:
	std::map<int, IGameState*> m_registeredStates;
	stateLL myStates;

	void processCommands();

	void processSetState(int ID, IGameState *state);
	void processPushState(int ID);
	void processPopState();

	enum class ECommand {PUSH, POP, SET};

	struct Command {

		ECommand cmd;
		int ID;
		IGameState *pState;

	};

	List<Command> m_commands;


};