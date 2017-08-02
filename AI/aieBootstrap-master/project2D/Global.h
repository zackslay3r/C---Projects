#pragma once
namespace StateMangement {
	// This stores the enums of the different states.
	enum GameStateID {LOADING, GAME_STATE, SPLASH_STATE, MENU_STATE, PAUSE_STATE, BLAH};

}
namespace BehaviourManagement {

	enum BehaviourID {SEEK, WANDER,FLEE };
}


// GameSettings is a singleton class that will allow me to dynamically change the screensize as well as the grid square size.
#define GAMESETTINGS GameSettings::getInstance()
class GameSettings {
public:
	
	const int windowHeight = 900;
	const int windowLength = 1600;
	const int gridSize = 50;
	const int NODE_ARRAY_LENGTH = ((windowLength / gridSize) * (windowHeight / gridSize));
	const float CIRCLE_CHECKER_SIZE = (gridSize * 2)*0.9f;//90 //gridSize*1.41f; //
	static GameSettings* getInstance();

private:
	GameSettings();

};
