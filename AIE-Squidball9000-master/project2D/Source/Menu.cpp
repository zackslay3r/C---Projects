#include <string>
#include "aieException.h"
#include "Menu.h"
#include "Input.h"
#include "AssetManager.h"
#include "ScoreKeeper.h"
#include "Settings.h"
#include "GameStateManager.h"
#include "GameCore.h"

Menu::Menu()
{

	//Menu input handler.
	input = aie::Input::getInstance();

	//Default menu state on startup.
	menuState = MenuStates::MainMenu;

	//Default playing state.
	playing = false;

	//M key toggle state.
	mToggle = true;

	//Default menu option selected on startup. Index starts from 0.
	menuOption = 0;

	//Max menu option index on startup. Index starts from 0.
	maxMenuOption = 4;

	//Menu options colour.
	menuColour = Colour(0.0f, 0.6f, 0.0f, 6.0f);

	//Menu options highlighted colour.
	menuColourSelected = Colour(0.0f, 1.0f, 0.0f, 1.0f);

	//Default menu option font size.
	menuOptionFontSize = 48;

	//Default player settings on startup.
	playerLeftSetting = PlayerSettings::Human;
	playerRightSetting = PlayerSettings::Human;

	//Default junk setting on startup.
	junkSetting = JunkSettings::Moderate;

}

Menu::~Menu()
{
}

Menu *Menu::getInstance()
{
	static Menu menu;

	return &menu;
}

void Menu::togglePlayerSettings(PlayerSettings *playerSetting)
{

	switch (*playerSetting)
	{
	case Menu::PlayerSettings::Human:
		*playerSetting = Menu::PlayerSettings::AIEasy;
		break;
	case Menu::PlayerSettings::AIEasy:
		*playerSetting = Menu::PlayerSettings::AIMedium;
		break;
	case Menu::PlayerSettings::AIMedium:
		*playerSetting = Menu::PlayerSettings::AIHard;
		break;
	case Menu::PlayerSettings::AIHard:
		*playerSetting = Menu::PlayerSettings::Human;
		break;
	default:
		aieTHROW("ERROR: Unknown playerSetting.");
		break;
	}

}

void Menu::toggleJunkSettings()
{

	switch (junkSetting)
	{
	case Menu::JunkSettings::None:
		junkSetting = Menu::JunkSettings::Low;
		break;
	case Menu::JunkSettings::Low:
		junkSetting = Menu::JunkSettings::Moderate;
		break;
	case Menu::JunkSettings::Moderate:
		junkSetting = Menu::JunkSettings::High;
		break;
	case Menu::JunkSettings::High:
		junkSetting = Menu::JunkSettings::Extreme;
		break;
	case Menu::JunkSettings::Extreme:
		junkSetting = Menu::JunkSettings::None;
		break;
	default:
		aieTHROW("ERROR: Unknown junk setting.");
		break;
	}

}

void Menu::update()
{
	//Toggle menu visibility off if we're in a game.
	if (playing && mToggle && (input->isKeyDown(aie::INPUT_KEY_M)))
	{
		mToggle = false;
		
        //Remove menu game state from active list.
        GSM->removeState("MenuMain");

        //Add playing game states to active list.
        GSM->activateState("DrawPlay");
        GSM->activateState("UpdatePlay");
	}


    //Reset menu toggle state.
    if (input->isKeyUp(aie::INPUT_KEY_M)) mToggle = true;

	//Menu navigation.
	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
	{
		menuOption++;
		if (menuOption > maxMenuOption) menuOption = maxMenuOption;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_UP))
	{
		menuOption--;
		if (menuOption < 0) menuOption = 0;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
	{
		if (menuOption == 0) togglePlayerSettings(&playerLeftSetting);
		if (menuOption == 1) togglePlayerSettings(&playerRightSetting);
		if (menuOption == 2) toggleJunkSettings();
		if (menuOption == 3)
		{
			newGame();
		}
		if (menuOption == 4) GC->app->quit();
	}

}

void Menu::draw() const
{
	
	aie::Renderer2D *renderer = GC->app->m_2dRenderer;

	aieASSERT(renderer);

	std::string menuString = "";

	float menuLeftX = (float) (SETT->screenWidth - 710) / 2;
	float menuTopY = (float) (SETT->screenHeight - 280);
	float vertSpacing = 50.0f;
	float curVertSpace = 0.0f;
    float depth = 0;

    //Black semitransparent box behind menu.
    renderer->setRenderColour(0.5f, 0.5f, 0.5f, 0.1f);
    renderer->drawBox((float)SETT->screenWidth / 2.0f, menuTopY - 140.0f, 800.0f, 400.0f, 0, depth + 1.0f);

    //Big title.
    renderer->setRenderColour(0.0f, 0.3f, 0.0f, 1.0f);
    char title[32];
    sprintf_s(title, 32, "%s", "SQUIDBALL 9000");
    renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 172), title, (float)(SETT->screenWidth - 1420) / 2, 100, depth);

	char item[1024];

	//Small Title.
	renderer->setRenderColour(0.0f, 1.0f, 1.0f, 1.0f);
	sprintf_s(item, 1024, "%s", "SQUIDBALL 9000 v1.3 by Ashley Flynn - AIE - 2017");
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", menuOptionFontSize), item, 
        (float) (SETT->screenWidth - 1360) / 2, (float)(SETT->screenHeight - 130), depth);

	//Player Left settings.
	if (menuOption == 0)
	{
		renderer->setRenderColour(menuColourSelected.r, menuColourSelected.g, menuColourSelected.b, menuColourSelected.a);
	}
	else
	{
		renderer->setRenderColour(menuColour.r, menuColour.g, menuColour.b, menuColour.a);
	}
	menuString = "Left Player : ";
	switch (playerLeftSetting)
	{
	case PlayerSettings::Human:
		menuString += "Human";
		break;
	case PlayerSettings::AIEasy:
		menuString += "Easy AI";
		break;
	case PlayerSettings::AIMedium:
		menuString += "Medium AI";
		break;
	case PlayerSettings::AIHard:
		menuString += "Hard AI";
		break;
	default:
		aieTHROW("ERROR: Unknown setting for left player.");
	}

	sprintf_s(item, 1024, "%s", ((std::string) (menuOption == 0 ? "> " : "  ") + menuString).c_str());
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", menuOptionFontSize), item, menuLeftX, menuTopY - curVertSpace, depth);

	//Player Right settings.
	curVertSpace += vertSpacing;
	if (menuOption == 1)
	{
		renderer->setRenderColour(menuColourSelected.r, menuColourSelected.g, menuColourSelected.b, menuColourSelected.a);
	}
	else
	{
		renderer->setRenderColour(menuColour.r, menuColour.g, menuColour.b, menuColour.a);
	}

	menuString = "Right Player: ";
	switch (playerRightSetting)
	{
	case PlayerSettings::Human:
		menuString += "Human";
		break;
	case PlayerSettings::AIEasy:
		menuString += "Easy AI";
		break;
	case PlayerSettings::AIMedium:
		menuString += "Medium AI";
		break;
	case PlayerSettings::AIHard:
		menuString += "Hard AI";
		break;
	default:
		aieTHROW("ERROR: Unknown setting for right player.");
	}

	sprintf_s(item, 1024, "%s", ((std::string) (menuOption == 1 ? "> " : "  ") + menuString).c_str());
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", menuOptionFontSize), item, menuLeftX, menuTopY - curVertSpace, depth);

	//Junk settings.
	curVertSpace += vertSpacing;
	if (menuOption == 2)
	{
		renderer->setRenderColour(menuColourSelected.r, menuColourSelected.g, menuColourSelected.b, menuColourSelected.a);
	}
	else
	{
		renderer->setRenderColour(menuColour.r, menuColour.g, menuColour.b, menuColour.a);
	}

	menuString = "Junk Amount : ";
	switch (junkSetting)
	{
	case JunkSettings::None:
		menuString += "None";
		break;
	case JunkSettings::Low:
		menuString += "Low";
		break;
	case JunkSettings::Moderate:
		menuString += "Moderate";
		break;
	case JunkSettings::High:
		menuString += "High";
		break;
	case JunkSettings::Extreme:
		menuString += "Extreme";
		break;
	default:
		aieTHROW("ERROR: Unknown setting for junk amount.");
	}

	sprintf_s(item, 1024, "%s", ((std::string) (menuOption == 2 ? "> " : "  ") + menuString).c_str());
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", menuOptionFontSize), item, menuLeftX, menuTopY - curVertSpace, depth);

	//Start New Game
	curVertSpace += vertSpacing;
	if (menuOption == 3)
	{
		renderer->setRenderColour(menuColourSelected.r, menuColourSelected.g, menuColourSelected.b, menuColourSelected.a);
	} 
	else
	{
		renderer->setRenderColour(menuColour.r, menuColour.g, menuColour.b, menuColour.a);
	}
	sprintf_s(item, 1024, "%s", ((std::string) (menuOption == 3 ? "> " : "  ") + "Start New Game").c_str());
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", menuOptionFontSize), item, menuLeftX, menuTopY - curVertSpace, depth);

	//Quit
	curVertSpace += vertSpacing;
	if (menuOption == 4)
	{
		renderer->setRenderColour(menuColourSelected.r, menuColourSelected.g, menuColourSelected.b, menuColourSelected.a);
	}
	else
	{
		renderer->setRenderColour(menuColour.r, menuColour.g, menuColour.b, menuColour.a);
	}
	sprintf_s(item, 1024, "%s", ((std::string) (menuOption == 4 ? "> " : "  ") + "Quit").c_str());
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", menuOptionFontSize), item, menuLeftX, menuTopY - curVertSpace, depth);
	
	curVertSpace += vertSpacing * 2;
	//Return to game message.
	renderer->setRenderColour(0.7f, 0.7f, 0.7f, 0.7f);
	char menu[1024];
	if (playing)
	{
		sprintf_s(menu, 1024, "%s", "M - Return to Current Game");
	}
	else
	{
		sprintf_s(menu, 1024, "%s", "M - Return to Menu any time");
	}
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 48), menu, menuLeftX - 30.0f , menuTopY - curVertSpace, depth);

}

void Menu::newGame()
{
	playing = true;

    //Remove menu game state from active list.
    GSM->removeState("MenuMain");

    //Add playing game states to active list.
    GSM->activateState("DrawPlay");
    GSM->activateState("UpdatePlay");

	//Clean playing field.
	SCOR->cleanAllJunk();

	//Set up players.

	Player::Pst pTypeLeft;
	Player::Pst pTypeRight;

	switch (playerLeftSetting)
	{
	case PlayerSettings::Human:
		pTypeLeft = Player::Pst::HumanLeft;
		break;
	case PlayerSettings::AIEasy:
		pTypeLeft = Player::Pst::AISimple;
		break;
	case PlayerSettings::AIMedium:
		pTypeLeft = Player::Pst::AIMedium;
		break;
	case PlayerSettings::AIHard:
		pTypeLeft = Player::Pst::AIHard;
		break;
	default:
		aieTHROW("ERROR: Invalid player type passed from menu.");
		break;
	}

	switch (playerRightSetting)
	{
	case PlayerSettings::Human:
		pTypeRight = Player::Pst::HumanRight;
		break;
	case PlayerSettings::AIEasy:
		pTypeRight = Player::Pst::AISimple;
		break;
	case PlayerSettings::AIMedium:
		pTypeRight = Player::Pst::AIMedium;
		break;
	case PlayerSettings::AIHard:
		pTypeRight = Player::Pst::AIHard;
		break;
	default:
		aieTHROW("ERROR: Invalid player type passed from menu.");
		break;
	}

	//LEFT
	FACT->newPlayerLeft(pTypeLeft);

	//RIGHT
	FACT->newPlayerRight(pTypeRight);
	
	//Set up score keeper.

	SCOR->resetScores();
	SCOR->resetState();
	SCOR->resetActor(FACT->playerLeft);
	SCOR->resetActor(FACT->playerRight);
	SCOR->goalProcessEnd();
}
