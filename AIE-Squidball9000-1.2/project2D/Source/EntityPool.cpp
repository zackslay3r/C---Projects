#include "EntityPool.h"

EntityPool::EntityPool()
{
    pool = ContLib::BinarySearchTree<Entity::Et, ContLib::Stack<Entity *>>();
}

EntityPool::~EntityPool()
{
}

EntityPool *EntityPool::getInstance()
{
    static EntityPool entityPool;

    return &entityPool;
}

Entity * EntityPool::getEntityFromPool(const Entity::Et & type)
{
	if (!count(type)) return nullptr;
	return pool[type].pop();
}

void EntityPool::addEntityToPool(Entity * p)
{
	//If no stack of this type, create it (with a default size of 1).
	if (!pool.count(p->getType())) pool.insert(p->getType(), ContLib::Stack<Entity *>(1));

	//Add this entity to the pool stack for its type.
	pool[p->getType()].push(p);
}

int EntityPool::count(const Entity::Et &type) const
{
    //If no stack of this type, return 0 immediately.
    if (!pool.count(type)) return 0;
    //Return count of number of items in stack.
    return pool[type].count();
}
