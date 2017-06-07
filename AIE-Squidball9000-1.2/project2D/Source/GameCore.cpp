#include "Menu.h"
#include "AssetManager.h"
#include "ScoreKeeper.h"
#include "PhysicsCalculator.h"
#include "GameStateManager.h"
#include "GameCore.h"
#include "Menu.h"
#include "Settings.h"

GameCore::GameCore()
{
    //Application pointer.
    app = nullptr;

    //Menu input handler.
    input = aie::Input::getInstance();

    t = 0.0;
    dt = 1.0f / 60.0f; //Maximum physics frame rate. NOTE: Only applies when vsync is OFF.
    fpsMax = (int)SETT->refreshRate;
    maxDt = 1.0f / 30.0f; //Minimum physics frame rate.
    currentTime = 0.0;
    accumulator = 0.0;
}

GameCore::~GameCore()
{
}

GameCore *GameCore::getInstance()
{
    static GameCore gameCore;

    return &gameCore;
}

void GameCore::update()
{
    //Set menu visible if M key is pressed.
    if (MENU->mToggle && input->isKeyDown(aie::INPUT_KEY_M))
    {
        MENU->mToggle = false;

        //Remove game draw and update states from active list.
        GSM->removeState("UpdatePlay");

        //Add menu state to active list.
        GSM->activateState("MenuMain");
    }

    //Reset menu toggle state.
    if (input->isKeyUp(aie::INPUT_KEY_M)) MENU->mToggle = true;

    //Physics timestep based on concepts from http://gafferongames.com/game-physics/fix-your-timestep/

    //Increment game timer.
    GCLK->incrementTime();

    double newTime = GCLK->getTimeSeconds();
    double frameTime = newTime - currentTime;

    //Limit max time that is allowed to pass between frames.
    if (frameTime > maxDt)
        frameTime = maxDt;

    currentTime = newTime;

    accumulator += frameTime;

    if ((int)app->getFPS() > fpsMax) fpsMax = app->getFPS();

    dt = 1.0f / fpsMax;

    while (accumulator >= dt)
    {

        /**
        * Remove any entities whose lifetime has expired.
        */

        FACT->removeExpiredEntities((float)t);

        /**
        * Get current vector arrays of entities.
        */
        /*std::vector*/ContLib::LinkedList<Entity*> topEnts = FACT->getTopLevelEntities();
        /*std::vector*/ContLib::LinkedList<Entity*> allEnts = FACT->getAllEntities();

        /**
        * Detect collisions.
        */

        /*std::vector*/ContLib::LinkedList<CollisionDetector::AABBCollidingPairs> aabbPairs;
        /*std::vector*/ContLib::LinkedList<CollisionDetector::SATCollidingPairs> allSATPairs;

        //Collision check broad phase - fast AABB test.
        //This gets all pairs of objects that may be intersecting via Axis Aligned Bounding Boxes.
        aabbPairs = COLL->getAABBCollidingEntities();

        //Collision check narrow phase - slow SAT test.
        //Check each identified pair using the accurate but slow Separating Axis Theorem test.
        for (auto &aabbPair : aabbPairs)
        {
            //Two immovable objects shouldn't have collisions resolved.
            if (aabbPair.A->root->inverseMass == 0 && aabbPair.B->root->inverseMass == 0) continue;

            //Get identified pairs and their collision data.
            CollisionDetector::SATCollidingPairs satPair = COLL->getSATCollidingEntities(aabbPair);
            if (satPair.A != nullptr && satPair.B != nullptr) allSATPairs.push_back/*emplace_back*/(satPair);
        }

        /**
        * Initialise collisions.
        */

        for (auto &satPair : allSATPairs)
        {
            //Use the minimum restitution of either object.
            satPair.e = std::min(satPair.A->root->restitution, satPair.B->root->restitution);

            //Determine friction.
            //See https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table--gamedev-7756
            satPair.sf = std::sqrt(satPair.A->root->staticFriction * satPair.A->root->staticFriction
                + satPair.B->root->staticFriction * satPair.B->root->staticFriction);
            satPair.df = std::sqrt(satPair.A->root->dynamicFriction * satPair.A->root->dynamicFriction
                + satPair.B->root->dynamicFriction * satPair.B->root->dynamicFriction);

            //////////
            // Gravity is DISABLED.
            //////////

            ////Calculate distance from COM to contact.
            //Vector2 ra = satPair.contactWorldPos - satPair.A->root->getWorldPos();
            //Vector2 rb = satPair.contactWorldPos - satPair.B->root->getWorldPos();

            //Vector2 rv = satPair.B->root->velocity + PHYS->cross(satPair.B->root->angVelocity, rb) -
            //	satPair.A->root->velocity - PHYS->cross(satPair.A->root->angVelocity, ra);

            ////If the only force acting on this object is gravity, then use a restitution of 0.
            //if (rv.magnitudeSqr() < ((float)dt * PHYS->gravity).magnitudeSqr() + PHYS->EPSILON)
            //	satPair.e = 0.0f;

        }

        /**
        * Solve collisions.
        * Recursively iterate this between 10 and 100 times for greater accuracy.
        */
        for (int iters = 0; iters < 1; ++iters)
        {
            for (auto &satPair : allSATPairs)
            {
                PHYS->resolveCollision(satPair);
            }
        }

        //Call update function for all actors.
        for (Actor *var : FACT->getAllActors())
        {
            var->updatePhysics((float)dt);
        }

        /**
        * Integrate velocities.
        */

        //RK4 integration based on http://gafferongames.com/game-physics/integration-basics/

        //Loop through all physics objects and integrate their velocities.
        //Only top level entities have physics.
        for (Entity* var : topEnts)
        {

            if (var->inverseMass == 0.0f || !var->active) continue;

            //RK4 method.
            PHYS->rk4Integrate(var, (float)t, (float)dt);

            //Euler's method.
            //PHYS->eulerIntegrate(var, (float)dt);

            //Update our matrix and all child matrices.
            var->updateMatrixHeirarchy();
        }

        //Call update function for all actors.
        for (Actor *var : FACT->getAllActors())
        {
            var->updatePhysics((float)dt);
        }

        /**
        * Correct positions of all colliding objects.
        */

        for (auto &satPair : allSATPairs)
        {

            //Only move active entities.
            if (!satPair.A->root->active || !satPair.B->root->active) continue;

            //Don't try to move objects that belong to the same parent entity.
            if (satPair.A->root == satPair.B->root) continue;

            float invMassSum = satPair.A->root->inverseMass + satPair.B->root->inverseMass;

            //Calculate minimum separation vector with magnitude.
            Vector2 mtv = satPair.normal * satPair.penetration;

            //Share the movement between the objects as a ration of their mass.
            float aRatio = satPair.A->root->inverseMass / invMassSum;
            float bRatio = satPair.B->root->inverseMass / invMassSum;

            //Only objects with mass can be moved.
            if (satPair.A->root->inverseMass)
            {
                //Move objects apart.
                satPair.A->root->addToLocalPosition(mtv * -aRatio);

                //Objects with no velocity should be moved a minimum possible extra distance so 
                //contact is no longer being made.
                if (satPair.A->root->velocity.magnitudeSqr() <=
                    PHYS->EPSILON*PHYS->EPSILON) satPair.A->root->addToLocalPosition(mtv * -PHYS->EPSILON);
            }

            //Only objects with mass can be moved.
            if (satPair.B->root->inverseMass)
            {
                //Move objects apart.
                satPair.B->root->addToLocalPosition(mtv * bRatio);

                //Objects with no velocity should be moved a minimum possible extra distance so 
                //contact is no longer being made.
                if (satPair.B->root->velocity.magnitudeSqr() <=
                    PHYS->EPSILON*PHYS->EPSILON) satPair.B->root->addToLocalPosition(mtv * PHYS->EPSILON);
            }

            satPair.A->root->updateMatrixHeirarchy();
            satPair.B->root->updateMatrixHeirarchy();
        }

        //Call update function for all actors.
        for (Actor *var : FACT->getAllActors())
        {
            var->updatePhysics((float)dt);
        }

        /**
        * Clear all forces.
        */

        for (Entity* var : topEnts)
        {
            var->force = Vector2();
            var->torque = 0.0f;
        }

        /**
        * Updates
        */

        //Call update function for all entities.
        for (Entity *var : FACT->getAllEntities())
        {
            //Update this entity, and recursively update all its children.
            var->update(true);
        }

        //Call update function for all actors.
        for (Actor *var : FACT->getAllActors())
        {
            var->update((float)dt);
        }

        //Call update for all players.
        if (FACT->playerLeft != nullptr) FACT->playerLeft->update((float)dt);
        if (FACT->playerRight != nullptr) FACT->playerRight->update((float)dt);

        //Scoreboard update.
        SCOR->update((float)dt);

        /**
        * Timer and accumulator.
        */

        //Increment time.
        t += dt;
        //Consume time from accumulator.
        accumulator -= dt;

    }
}

void GameCore::draw()
{

    float depthTextHelp = 3.0f;

    //Faint background title.
    app->m_2dRenderer->setRenderColour(0.3f, 0.3f, 0.3f, 0.1f);

    char title[32];
    sprintf_s(title, 32, "%s", "SQUIDBALL 9000");
    app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 172), title, 
        (float)(SETT->screenWidth - 1420) / 2, 100, depthTextHelp);

    //Onscreen key decriptions.
    char keyHelp[32];
    app->m_2dRenderer->setRenderColour(0.4f, 0.4f, 0.4f, 0.5f);

    //Left
    if (MENU->playerLeftSetting == Menu::PlayerSettings::Human)
    {
        sprintf_s(keyHelp, 32, "%s", "W key / S key");
        app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 32), keyHelp, 50, 40, depthTextHelp);
    }
    //Right
    if (MENU->playerRightSetting == Menu::PlayerSettings::Human)
    {
        sprintf_s(keyHelp, 32, "%s", "Up / Down arrows");
        app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 32), keyHelp, 
            (float)(SETT->screenWidth - 350), 40, depthTextHelp);
    }

    //Onscreen player decriptions.
    char playerDesc[32];
    std::string playerDescString;
    app->m_2dRenderer->setRenderColour(0.4f, 0.4f, 0.4f, 0.5f);

    //Left
    switch (MENU->playerLeftSetting)
    {
    case Menu::PlayerSettings::Human:
        playerDescString = "Human";
        break;
    case Menu::PlayerSettings::AIEasy:
        playerDescString = "Easy AI";
        break;
    case Menu::PlayerSettings::AIMedium:
        playerDescString = "Medium AI";
        break;
    case Menu::PlayerSettings::AIHard:
        playerDescString = "Hard AI";
        break;
    default:
        aieTHROW("ERROR: Unknown player setting.");
        break;
    }

    sprintf_s(playerDesc, 32, "%s", playerDescString.c_str());
    app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 32), playerDesc, 50, 70, depthTextHelp);

    //Right
    switch (MENU->playerRightSetting)
    {
    case Menu::PlayerSettings::Human:
        playerDescString = "    Human";
        break;
    case Menu::PlayerSettings::AIEasy:
        playerDescString = "  Easy AI";
        break;
    case Menu::PlayerSettings::AIMedium:
        playerDescString = "Medium AI";
        break;
    case Menu::PlayerSettings::AIHard:
        playerDescString = "  Hard AI";
        break;
    default:
        aieTHROW("ERROR: Unknown player setting.");
        break;
    }

    sprintf_s(playerDesc, 32, "%s", playerDescString.c_str());
    app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 32), playerDesc, 
        (float)(SETT->screenWidth - 220), 70, depthTextHelp);

    //Winning goals hint.
    app->m_2dRenderer->setRenderColour(0.6f, 0.6f, 0.6f, 0.6f);
    char win[32];
    sprintf_s(win, 32, "%s", (std::to_string(SCOR->winScore) + " to win").c_str());
    app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 24), win, 
        (float)(SETT->screenWidth - 100) / 2, (float)(SETT->screenHeight - 85), depthTextHelp);

    //Menu message.
    app->m_2dRenderer->setRenderColour(0.4f, 0.4f, 0.4f, 0.5f);
    char menu[32];
    sprintf_s(menu, 32, "%s", "M - MENU / PAUSE");
    app->m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 32), menu, 
        (float)(SETT->screenWidth - 300) / 2, 40, depthTextHelp);

    //Scoreboard draw.
    SCOR->draw(app->m_2dRenderer);

    //Call draw function for all entities.
    /*std::vector*/ContLib::LinkedList<Entity*> ents = FACT->getTopLevelEntities();
    for (Entity* var : ents)
    {
        //Draw this entity, and recursively draw all its children.
        var->draw(true, app->m_2dRenderer);
    }


    ////Display FPS
    //m_2dRenderer->setRenderColour(0.6f, 0.6f, 0.6f, 0.6f);
    //char fps[32];
    //sprintf_s(fps, 32, "FPS: %i", getFPS());
    //m_2dRenderer->drawText(AMAN->getFont("/font/OCRAEXT.TTF", 24), fps, 30, (float)SETT->screenHeight - 60.0f, 11);
}

void GameCore::initialise()
{
	////////////////
	//Set up walls.
	////////////////

	float sizeX;
	float sizeY;
	Entity::RenderShape rs;

	//Bottom wall.
	Entity *pBwall;
	pBwall = FACT->addEntity(Entity::Et::BasicShape);
	sizeX = 10000.0f;
	sizeY = 500.0f;
	pBwall->colliderShapes = { Shape2({ Vector2(-sizeX, sizeY), Vector2(sizeX, sizeY), Vector2(sizeX, -sizeY), Vector2(-sizeX, -sizeY) }) };
	for (auto &var : pBwall->colliderShapes) var.updateNormals();
	rs.shape = Shape2({ Vector2(-sizeX, sizeY), Vector2(sizeX, sizeY), Vector2(sizeX, -sizeY), Vector2(-sizeX, -sizeY) });
	rs.colour = Colour(0.0f, 1.0f, 0.0f, 0.8f);
	rs.lineThickness = 2.0f;
	pBwall->renderShapes = { rs };
	for (auto &var : pBwall->renderShapes) var.shape.updateNormals();
	pBwall->rotatable = false;
	pBwall->updateAABBFromColliders();
	pBwall->setMass(0.0f);
	//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
	pBwall->setLocalPosition(Vector2(-5000.0f + ((float)SETT->screenWidth / 2.0f), -480.0f));

	//Top wall.
	Entity *pTwall;
	pTwall = FACT->addEntity(Entity::Et::BasicShape);
	sizeX = 10000.0f;
	sizeY = 500.0f;
	pTwall->colliderShapes = { Shape2({ Vector2(-sizeX, sizeY), Vector2(sizeX, sizeY), Vector2(sizeX, -sizeY), Vector2(-sizeX, -sizeY) }) };
	for (auto &var : pTwall->colliderShapes) var.updateNormals();
	rs.shape = Shape2({ Vector2(-sizeX, sizeY), Vector2(sizeX, sizeY), Vector2(sizeX, -sizeY), Vector2(-sizeX, -sizeY) });
	rs.colour = Colour(0.0f, 1.0f, 0.0f, 0.8f);
	rs.lineThickness = 2.0f;
	pTwall->renderShapes = { rs };
	for (auto &var : pTwall->renderShapes) var.shape.updateNormals();
	pTwall->rotatable = false;
	pTwall->updateAABBFromColliders();
	pTwall->setMass(0.0f);
	//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
	pTwall->setLocalPosition(Vector2(-5000.0f + ((float)SETT->screenWidth / 2.0f), (float)SETT->screenHeight + 480.0f));

	////////////////
	//Set up ball.
	////////////////

	FACT->ball = FACT->addActor(Actor::Ast::Multiball);
	FACT->ball->rootEntity->active = false;
	FACT->ball->rootEntity->visible = false;
}
