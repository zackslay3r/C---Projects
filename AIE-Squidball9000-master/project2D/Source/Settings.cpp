#include "Settings.h"



Settings::Settings()
{

    screenWidth = 0;
    screenHeight = 0;
    refreshRate = 0;
    fullscreen = false;
}

Settings::~Settings()
{
}

Settings *Settings::getInstance()
{
	static Settings settings;

	return &settings;
}
