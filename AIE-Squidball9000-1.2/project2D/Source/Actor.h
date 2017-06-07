#pragma once
#include "aieException.h"
#include "Entity.h"

/**
* Forward declarations.
*/
class Player;

/**
* Actors are objects composed of entities, that have a defined behaviour such as the way they move or
* interact with their environment. Actors may be under the control of human players or the AI.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Actor
{

public:

	/**
	* Default constructor.
	*/
	Actor();

	/**
	* Default destructor.
	*/
	virtual ~Actor();

	/**
	* Actor types.
	*/
	enum class At { Ball, Goalkeeper };

	/**
	* Actor subtypes.
	*/
	enum class Ast { Multiball, Squid };

	/**
	* Root entity that represents the centre of the actor, and responds to all physics reactions.
	*/
	Entity *rootEntity;

	/**
	* Player this actor belongs to, if any.
	*/
	Player *player;

	/**
	* Is this actor active?
	*/
	bool active;

	/**
	* Current maximum velocity this actor may move at.
	*/
	float maxVelocity;

	/**
	* Maximum velocity this actor may move at.
	* Used as the default when maxVelocity is reset.
	*/
	float baseMaxVelocity;

	/**
	* Set this actor's root entity moving in a random direction, favouring a flattened 
	* X-axis bias to ensure a "mostly left or right" direction, at a given speed.
	* @params speed The max speed to use.
	* @returns void.
	*/
	void randomDirection(float speed) const;

	/**
	* Get actor type.
	* Pure virtual function.
	* @returns The actor type as defined in enum At.
	*/
	virtual At type() const = 0;

	/**
	* Get actor subtype.
	* Pure virtual function.
	* @returns The actor subtype as defined in enum Ast.
	*/
	virtual Ast subType() const = 0;

	/**
	* Perform actor actions.
	* Pure virtual function.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt) = 0;

	/**
	* Perform actor physics actions.
	* Pure virtual function.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void updatePhysics(float dt) = 0;

	/**
	* Explode into component parts, each of which auto remove themselves from the scene after a set time.
	* Pure virtual function.
	* @returns void.
	*/
	virtual void explode() = 0;

protected:

	/**
	* Mersenne twister random number generator.
	*/
	Mersenne mt;
    
};