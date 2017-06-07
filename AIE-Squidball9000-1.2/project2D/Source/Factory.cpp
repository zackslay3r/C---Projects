#include "Factory.h"
#include "Settings.h"
//#include "EntityPool.h"

Factory::Factory()
{
	entities = ContLib::LinkedList<Entity *>();
	actors = ContLib::LinkedList<Actor *>();

	ball = nullptr;
	playerLeft = nullptr;
	playerRight = nullptr;
}

Factory::~Factory()
{

	removePlayerLeft();

	removePlayerRight();

	//Delete all Actors on the heap. Use a COPY as we are removing things from the list as we loop over it.
	std::vector<Actor *> actorsCopy;
	for (auto &var : actorsCopy)
	{
		removeActor(var);
	}

	//Delete all top level Entities on the heap.
	//Sub entities will be romed automatically as their parent is removed.
	/*std::vector*/ContLib::LinkedList<Entity *> entitiesCopy = getTopLevelEntities();
	for (auto &var : entitiesCopy)
	{
		removeEntity(var);
	}

}

Factory *Factory::getInstance()
{
    static Factory Factory;

    return &Factory;
}

Entity *Factory::addEntity(Entity::Et type)
{

    Entity *p;

    ////Check if an entity of this type is available in the entity pool.
    //if (EPOOL->count(type))
    //{
    //    //Pop the entity off the pool stack.
    //    p = EPOOL->getEntityFromPool(type);
    //}
    //else
    //{
        //Create object of selected subtype.
        switch (type)
        {
        case Entity::Et::BasicShape:
            p = new BasicShape;
            break;
        case Entity::Et::Soccerball:
            p = new Soccerball;
            break;
        case Entity::Et::Paperball1:
            p = new Paperball1;
            break;
        case Entity::Et::Pizza1:
            p = new Pizza1;
            break;
        case Entity::Et::MonaLisa:
            p = new MonaLisa;
            break;
        case Entity::Et::Cleaver:
            p = new Cleaver;
            break;
        case Entity::Et::Ruler:
            p = new Ruler;
            break;
        case Entity::Et::Computer:
            p = new Computer;
            break;
        case Entity::Et::Snack:
            p = new Snack;
            break;
        case Entity::Et::Can:
            p = new Can;
            break;
        default:
            //Type not defined here.
            aieTHROW("Invalid entity type requested.");
            break;
        }
    //}
	//Add Entity to the vector array of entities.
	entities.push_back(p);

	return p;
}

//void Factory::releaseEntity(Entity *ent)
//{
//    //Search for the entity in the vector array.
//    /*std::vector<Entity *>::iterator*/ ContLib::LinkedListIterator<Entity *> it = std::find(entities.begin(), entities.end(), ent);
//
//    //If we couldn't find this entity in the vector array, abort.
//    if (it == entities.end()) return;
//
//    //Remove item from the entities list.
//    entities.erase(it);
//
//    //Reset the entity back to a default state.
//    ent->resetExisting();
//
//    //Place the entity into the pool for re-use.
//    EPOOL->addEntityToPool(ent);
//}

void Factory::removeEntity(Entity *ent)
{
	    //Search for the entity in the vector array.
	    /*std::vector<Entity *>::iterator*/ ContLib::LinkedListIterator<Entity *> it = std::find(entities.begin(), entities.end(), ent);
	
		//If we couldn't find this entity in the vector array, abort.
		if (it == entities.end()) return;
	
		//Remove item from the entities list.
		entities.erase(it);
	
	    //Delete the object from the heap.
	    delete ent;
	    ent = nullptr;
}

void Factory::removeExpiredEntities(float currentTime)
{
	//Get top level entities only.
	//Only top level entities can act on their expiry time, to prevent
	//children trying to remove themselves.
	/*std::vector*/ContLib::LinkedList<Entity*> entitiesCopy = FACT->getTopLevelEntities();

	//Loop over the COPY vector array.
	for (auto &var : entitiesCopy)
	{
		//Skip entities with a life tgime of 0. this means their timer is not active.
		if (var->lifeTimeExpiry == 0) continue;

		//Remove element from the ORIGINAL vector array.
		if (var->lifeTimeExpiry < currentTime)
		{
			FACT->removeEntity(var);
            //FACT->releaseEntity(var);
		}
	}
}

/*std::vector*/ContLib::LinkedList<Entity*> Factory::getTopLevelEntities() const
{
	/*std::vector*/ContLib::LinkedList<Entity*> ents;

	for (Entity* var : entities)
	{
		//Add all top level entities (those with no parents) to the vector array.
		if (var->parent == nullptr) ents.push_back(var);
	}

	return ents;
}

/*std::vector*/ContLib::LinkedList<Entity*> Factory::getAllEntities() const
{
	return entities;
}

Actor *Factory::addActor(Actor::Ast subType)
{
	Actor *p;

	//Create object of selected subtype.
	switch (subType)
	{
	case Actor::Ast::Multiball:
		p = new Multiball;
		break;
	case Actor::Ast::Squid:
		p = new Squid;
		break;
	default:
		//Subtype not defined here.
		aieTHROW("Invalid actor subtype requested.");
		break;
	}

	//Add Actor to the vector array of entities.
	actors.push_back(p);

	return p;
}

void Factory::removeActor(Actor *act)
{
	//Search for the actor in the vector array.
	/*std::vector<Actor *>::iterator*/ ContLib::LinkedListIterator<Actor *> it = std::find(actors.begin(), actors.end(), act);

	//If we couldn't find this actor in the vector array, abort.
	if (it == actors.end()) return;

	//Remove item from the things list of its type.
	actors.erase(it);

	//Delete the object from the heap.
	delete act;
	act = nullptr;
}

/*std::vector*/ContLib::LinkedList<Actor*> Factory::getAllActors() const
{
	return actors;
}

int Factory::getNumberOfActors() const
{
	return actors.size();
}

Actor *Factory::getActorByNumber(int n) const
{
	if (n < 0 || n >(int)actors.size() - 1) return nullptr;
	return actors[n];
}

Player * Factory::newPlayerLeft(Player::Pst subType)
{

	if (playerLeft != nullptr)
	{
		delete playerLeft;
		playerLeft = nullptr;
	}

	switch (subType)
	{
	case Player::Pst::HumanLeft:
		playerLeft = new HumanLeft;
		break;
	case Player::Pst::AISimple:
		playerLeft = new AISimple;
		break;
	case Player::Pst::AIMedium:
		playerLeft = new AIMedium;
		break;
	case Player::Pst::AIHard:
		playerLeft = new AIHard;
		break;
	default:
		aieTHROW("Invalid player type for playerLeft.");
		break;
	}

	playerLeft->clampX = 150.0f;
	playerLeft->clampYMin = 240.0f;
    playerLeft->clampYMax = (float)SETT->screenHeight - 75.0f;

	return playerLeft;
}

Player * Factory::newPlayerRight(Player::Pst subType)
{

	if (playerRight != nullptr)
	{
		delete playerRight;
		playerRight = nullptr;
	}

	switch (subType)
	{
	case Player::Pst::HumanRight:
		playerRight = new HumanRight;
		break;
	case Player::Pst::AISimple:
		playerRight = new AISimple;
		break;
	case Player::Pst::AIMedium:
		playerRight = new AIMedium;
		break;
	case Player::Pst::AIHard:
		playerRight = new AIHard;
		break;
	default:
		aieTHROW("Invalid player type for playerRight.");
		break;
	}

	playerRight->clampX = (float)SETT->screenWidth - 150.0f;
	playerRight->clampYMin = 240.0;
	playerRight->clampYMax = playerLeft->clampYMax = (float)SETT->screenHeight - 75.0f;

	return playerRight;
}
