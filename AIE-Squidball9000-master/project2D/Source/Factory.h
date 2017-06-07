#pragma once
//#include <vector>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include <Mersenne.h>
#include "aieException.h"
#include "Actor.h"
#include "Ball.h"
#include "Multiball.h"
#include "Goalkeeper.h"
#include "Squid.h"
#include "Entity.h"
#include "BasicShape.h"
#include "Soccerball.h"
#include "Paperball1.h"
#include "Pizza1.h"
#include "MonaLisa.h"
#include "Cleaver.h"
#include "Ruler.h"
#include "Computer.h"
#include "Snack.h"
#include "Can.h"
#include "HumanLeft.h"
#include "HumanRight.h"
#include "AISimple.h"
#include "AIMedium.h"
#include "AIHard.h"

#define FACT Factory::getInstance()


/**
* Factory creates and manages objects including Entities, Actors and Players.
* It is responsible for creating these objects on the heap, and removing them when they are no longer needed.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Factory
{

public:

    /**
    * Create or get static instance.
    * @returns A pointer to the single Factory object.
    */
    static Factory *getInstance();

	/*********************************
	* ENTITIES
	**********************************/

	/**
	* Add a new Entity by type. Eg: FACT->addEntity(Et::BasicShape);
    * This will try first to obtain the entity from the pool, or will create
    * a new entity if none of the same type are in the pool.
	* @param type The type of Entity to add.
	* @returns A pointer to the newly created Entity.
	*/
	Entity *addEntity(Entity::Et type);

    ///**
    //* Release an entity back to the entity pool.
    //* @params p Pointer to the entity to release.
    //* @returns void.
    //*/
    //void releaseEntity(Entity *ent);

	/**
	* Remove an existing entity.
	* @param ent A pointer to the entity to remove.
	* @returns void.
	*/
	void removeEntity(Entity *ent);

	/**
	* Remove entities whose expiry time has been reached.
	* @params currentTime The current game time.
	* @returns void.
	*/
	void removeExpiredEntities(float currentTime);

	/**
	* Get a vector array of pointers to top level entities, which are those
	* with no parent.
	* @returns The vector array of pointers to entities.
	*/
	/*std::vector*/ContLib::LinkedList<Entity *> getTopLevelEntities() const;

	/**
	* Get a vector array of pointers to all entities.
	* @returns The vector array of pointers to entities.
	*/
	/*std::vector*/ContLib::LinkedList<Entity *> getAllEntities() const;


	/*********************************
	* ACTORS
	**********************************/

	/**
	* Add a new Actor by subtype. Eg: FACT->addActor(Ast::Planet);
	* @param subType The subtype of Actor to add.
	* @returns A pointer to the newly created Actor.
	*/
	Actor *addActor(Actor::Ast subType);

	/**
	* Remove an existing Actor.
	* @param ent A pointer to the Actor to remove.
	* @returns void.
	*/
	void removeActor(Actor *act);

	/**
	* Get a vector array of pointers to all Actors.
	* @returns The vector array of pointers to Actors.
	*/
	/*std::vector*/ContLib::LinkedList<Actor *> getAllActors() const;

	/**
	* Get number of Actors being tracked by Factory.
	* @returns The number of Actors.
	*/
	int getNumberOfActors() const;

	/**
	* Get a pointer to the Nth Actor in the list of all Actors.
	* Returns nullptr if the index number requested was invalid.
	* @param n The Actor number. Counting starts from 0.
	* @returns A pointer to the Actor.
	*/
	Actor *getActorByNumber(int n) const;

	/**
	* Pointer to ball actor.
	*/
	Actor *ball;


	/*********************************
	* PLAYERS
	**********************************/

	/**
	* Add a new playerLeft player. Replaces any existing playerLeft player.
	* @params subType The player subtype to use.
	* @returns A pointer to the new player.
	*/
	Player *newPlayerLeft(Player::Pst subType);

	/**
	* Add a new playerRight player. Replaces any existing playerRight player.
	* @params subType The player subtype to use.
	* @returns A pointer to the new player.
	*/
	Player *newPlayerRight(Player::Pst subType);

	/**
	* Remove the playerLeft player.
	* @returns void.
	*/
	inline void removePlayerLeft() { if (playerLeft != nullptr) { delete playerLeft; playerLeft = nullptr; } }
	
	/**
	* Remove the playerRight player.
	* @returns void.
	*/
	inline void removePlayerRight() { if (playerRight != nullptr) { delete playerRight; playerRight = nullptr; } }

	/**
	* Pointer to playerLeft player.
	*/
	Player *playerLeft;

	/**
	* Pointer to playerRight player.
	*/
	Player *playerRight;


private:

	/**
	* Default constructor.
	* Private to prevent class being created on the stack.
	*/
	Factory();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
    ~Factory();

	/**
	* Mersenne Twister random number generator.
	*/
	Mersenne mt;

    /**
    * Vector array of pointers to Entities.
    */
	/*std::vector*/ContLib::LinkedList<Entity *> entities;

	/**
	* Vector array of pointers to Actors.
	*/
	/*std::vector*/ContLib::LinkedList<Actor *> actors;

};