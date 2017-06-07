#pragma once
#include "Actor.h"

/**
* Goalkeepers are an Actor that moves in front of the goal to prevent a ball from entering it.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Goalkeeper : public Actor
{

public:

	/**
	* Default constructor.
	*/
	Goalkeeper();

	/**
	* Default destructor.
	*/
	virtual ~Goalkeeper();

	/**
	* Get actor type.
	* @returns The actor type as defined in enum At.
	*/
	virtual inline At type() const { return At::Goalkeeper; }

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

};