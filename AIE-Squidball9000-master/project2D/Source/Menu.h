#pragma once
#include "Application2D.h"
#include "Font.h"
#include "Renderer2D.h"
#include <MathsLib.h>



#define MENU Menu::getInstance()

/**
* This class displays the main menu for the game, managing game settings. 
* It also controls game state and initiates new games.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Menu
{

public:

	/**
    * Create or get static instance.
    * @returns A pointer to the single Menu object.
    */
	static class Menu *getInstance();

	/**
	* Player settings options.
	*/
	enum class PlayerSettings { Human, AIEasy, AIMedium, AIHard };

	/**
	* Junk settings options.
	*/
	enum class JunkSettings { None, Low, Moderate, High, Extreme };

	/**
	* Player left settings.
	*/
	PlayerSettings playerLeftSetting;

	/**
	* Player right settings.
	*/
	PlayerSettings playerRightSetting;

	/**
	* Junk setting.
	*/
	JunkSettings junkSetting;

	/**
	* Is a match in progress?
	*/
	bool playing;

	/**
	* Key toggle for M key to allow it to be detected as a single keypress.
	*/
	bool mToggle;

	/**
	* All possible menu display states.
	*/
	enum class MenuStates { MainMenu, Help };

	/**
	* Toggle player settings.
	* @params playerSetting Pointer to the settings to toggle.
	* @returns void.
	*/
	void togglePlayerSettings(PlayerSettings *playerSetting);

	/**
	* Toggle junk settings.
	* @returns void.
	*/
	void toggleJunkSettings();

	/**
	* Run menu actions.
	* @returns void.
	*/
	void update();

	/**
	* Draw menu.
	* @returns void.
	*/
	void draw() const;

	/**
	* Initiate a new game. Cleans up any current game in progress.
	* @returns void.
	*/
	void newGame();

private:

	/**
	* Default constructor.
    * Private to prevent class being created on the stack.
    */
	Menu();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
	~Menu();

	/**
	* Menu display state.
	*/
	MenuStates menuState;

	/**
	* Input object pointer.
	*/
	aie::Input *input;

	/**
	* Currently selected menu option.
	*/
	int menuOption;

	/**
	* The maximum menu option index allowed.
	*/
	int maxMenuOption;

	/**
	* Menu options colour.
	*/
	Colour menuColour;
	
	/**
	* Menu options colour for selected item.
	*/
	Colour menuColourSelected;

	/**
	* Menu options font size.
	*/
	unsigned short menuOptionFontSize;

};