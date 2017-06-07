#include "DrawPlayState.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Settings.h"
#include "ScoreKeeper.h"
#include "GameCore.h"

DrawPlayState::DrawPlayState()
{
}

DrawPlayState::~DrawPlayState()
{
}

void DrawPlayState::enter()
{
}

void DrawPlayState::leave()
{
}

void DrawPlayState::update()
{
}

void DrawPlayState::draw()
{
    GC->draw();
}
