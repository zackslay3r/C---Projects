#pragma once
#include <map>
#include <vector>

enum class EStateID;
class IGameState;

namespace aie {

	class Renderer2D;
}

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void updateStates(float dt);

	void renderStates(aie::Renderer2D *renderer);

	void setState(int id, IGameState* state);

	void pushState(int id);

	void popState();

	IGameState* getTopState();

private:
	std::map<int, IGameState*> m_registeredStates;
	std::vector<IGameState*> m_activeStates;


#pragma region Commands
	void processCommands();

	void ProcessSetState(int id, IGameState* state);

	void processPushState(int id);

	void processPopState();

	enum class ECommand {SET, PUSH , POP};

	struct Command
	{
		ECommand cmd;
		int id;
		IGameState *state;
	
	};

	std::vector<Command> m_commands;

#pragma endregion
};

