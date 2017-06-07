#pragma once
#include "Goalkeeper.h"

/**
* Squids are a Goalkeeper that has a central body and a set of movable limbs.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Squid : public Goalkeeper
{

public:

	/**
	* Default constructor.
	*/
	Squid();

	/**
	* Default destructor.
	*/
	virtual ~Squid();

	/**
	* Squid limb segments.
	*/
	Entity *limb1_1, *limb2_1, *limb3_1, *limb4_1;
	Entity *limb1_2, *limb2_2, *limb3_2, *limb4_2;
	Entity *limb1_3, *limb2_3, *limb3_3, *limb4_3;

	/**
	* Get actor subtype.
	* @returns The actor subtype as defined in enum Ast.
	*/
	virtual inline Ast subType() const { return Ast::Squid; }

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

private:

	/**
	* Limb rotation limits.
	*/
	float limb1RotStartDeg;
	float limb1RotEndDeg;
	float limb2RotStartDeg;
	float limb2RotEndDeg;
	float limb3RotStartDeg;
	float limb3RotEndDeg;
	float limb4RotStartDeg;
	float limb4RotEndDeg;

	/**
	* Limb segment rotation direction.
	*/
	int limb1_1_dir;
	int limb2_1_dir;
	int limb3_1_dir;
	int limb4_1_dir;
	int limb1_2_dir;
	int limb2_2_dir;
	int limb3_2_dir;
	int limb4_2_dir;
	int limb1_3_dir;
	int limb2_3_dir;
	int limb3_3_dir;
	int limb4_3_dir;

	/**
	* Create a new limb segment for a squid.
	* @params addColliders Set true adds colliders for this segment.
	* @returns A pointer to the new limb segment.
	*/
	Entity *newLimbSegment(bool addColliders) const;
};