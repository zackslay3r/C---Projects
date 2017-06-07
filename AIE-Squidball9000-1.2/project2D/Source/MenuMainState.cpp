#include "MenuMainState.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Settings.h"
#include "GameCore.h"

MenuMainState::MenuMainState()
{
}

MenuMainState::~MenuMainState()
{
}

void MenuMainState::enter()
{
}

void MenuMainState::leave()
{
}

void MenuMainState::update()
{

    //Call update on main menu.
    MENU->update();

}

void MenuMainState::draw()
{
    //Call draw on main menu.
    MENU->draw();
}
