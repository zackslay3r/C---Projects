#pragma once
#include "Edge.h"
#include <list>
// This is the node class, it is responsible for each point on the screen and will be used for pathfinding and A*.
// It consist's of an X and Y position, as well as a size apart scalar, which will be used to set uniform distance between nodes.
// It will also feature get methods that will let the note get 2 of the 3 values required for the A* calculations. F and H.

// A* equation = (F = G + H)
class Edge;
class Node
{
	
private:
	
	
	
	// a boolean that will tell A* if it is facing a wall or not.
	bool isWalkable = true;
	// values that are required for calculating the distance between the start and end point with a node.
	// F score = Final score of distance.
	// H score = distance between the start and end. H is indiviually changed based on each node area.
	float hScore;
	// this is the d score, which is the distance that each step cost.
	float dScore;

	

public:
	// This the the constructor.
	Node();
	// This is the destructor.
	~Node();
	// an array of Node pointers that will enable for directional movement later.
	std::list<Edge* > links;
	//This function returns FScore of type float.
	float getFScore();
	//This function returns HScore of type float.
	float getHScore();
	//This function returns DScore of type float.
	float getdScore();
	//This function sets the HScore of type float.
	void setHScore(float newHScore);
	//This function sets the DScore of type float.
	void setdScore(float newdScore);
	inline bool getWalkable(){return isWalkable;};
	inline void setWalkable(bool tf) {isWalkable = tf;};

	int getKey();
	float magnitude();
	Node* previousNode = nullptr;
	//void normalise();
	// Position X and Y of a node on the game.
	float posX, posY;
	// This is the key that each node has.
	int key;
	void linkNodes();
};


