#pragma once
//#include <vector>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include <algorithm>
#include <string>
#include <Mersenne.h>
#include <MathsLib.h>
#include "aieException.h"
#include "Renderer2D.h"
#include "GameClock.h"



/**
* Entity is the root class for all derived entity objects that exist physically in world space.
* Entities are the most basic object that can exist in world space. Other more complex objects
* such as Actors are composed of Entities.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Entity
{
public:
	
	/**
	* Default constructor.
	*/
	Entity();

	/**
	* Default destructor.
	*/
	virtual ~Entity();

	/**
	* Entity types.
	*/
	enum class Et { BasicShape, Soccerball, Paperball1, Pizza1, 
		MonaLisa, Cleaver, Ruler, Computer, Snack, Can };

	/**
	* Is this entity active?
	*/
	bool active;

	/**
	* Is this entity visible?
	*/
	bool visible;

	/**
	* Velocity.
	*/
	Vector2 velocity;

	/**
	* Linear force.
	*/
	Vector2 force;

	/**
	* Angular velocity.
	*/
	float angVelocity;

	/**
	* Torque.
	*/
	float torque;

	/**
	* Matrix transform that represents scale, rotation and translation relative to parent.
	*/
	Matrix3 localMatrix;

	/**
	* Matrix transform that represents scale, rotation and translation relative to world.
	*/
	Matrix3 globalMatrix;

	/**
	* Mass.
	*/
	float mass;

	/**
	* Inverse mass.
	*/
	float inverseMass;

	/**
	* Inertia.
	*/
	float inertia;

	/**
	* Inverse inertia.
	*/
	float inverseInertia;

    /**
    * Combined centre of mass position matrix when this entity is the top level of a matrix hierarchy.
    */
    Matrix3 comLocalMatrix;

    /**
    * Combined mass when this entity is the top level of a matrix hierarchy.
    */
    float comMass;

    /**
    * Combined inverse inertia when this entity is the top level of a matrix hierarchy.
    */
    float comInverseMass;

    /**
    * Combined inertia when this entity is the top level of a matrix hierarchy.
    */
    float comInertia;

    /**
    * Combined inverse inertia when this entity is the top level of a matrix hierarchy.
    */
    float comInverseInertia;

	/**
	* Static friction of this object.
	* This is the friction threshold below which we can assume the body is at rest and cannot be moving against its own friction.
	* See http://gamedev.tutsplus.com/tutorials/implementation/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table/
	*/
	float staticFriction;

	/**
	* Dynamic friction of this object.
	* This is the friction threshold above which the object has overcome its own friction and can move.
	* See http://gamedev.tutsplus.com/tutorials/implementation/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table/
	*/
	float dynamicFriction;

	/**
	* Coefficient of restitution in the range 0.0f .. 1.0f.
	* Restitution is the elasticity, or bounciness of an object.
	* 0 means no bounce. 1 means a fully elastic collision.
	*/
	float restitution;

	/**
	* Is this entity sticky?
	* Sticky entities will stick to entities with "stickyReceiver" set true.
	*/
	bool sticky;

	/**
	* Is this entity a sticky receiver?
	* Sticky entities will stick to entities with "stickyReceiver" set true.
	*/
	bool stickyReceiver;

	/**
	* Time before a sticky entity that just became unstuck from its parent can restick.
	*/
	float restickTimeOut;

	/**
	* Timer for restick timeout.
	*/
	float restickTimer;

	/**
	* Shapes used for rendering.
	*/
	struct RenderShape
	{
        RenderShape() { lineThickness = 1.0f; depth = 3.0f; }
		Shape2 shape;
		Colour colour;
		float lineThickness;
        float depth;
	};

    /**
    * Sprites used for rendering.
    */
    struct RenderSprite
    {
        RenderSprite() { texture = ""; textureHeight = 0; textureWidth = 0; depth = 3.0f; }
        RenderSprite(const RenderSprite &other)
        { 
            copy(other);
        }
        RenderSprite &operator=(const RenderSprite &other) { copy(other); return *this; }
        void copy(const RenderSprite &other)
        {
            texture = other.texture;
            textureHeight = other.textureHeight;
            textureWidth = other.textureWidth;
            colour = other.colour;
            depth = other.depth;
        }
        std::string texture;
        float textureHeight;
        float textureWidth;
        Colour colour;
        float depth;
    };

	/**
	* Rendering shapes for this entity, if any.
	* These are the visible component of the entity, but have no effect on collision calculations.
	*/
	/*std::vector*/ ContLib::LinkedList<RenderShape> renderShapes;

	/**
	* Collider shapes for this entity, if any.
	* Collider shapes MUST be convex. Concave entites can be created form a series of convex collider shapes.
	* These are used to calculate collisions for the entity, but have no visible appearance on screen.
	*/
	/*std::vector*/ ContLib::LinkedList<Shape2> colliderShapes;

    /**
    * Sprites for this entity, if any.
    * These are the visible component of the entity, but have no effect on collision calculations.
    */
    /*std::vector*/ ContLib::LinkedList<RenderSprite> sprites;

	/**
	* Axis aligned bounding box (AABB) max distance for this entity.
	* This is the maximum length of a line between the world position of an entity
	* and a point on its axis aligned bounding box.
	* Note that for rotatable objects, this length is the maximum distance at any possible rotation of the object,
	* while the bounding box remains axis aligned and is never rotated.
	*/
	float aabbMaxDistUp, aabbMaxDistDown, aabbMaxDistLeft, aabbMaxDistRight;

	/**
	* Is this entity rotatable? This is used to determine the kind of calculations to use when auto generating the
	* Axis Aligned Bounding Box.
	*/
	bool rotatable;

	/**
	* Pointer to parent Entity, if any.
	* Will be nullptr if no parent (we are not in a heirarchy).
	*/
	Entity *parent;

	/**
	* Pointer to root Entity, if any. 
	* Points to ourself if no root entity (we are not in a heirarchy).
	* The root entity is the one at the top of a matrix heirarchy.
	*/
	Entity *root;

	/**
	* Vector of pointers to child entities, if any.
	*/
	/*std::vector*/ ContLib::LinkedList<Entity*> children;

	/**
	* Time at which the entity life expires and it should be automatically removed.
	* Set to zero means life timer is not active.
	*/
	float lifeTimeExpiry;

    /**
    * Reset this NEW entity, ready for its first use.
    * @returns void.
    */
    void resetNew();

    /**
    * Reset this EXISTING entity, ready for RE-USE.
    * @returns void.
    */
    void resetExisting();

	/**
	* Get Entity type. Pure virtual.
	* @returns Entity type
	*/
	virtual Et getType() const = 0;

	/**
	* Set parent Entity.
	* It is acceptable to set this to nullptr here.
	* @param pParent Pointer to the parent Entity to set.
	* @returns void.
	*/
	void setParent(Entity *pParent);

	/**
	* Update the root pointer for this entity, and all those below it in a matrix heirarchy.
	* @returns void.
	*/
	void updateRoot();

	/**
	* Get world position.
	* @returns World position as a vector2.
	*/
	Vector2 getWorldPos() const;

    /**
    * Get world position of the combined centre of mass.
    * Relevant only to the top level entity of a matrix hierarchy.
    * @returns World position of the centre of mass as a vector2.
    */
    Vector2 getWorldPosCOM() const;

	/**
	* Get local position.
	* @returns Local position relative to parent as a vector2.
	*/
	Vector2 getLocalPos() const;

	/**
	* Set local position relative to parent.
	* @param newPos The new local position.
	* @return void.
	*/
	void setLocalPosition(const Vector2 &newPos);

	/**
	* Add to local position relative to parent.
	* @param pos The x and y values to add, as a vector.
	* @returns void.
	*/
	void addToLocalPosition(const Vector2 &pos);

	/**
	* Set entity rotation in DEGREES.
	* @param The new rotation to use in DEGREES.
	* @returns void.
	*/
	inline void setRotationDeg(float degrees) { setRotation(MathsLib::deg2rad(degrees)); };

	/**
	* Set entity rotation in RADIANS.
	* @param The new rotation to use in RADIANS.
	* @returns void.
	*/
	void setRotation(float radians);

	/**
	* Add to entity rotation in RADIANS.
	* @param The rotation to add in RADIANS.
	* @returns void.
	*/
	void addRotation(float radians);

	/**
	* Add to entity rotation in DEGREES.
	* @param The rotation to add in DEGREES.
	* @returns void.
	*/
	inline void addRotationDeg(float degrees) { addRotation(MathsLib::deg2rad(degrees));  };

	/**
	* Clamp current local rotation between two values in RADIANS.
	* @params min The minimum rotation in RADIANS.
	* @params max The maximum rotation in RADIANS.
	* @returns void.
	*/
	void clampRotation(float min, float max);

	/**
	* Clamp current local rotation between two values in DEGREES.
	* @params min The minimum rotation in DEGREES.
	* @params max The maximum rotation in DEGREES.
	* @returns void.
	*/
	inline void clampRotationDeg(float min, float max) { clampRotation(MathsLib::deg2rad(min), MathsLib::deg2rad(max)); };

	/**
	* Set entity mass. 
	* Also updates inverseMass, inertia and inverseInertia automatically.
	* @param The new mass to use.
	* @returns void.
	*/
	void setMass(float nMass);

	/**
	* Set entity inertia. Also updates inverseInertia automatically.
	* @param The new inertia to use.
	* @returns void.
	*/
	void setInertia(float nInertia);

    /**
    * Update the combined local matrix of the matrix hierarchy, treating this entity as the top level entity.
    */
    void updateComLocalMatrix();

    /**
    * Update the combined mass of the matrix hierarchy, treating this entity as the top level entity.
    */
    void updateCombinedMass();

    /**
    * Update the combined inertia of the matrix hierarchy, treating this entity as the top level entity.
    */
    void updateCombinedInertia();

	/**
	* Update the matrix heirarchy.
	* @returns void.
	*/
	void updateMatrixHeirarchy();

	/**
	* Update Axis Aligned Bounding Box size data automatically from collider shapes.
	* @returns void.
	*/
	void updateAABBFromColliders();

	/**
	* Draw this entity. Optionally draw all our children recursively.
	* @param cascade Bool set true will draw all our children recursively. Set false will just draw this entity.
	* @param renderer A pointer to the Renderer2D object for this scene. 
	* @returns void.
	*/
	void draw(bool cascade, aie::Renderer2D* renderer);

	/**
	* Update this entity. Optionally update all our children recursively.
	* @param cascade Bool set true will update all our children recursively. Set false will just update this entity.
	* @returns void.
	*/
	void update(bool cascade);

	/**
	* Set the life expiry time N seconds in the future. This is when an entity will be automatically removed.
	* @params time The number of seconds in the future when this entity should expire.
	* @returns void.
	*/
	void setLifeTimeExpiry(float time);

	/**
	* Get sll child entities as a vector array of pointers.
	* @param vectorArray The vector array to fill with child entity pointers. Passed in by reference.
	* @param recursive Set true will also get all children of children recursively.
	* @returns A vector array of points to the child entities.
	*/
	void getChildEntities(/*std::vector*/ContLib::LinkedList<Entity *> &vectorarray, bool recursive) const;

	/**
	* Couple this entity to a new parent entity based on their current relative positions.
	* @params ent A pointer to the entity to use as our new parent.
	* @returns void.
	*/
	void fuseTo(Entity *ent);

	/**
	* Decouple this entity from its current parent.
	* @returns void.
	*/
	void breakAway();

protected:

	/**
	* Attach a child Entity.
	* @param pChild Pointer to the Entity to add.
	* @returns void.
	*/
	void addChild(Entity *pChild);

	/**
	* Remove a child Entity.
	* @param pChild Pointer to the Entity to remove.
	* @returns void.
	*/
	void removeChild(Entity *pChild);
};