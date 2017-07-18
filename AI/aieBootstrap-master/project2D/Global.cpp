#include "Global.h"

GameSettings * GameSettings::getInstance()
{
	static GameSettings gamesettings;
	return &gamesettings;
}

GameSettings::GameSettings()
{
}
