#pragma once

#include <string>
#include <BinarySearchTree.h>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include "State.h"

#define GSM GameStateManager::getInstance()

class GameStateManager
{

public:

    /**
    * Create or get static instance.
    * @returns A pointer to the single GameStateManager object.
    */
    static GameStateManager *getInstance();

    /**
    * Execute update behaviours for all active states.
    * @returns void.
    */
    inline void update() { for (auto &state : activeStates) state->update(); };

    /**
    * Execute draw behaviours for all active states.
    * @returns void.
    */
    inline void draw() { for (auto &state : activeStates) state->draw(); };

    /**
    * Get count of active states.
    * @returns The count of active states.
    */
    inline int count() { return activeStates.count(); };

    /**
    * Add a registered state to the active states list.
    * @returns void.
    */
    void activateState(std::string stateName);

    /**
    * Remove a state from the active states list.
    * @returns void.
    */
    void removeState(std::string stateName);

private:

    /**
    * Default constructor.
    */
    GameStateManager();

    /**
    * Default destructor.
    */
    ~GameStateManager();

    /**
    * Available state objects.
    */
    ContLib::BinarySearchTree<std::string, State *> availableStates;

    /**
    * List of active state objects.
    */
    ContLib::LinkedList<State *> activeStates;

};