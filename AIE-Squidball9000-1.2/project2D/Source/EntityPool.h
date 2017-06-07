#pragma once
#include <BinarySearchTree.h>
#include <Stack.h>
#include "Entity.h"

#define EPOOL EntityPool::getInstance()

class EntityPool
{

public:
    
    /**
    * Create or get static instance.
    * @returns A pointer to the single EntityPool object.
    */
    static class EntityPool *getInstance();

    /**
    * Get a count of available entities of this type.
    * @params type Entity type.
    * @returns Count of entities of the given type.
    */
    int count(const Entity::Et &type) const;

    /**
    * Pop an entity off the pool stack for the given type.
    * If no entity of that type is available, it will return nullptr.
    * @params type Entity type.
    * @returns A pointer to the entity.
    */
    Entity *getEntityFromPool(const Entity::Et &type);

    /**
    * Add entity to pool.
    * Entity type is automatically determined.
    * @params p Pointer to entity.
    * @returns void.
    */
    void addEntityToPool(Entity *p);

private:

    /**
    * Default constructor.
    */
    EntityPool();

    /**
    * Default destructor.
    */
    ~EntityPool();

    /**
    * The object pool, which is a binary tree of stacks, keyed by Entity type.
    */
    ContLib::BinarySearchTree<Entity::Et, ContLib::Stack<Entity *>> pool;

};