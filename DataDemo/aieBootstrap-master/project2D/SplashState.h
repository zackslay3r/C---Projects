#pragma once

#include "Application2D.h"
#include "IGameState.h"
#include "SpriteBatch.h"
#include "Font.h"

#include <stdio.h>

class SplashState : public IGameState
{
public:
	
	SplashState(Application2D *pApp);

	 ~SplashState();

	 virtual void Update(float deltaTime);
	virtual void Draw();

protected:

private:


	Font* m_font;
	float m_elapsedTime;




};