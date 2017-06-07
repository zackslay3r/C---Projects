#pragma once
//#include <vector>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include <Mersenne.h>
#include "aieException.h"
#include "Entity.h"
#include "CollisionDetector.h"


#define PHYS PhysicsCalculator::getInstance()


/**
* PhysicsCalculator calculates the physics behavior of entities.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class PhysicsCalculator
{

public:

	/**
	* Gravity constant.
	*/
	const Vector2 gravity = Vector2(0.0f, 0.0f);

	/**
	* Epsilon is the smallest number we can consider zero.
	* This helps deal with floating point error.
	*/
	const float EPSILON = 0.0001f;

	/**
	* Compare two floats within the tolerance of EPSILON.
	* @params a The first value to compare.
	* @params b The second value to compare.
	* @returns True if the values are equal (within the given tolerance). False if not.
	*/
	inline bool equal(float a, float b) const { return std::abs(a - b) <= EPSILON; }

	/**
	* Derivative struct used for feedback in the Runge-Kutta 4th order integration method.
	*/
	struct Derivative
	{
		Derivative() : dx(0.0f), dxv(0.0f), dy(0.0f), dyv(0.0f), dr(0.0f), drv(0.0f) { }
		float dx, dxv, dy, dyv, dr, drv;
	};

    /**
    * Create or get static instance.
    * @returns A pointer to the single PhysicsCalculator object.
    */
    static PhysicsCalculator *getInstance();

	/**
	* Perform evaluations for a physics object state.
	* @param initial The entity to evaluate.
	* @param t Current time.
	* @param dt Fixed deltaTime.
	* @param d The derivative to use for feedback.
	* @returns void.
	*/
	Derivative rk4Evaluate(const Entity *initial, float t, float dt, const Derivative &d) const;

	/**
	* Perform integration calculations for a physics object state.
	* Uses a variation of the Runge-Kutta 4th order method:
	* https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods
	* https://en.wikipedia.org/wiki/List_of_Runge%E2%80%93Kutta_methods#Classic_fourth-order_method
	* Entity is passed by reference so it directly updates the given entity.
	* @param state The entity to integrate.
	* @param t Current time.
	* @param dt Fixed deltaTime.
	* @returns void.
	*/
	void rk4Integrate(Entity *state, float t, float dt) const;

	/**
	* Integrate acceleration, velocity and position (rotational and linear) using the Euler method.
	* @params ent The entity to update.
	* @params dt The delta time since last physics update.
	* @returns void.
	*/
	void eulerIntegrate(Entity * ent, float dt) const;

	/**
	* Resolve collision and apply forces for a pair of colliding entities.
	* Based on concepts from:
	* https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331
	* https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table--gamedev-7756
	* https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-core-engine--gamedev-7493
	* http://www.randygaul.net/2013/03/27/game-physics-engine-part-1-impulse-resolution/
	* http://buildnewgames.com/gamephysics/
	* @params satPair The pair of colliding entities identified by the SAT test, defined by a SATCollidingPairs struct.
	* @returns void.
	*/
	void resolveCollision(CollisionDetector::SATCollidingPairs &satPair) const;

	/**
	* Apply instantaneous velocity changes to an entity via a force.
	* @params pEnt Pointer to the Entity.
	* @params force The force vector to exert.
	* @params com The vector from entity centre of mass, to the contact point where the force is being applied.
	* @returns void.
	*/
	void applyImpulse(Entity *pEnt, const Vector2 &force, const Vector2 &com) const;

	/**
	* Vector2 times scalar. 2D cross product functions using scalars.
	* These are specialised meanings of "Cross" in 2D space, created for this simulation, and so not part of the MathsLib library.
	* @params v The vector.
	* @params a The scalar.
	* @returns The new cross product vector.
	*/
	inline Vector2 cross(const Vector2& v, float a) const {	return Vector2(a * v.y, -a * v.x); }
	
	/**
	* Scalar times vector. 2D cross product functions using scalars.
	* These are specialised meanings of "Cross" in 2D space, created for this simulation, and so not part of the MathsLib library.
	* @params a The scalar.
	* @params v The vector.
	* @returns The new cross product vector.
	*/
	inline Vector2 cross(float a, const Vector2& v) const { return Vector2(-a * v.y, a * v.x); }

private:

	/**
	* Default constructor.
	* Private to prevent class being created on the stack.
	*/
	PhysicsCalculator();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
    ~PhysicsCalculator();

	/**
	* Mersenne Twister random number generator.
	*/
	Mersenne mt;

};