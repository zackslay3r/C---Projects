#pragma once
#include "Node.h"
// This is the Edge class, all an edge is is the start and end point within the A* pathfinding. as well as the G score, which
// is the the actual distance between the two points.
class Edge
{
private:


	// This are the two Nodes, startNode and endNode.

	/*Node* nodeOne;
	Node* nodeTwo;*/
public:
	int keyOne;
	int keyTwo;
	
	// This will help calulate distance between nodes
	float edgeDistance;

	char edgeColour;

	// this function returns the gScore.
		
	void getEdges();
	Edge();
	~Edge();
};

