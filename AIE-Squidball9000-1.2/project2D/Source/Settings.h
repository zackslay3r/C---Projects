#pragma once


#define SETT Settings::getInstance()

/**
* A class that stores settings for the game.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Settings
{

public:

	/**
    * Create or get static instance.
    * @returns A pointer to the single Settings object.
    */
	static class Settings *getInstance();

    /**
    * Screen width.
    */
    int screenWidth;

    /**
    * Screen height.
    */
    int screenHeight;

    /**
    * Refresh rate reported by graphics card.
    */
    float refreshRate;

    /**
    * Full screen mode.
    */
    bool fullscreen;

private:

	/**
	* Default constructor.
    * Private to prevent class being created on the stack.
    */
    Settings();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
	~Settings();

};