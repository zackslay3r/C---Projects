#include "UpdatePlayState.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Settings.h"
#include "ScoreKeeper.h"
#include "PhysicsCalculator.h"
#include "GameStateManager.h"
#include "GameCore.h"

UpdatePlayState::UpdatePlayState()
{
}

UpdatePlayState::~UpdatePlayState()
{
}

void UpdatePlayState::enter()
{
}

void UpdatePlayState::leave()
{
}

void UpdatePlayState::update()
{
    GC->update();
}

void UpdatePlayState::draw()
{
}
