#pragma once
#include <Mersenne.h>
#include "Actor.h"



/**
* Player is the essential AI or Human controlled object that directs movement of
* a goalkeeper (an Actor class) in the game world.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Player
{
public:
	/**
	* Default constructor.
	*/
	Player();

	/**
	* Default destructor.
	*/
	virtual ~Player();

	/**
	* Player types.
	*/
	enum class Pt { Human, AI };

	/**
	* Player subtypes.
	*/
	enum class Pst { AISimple, AIMedium, AIHard, HumanLeft, HumanRight };

	/**
	* The actor attached to this player.
	*/
	Actor *actor;

	/**
	* The X position to clamp to.
	*/
	float clampX;

	/**
	* The minimum Y position to clamp to.
	*/
	float clampYMin;

	/**
	* The maximum Y position to clamp to.
	*/
	float clampYMax;

	/**
	* Get player type.
	* Pure virtual function.
	* @returns The player type as defined in enum Pt.
	*/
	virtual Pt type() const = 0;

	/**
	* Get player subtype.
	* Pure virtual function.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual Pst subType() const = 0;

	/**
	* Move player up.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	void moveUp(float dt) const;

	/**
	* Move player down.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	void moveDown(float dt) const;

	/**
	* Stop player moving.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	void moveStop(float dt) const;

	/**
	* Perform player actions.
	* Pure virtual function.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt) = 0;

protected:

	/**
	* Mersenne twister random number generator.
	*/
	Mersenne mt;

};