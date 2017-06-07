#pragma once
#include "Ball.h"


/**
* Multiball is a Ball that has a central circle entity, which may have other junk entities stuck to it
* that it collects as it collides with them while moving around.
* The Multiball maintains a set speed which slowly increases during each round.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Multiball : public Ball
{

public:

	/**
	* Default constructor.
	*/
	Multiball();

	/**
	*Default destructor.
	*/
	virtual ~Multiball();

	/**
	* Get actor subtype.
	* @returns The actor subtype as defined in enum Ast.
	*/
	virtual inline Ast subType() const { return Ast::Multiball; }

	/**
	* Perform actor actions.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt);

	/**
	* Perform actor physics actions.
	* Pure virtual function.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void updatePhysics(float dt);

	/**
	* Explode into component parts, each of which auto remove themselves from the scene after a set time.
	* Pure virtual function.
	* @returns void.
	*/
	virtual void explode();

};