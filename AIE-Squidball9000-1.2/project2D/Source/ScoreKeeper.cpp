#include "ScoreKeeper.h"
#include "Factory.h"
#include "HumanRight.h"
#include "Menu.h"
#include "Settings.h"


ScoreKeeper::ScoreKeeper()
{

	winScore = 5;

	minXExtent = 0.0f;

	maxXExtent = (float)SETT->screenWidth;

	minYExtent = 0.0f;

	maxYExtent = (float)SETT->screenHeight;

	ballStartPosition = Vector2(maxXExtent / 2.0f, maxYExtent / 2.0f);

	resetState();

	resetScores();
}

ScoreKeeper::~ScoreKeeper()
{

}

ScoreKeeper *ScoreKeeper::getInstance()
{
	static ScoreKeeper scoreKeeper;

	return &scoreKeeper;
}


void ScoreKeeper::update(float dt)
{

	//Check if ball countdown tgimer is active.
	if (ballCountdownEnd)
	{
		if (ballCountdownEnd < GCLK->getTimeSeconds())
		{
			ballCountdownEnd = 0;
			resetBall();
		}
		return;
	}

	//Check if goal process timer is active and desired time has elapsed.
	if (goalTimeEnd && goalTimeEnd < GCLK->getTimeSeconds())
	{
		goalTimeEnd = 0.0f;
		goalProcessEnd();
		return;
	}

	//Check if win process timer is active and desired time has elapsed.
	if (winTimeEnd && winTimeEnd < GCLK->getTimeSeconds())
	{
		winTimeEnd = 0.0f;
		winProcessEnd();
		return;
	}

	bool tmpGoal = false;

	if (FACT->ball != nullptr && !ballCountdownEnd && !goalMessage && !winnerMessage)
	{
		if (FACT->ball->rootEntity->getWorldPos().x < minXExtent)
		{
			scoreRight++;
			tmpGoal = true;
			goalSide = false;
		}

		if (FACT->ball->rootEntity->getWorldPos().x > maxXExtent)
		{
			scoreLeft++;
			tmpGoal = true;
			goalSide = true;
		}

		if (FACT->ball->rootEntity->getWorldPos().y < minYExtent)
		{
			resetBall();
		}

		if (FACT->ball->rootEntity->getWorldPos().y > maxYExtent)
		{
			resetBall();
		}
	}

	if (tmpGoal && scoreLeft < winScore && scoreRight < winScore && !ballCountdownEnd && !goalMessage && !winnerMessage)
	{
		goalProcessStart();
	}

	if (!winnerMessage)
	{
		if (scoreLeft >= winScore)
		{
			if (FACT->playerRight != nullptr && FACT->playerRight->actor != nullptr)
			{
				FACT->playerRight->actor->explode();
			}

			winProcessStart();
		}

		if (scoreRight >= winScore)
		{
			if (FACT->playerLeft != nullptr && FACT->playerLeft->actor != nullptr)
			{
				FACT->playerLeft->actor->explode();
			}

			winProcessStart();
		}
	}
}

void ScoreKeeper::draw(aie::Renderer2D *renderer) const
{

	aieASSERT(renderer);

	//SCORES

	char score[32];
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 0.8f);
	if ((goalMessage || winnerMessage) && goalSide) renderer->setRenderColour(1.0f, 1.0f, 0.0f, 0.8f);
	sprintf_s(score, 32, "%i", scoreLeft);
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 72), score, 
        (float)SETT->screenWidth / 2 - 236, (float)SETT->screenHeight - 100, 2);

	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 0.8f);
	if ((goalMessage || winnerMessage) && !goalSide) renderer->setRenderColour(1.0f, 1.0f, 0.0f, 0.8f);
	sprintf_s(score, 32, "%i", scoreRight);
	renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 72), score, 
        (float)SETT->screenWidth / 2 + 200, (float)SETT->screenHeight - 100, 2);

	//GOAL MESSAGE

	if (goalMessage)
	{
		renderer->setRenderColour(1.0f, 1.0f, 0.0f, 0.6f);
		char goal[32];
		sprintf_s(goal, 32, "%s", "GOAL!");
		renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 172), goal, (float)(SETT->screenWidth - 480) / 2, 
            (float)(SETT->screenHeight - 80) / 2, 2);
	}

	//WINNER MESSAGE
	if (winnerMessage)
	{
		renderer->setRenderColour(1.0f, 1.0f, 0.0f, 0.6f);
		char goal[32];
		sprintf_s(goal, 32, "%s", "WINNER!");
		renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 172), goal, (float)(SETT->screenWidth - 660) / 2, 
            (float)(SETT->screenHeight - 80) / 2, 2);
	}

	//BALL COUNTDOWN TIMER
	if (ballCountdownEnd)
	{
		renderer->setRenderColour(0.0f, 1.0f, 0.0f, 0.8f);
		
		char timer[32];
		int timeDisplay = 1 + (int)floor(ballCountdownEnd - GCLK->getTimeSeconds());
		sprintf_s(timer, 32, "%i", timeDisplay);

		if (timeDisplay != 0) renderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 172), timer, 
            (float)(SETT->screenWidth - 100) / 2, (float)(SETT->screenHeight + 120) / 2, 2);
	}

}

void ScoreKeeper::resetBall() const
{
	if (FACT->ball == nullptr) return;
	
	FACT->ball->randomDirection(FACT->ball->maxVelocity);
	FACT->ball->rootEntity->setRotation(0);
	FACT->ball->rootEntity->angVelocity = (float)mt.rng(-2.0, 2.0);
	FACT->ball->maxVelocity = FACT->ball->baseMaxVelocity;
	//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
	FACT->ball->rootEntity->setLocalPosition(ballStartPosition);

	FACT->ball->rootEntity->active = true;
	FACT->ball->rootEntity->visible = true;

	//Remove all child entities attached to the ball.
	/*std::vector*/ContLib::LinkedList<Entity*> tmpChildren;
	//Retrieve only IMMEDIATE children. 
	//Removing them will remove their own sub-child entities automatically.
	FACT->ball->rootEntity->getChildEntities(tmpChildren, false);
	for (Entity * ch : tmpChildren)
	{
		ch->setParent(nullptr);
		FACT->removeEntity(ch);
        //FACT->releaseEntity(ch);
	}
}

void ScoreKeeper::resetScores()
{
	scoreLeft = 0;
	scoreRight = 0;
}

void ScoreKeeper::resetActor(Player *player) const
{
	if (player->actor != nullptr) FACT->removeActor(player->actor);

	player->actor = FACT->addActor(Actor::Ast::Squid);
	player->actor->player = player;

	//Place actor in the middle of their allowed vertical range.
	player->actor->rootEntity->setLocalPosition(Vector2(player->clampX, ((player->clampYMax - player->clampYMin) / 2.0f)
        + player->clampYMin));

}

void ScoreKeeper::goalProcessStart()
{
	goalMessage = true;
	goalTimeEnd = (float)GCLK->getTimeSeconds() + 3.0f;
}

void ScoreKeeper::goalProcessEnd()
{

	FACT->ball->rootEntity->active = false;
	FACT->ball->rootEntity->visible = false;

	goalMessage = false;
	
	//Remove junk outside the game area.
	cleanOutsideJunk();

	//Chance to spawn junk on the game field.
	spawnJunk();

	ballCountdown();
	
}

void ScoreKeeper::winProcessStart()
{
	winnerMessage = true;
	winTimeEnd = (float)GCLK->getTimeSeconds() + 6.0f;
}

void ScoreKeeper::winProcessEnd()
{
	FACT->ball->rootEntity->active = false;
	FACT->ball->rootEntity->visible = false;

	winnerMessage = false;
	resetScores();

	FACT->newPlayerRight(FACT->playerRight->subType());
	resetActor(FACT->playerRight);

	FACT->newPlayerLeft(FACT->playerLeft->subType());
	resetActor(FACT->playerLeft);

	//Remove junk outside the game area.
	cleanOutsideJunk();

	//Chance to spawn junk on the game field.
	spawnJunk();

	FACT->ball->rootEntity->active = false;
	FACT->ball->rootEntity->visible = false;
	ballCountdown();
}

void ScoreKeeper::ballCountdown()
{
	FACT->ball->rootEntity->active = false;
	FACT->ball->rootEntity->visible = false;
	ballCountdownEnd = (float)GCLK->getTimeSeconds() + 3.0f;
}

void ScoreKeeper::spawnJunk() const
{

	int junkMin = 0;
	int junkMax = 0;

	switch (MENU->junkSetting)
	{
	case Menu::JunkSettings::None:
		//Don't spawn anything. Exit this function immediately.
		return;
	case Menu::JunkSettings::Low:
		junkMin = 0;
		junkMax = 2;
		break;
	case Menu::JunkSettings::Moderate:
		junkMin = 2;
		junkMax = 4;
		break;
	case Menu::JunkSettings::High:
		junkMin = 4;
		junkMax = 6;
		break;
	case Menu::JunkSettings::Extreme:
		junkMin = 6;
		junkMax = 8;
		break;
	default:
		aieTHROW("ERROR: Unknown setting for junk amount in spawnJunk.");
	}

	Entity::RenderSprite rsp;
	Entity::RenderShape rs;
	Entity *sticky;
	float size = 0;
	float diagonalsDown = 0;
	float diagonalsAlong = 0;

	size_t numEntities = (size_t)mt.rng(junkMin, junkMax);
	for (size_t i = 0; i < numEntities; i++)
	{
		int typeSel = mt.rng(0, 10);
		if (typeSel == 0)
		{
			//Tennis ball.
			sticky = FACT->addEntity(Entity::Et::BasicShape);
			size = (float)mt.rng(20.0, 30.0);
			sticky->colliderShapes = { Shape2(size) };
			for (auto &var : sticky->colliderShapes) var.updateNormals();
			sticky->rotatable = true;
			sticky->updateAABBFromColliders();
			sticky->setMass(10.0f);

			//Add sprite.
			//rsp.depth = 1.0f;
			rsp.colour = Colour();
			rsp.texture = "/textures/tennisball.png";
			rsp.textureWidth = size * 2.0f;
			rsp.textureHeight = size * 2.0f;
			sticky->sprites.push_back(rsp);
		}
		else if (typeSel == 1)
		{
			//Basket ball.
			sticky = FACT->addEntity(Entity::Et::BasicShape);
			size = (float)mt.rng(20.0, 30.0);
			sticky->colliderShapes = { Shape2(size) };
			for (auto &var : sticky->colliderShapes) var.updateNormals();
			sticky->rotatable = true;
			sticky->updateAABBFromColliders();
			sticky->setMass(10.0f);

			//Add sprite.
			//rsp.depth = 1.0f;
			rsp.colour = Colour();
			rsp.texture = "/textures/basketball.png";
			rsp.textureWidth = size * 2.0f;
			rsp.textureHeight = size * 2.0f;
			sticky->sprites.push_back(rsp);
		}
		else if (typeSel == 2)
		{
			//Triangle.

			//Calculate equalateral triangle points.
			size = (float)mt.rng(20.0, 40.0);
			diagonalsDown = size * sin(MathsLib::deg2rad(30.0f));
			diagonalsAlong = size * cos(MathsLib::deg2rad(30.0f));

			sticky = FACT->addEntity(Entity::Et::BasicShape);
			sticky->colliderShapes = { Shape2({ Vector2(0, size), Vector2(diagonalsAlong, -diagonalsDown), Vector2(-diagonalsAlong, -diagonalsDown) }) };
			for (auto &var : sticky->colliderShapes) var.updateNormals();
			sticky->rotatable = true;
			sticky->updateAABBFromColliders();

			rs.shape = Shape2({ Vector2(0, size), Vector2(diagonalsAlong, -diagonalsDown), Vector2(-diagonalsAlong, -diagonalsDown) });
			rs.colour = Colour((float)mt.rng(0.5, 1.0), (float)mt.rng(0.5, 1.0), (float)mt.rng(0.5, 1.0), 1.0f);
			rs.lineThickness = 2.0f;
			sticky->renderShapes.push_back(rs);
			for (auto &var : sticky->renderShapes) var.shape.updateNormals();

			sticky->setMass(10.0f);
		}
		else if (typeSel == 3)
		{
			//Paper ball 1.
			sticky = FACT->addEntity(Entity::Et::Paperball1);
		}
		else if (typeSel == 4)
		{
			//Pizza 1.
			sticky = FACT->addEntity(Entity::Et::Pizza1);
		}
		else if (typeSel == 5)
		{
			//Mona Lisa.
			sticky = FACT->addEntity(Entity::Et::MonaLisa);
		}
		else if (typeSel == 6)
		{
			//Cleaver.
			sticky = FACT->addEntity(Entity::Et::Cleaver);
		}
		else if (typeSel == 7)
		{
			//Ruler.
			sticky = FACT->addEntity(Entity::Et::Ruler);
		}
		else if (typeSel == 8)
		{
			//Computer.
			sticky = FACT->addEntity(Entity::Et::Computer);
		}
		else if (typeSel == 9)
		{
			//Snack chip packet.
			sticky = FACT->addEntity(Entity::Et::Snack);
		}
		else if (typeSel == 10)
		{
			//Canned squid.
			sticky = FACT->addEntity(Entity::Et::Can);
		}
		else
		{
			aieTHROW("Invalid entity type number in spawnJunk.");
		}

		sticky->sticky = true;

		sticky->setRotationDeg((float)mt.rng(0.0, 360.0));

		//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
		sticky->setLocalPosition(Vector2((float)mt.rng(250, SETT->screenWidth - 250),
			(float)mt.rng(100, SETT->screenHeight - 100)));

	}
}

void ScoreKeeper::cleanOutsideJunk() const
{
	
	//Get all top level entities.
	/*std::vector*/ContLib::LinkedList<Entity*> topEnts = FACT->getTopLevelEntities();

	//Remove any "sticky" (junk) entities outside the permitted game area.
	for (Entity *ent : topEnts)
	{
		if (ent->sticky)
		{
			if ((ent->getWorldPos().x < minXExtent || ent->getWorldPos().x > maxXExtent)
			|| (ent->getWorldPos().y < minYExtent || ent->getWorldPos().y > maxYExtent))
			{
				FACT->removeEntity(ent);
                //FACT->releaseEntity(ent);
			}
		}
	}

}

void ScoreKeeper::cleanAllJunk() const
{
	//Get all top level entities.
	/*std::vector*/ContLib::LinkedList<Entity*> topEnts = FACT->getTopLevelEntities();

	//Remove all "sticky" (junk) entities.
	for (Entity *ent : topEnts)
	{
		if (ent->sticky)
		{
			FACT->removeEntity(ent);	
            //FACT->releaseEntity(ent);
		}
	}
}

void ScoreKeeper::resetState()
{
	goalMessage = false;

	winnerMessage = false;

	goalTimeEnd = 0.0f;

	winTimeEnd = 0.0f;

	ballCountdownEnd = 0.0f;
}

