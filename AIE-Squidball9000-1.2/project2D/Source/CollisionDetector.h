#pragma once
//#include <vector>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include <Mersenne.h>
#include <MathsLib.h>
#include "aieException.h"
#include "Entity.h"
#include "Factory.h"


#define COLL CollisionDetector::getInstance()


/**
* CollisionDetector calculates collision points between entities.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class CollisionDetector
{

public:

	/**
	* Struct of pairs of colliding entities in a broadphase 
	* Axis Aligned Bounding Box (AABB) test.
	*/
	struct AABBCollidingPairs
	{
		inline AABBCollidingPairs() { A = B = nullptr; };
		Entity *A;
		Entity *B;
	};

	/**
	* Struct of pairs of colliding entities in a 
	* Separating Axis Theorem (SAT) test.
	*/
	struct SATCollidingPairs
	{
		inline SATCollidingPairs() { A = B = nullptr; penetration = 0.0f; normal = Vector2(); e = df = sf = 0.0f; };
		Entity *A;
		Entity *B;
		float penetration;
		Vector2 normal;
		Vector2 contactWorldPos;
		int contactCount;
		float e;  //Combined restitution
		float df; //Combined dynamic friction
		float sf; //Combined static friction
	};

	/**
	* Struct for axis dot product projection value pairs.
	*/
	struct Projection
	{
		inline Projection() { min = max = 0.0f; }
        inline Projection(float a, const Vector2 &aV, float b, const Vector2 &bV) { min = a; max = b; minV = aV; maxV = bV; };
		float min;
		float max;
        Vector2 minV;
        Vector2 maxV;
	};

    /**
    * Create or get static instance.
    * @returns A pointer to the single Factory object.
    */
    static CollisionDetector *getInstance();

	/**
	* Get a vector array of objects that are colliding according to the AABB method.
	* @returns A vector array of any colliding pairs, encapsulated in a AABBCollidingPairs struct.
	*/
	/*std::vector*/ContLib::LinkedList<AABBCollidingPairs> getAABBCollidingEntities() const;

	/**
	* Calculate the SAT test axes normals for a shape.
	* These axes are normalised before being returned.
	* @params shape The shape to generate the axes from.
	* @returns A vector array of axes to use for SAT tests on this shape.
	*/
	/*std::vector*/ContLib::LinkedList<Vector2> getNormalSATAxes(const Shape2 &shape) const;
	
	/**
	* Calculate the min and max dot product values of the projection of a shape onto an axis.
	* Note the axis must be normalised.
	* @params shape The shape to project.
	* @params axis The axis to project on to.
	* @returns A Projection struct containing the min and max dot product values of the projection.
	*/
	Projection axisDotProductProject(const Shape2 &shape, const Vector2 &axis) const;

	/**
	* Check if SAT axis projection 1 contains SAT axis projection 2.
	* Containments means projection 2 is entirely inside projection 1.
	* @params proj1 Projection 1.
	* @params proj2 Projection 2.
	* @returns True if projection 1 contains projection 2. False if not.
	*/
	bool checkContainment(const CollisionDetector::Projection & proj1, const CollisionDetector::Projection & proj2) const;
	
	/**
	* Check if SAT axis projection 1 overlaps SAT axis projection 2.
	* @params proj1 Projection 1.
	* @params proj2 Projection 2.
	* @returns True if projection 1 overlaps projection 2. False if not.
	*/
	bool checkOverlap(const CollisionDetector::Projection & proj1, const CollisionDetector::Projection & proj2) const;

	/**
	* Get the overlap distance between SAT axis projection 1 and SAT axis projection 2.
	* @params proj1 Projection 1.
	* @params proj2 Projection 2.
	* @returns The overlap distance.
	*/
	float getOverlap(const CollisionDetector::Projection & proj1, const CollisionDetector::Projection & proj2) const;

    /**
    * Get the support points of a shape at the max distance along a vector.
    * @params sh A pointer to the shape to get support points for.
    * @params dir The vector to use when calculating the support points.
    * @returns The support points as a vector array.
    */
	/*std::vector*/ContLib::LinkedList<Vector2> getMaxSupports(const Shape2 *sh, const Vector2 &dir) const;

	/**
	* Get data about any collision between two entities, according to the SAT method.
	* Based on ideas from:
	* http://www.metanetsoftware.com/technique/tutorialA.html#section1
	* http://www.phailed.me/2011/02/polygonal-collision-detection/
	* http://buildnewgames.com/gamephysics/
	* http://www.metanetsoftware.com/2016/n-tutorial-a-collision-detection-and-response
	* https://gamedevelopment.tutsplus.com/tutorials/collision-detection-using-the-separating-axis-theorem--gamedev-169
	* http://www.dyn4j.org/2010/01/sat/#sat-notes
	* @params pair The entities to compare, stored in an AABBCollidingPairs struct.
	* @returns Data about the first detected collision between the entities, encapsulated in a SATCollidingPairs struct,
	* or a SATCollidingPairs struct with nullptr for values A and B if no collisions were found.
	*/
	SATCollidingPairs getSATCollidingEntities(const CollisionDetector::AABBCollidingPairs &pair) const;

	/**
	* Draw a contact point marker at a location, that disappears automatically after an amount of time.
	* @params point The location in world space to draw the contact point.
	* @returns void.
	*/
	void drawContactPoint(const Vector2 &point) const;

private:

	/**
	* Default constructor.
	* Private to prevent class being created on the stack.
	*/
	CollisionDetector();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
    ~CollisionDetector();

	/**
	* Mersenne Twister random number generator.
	*/
	Mersenne mt;

};