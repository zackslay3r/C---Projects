#pragma once
#include "Node.h"
// This is the Edge class, all an edge is is the start and end point within the A* pathfinding. as well as the G score, which
// is the the actual distance between the two points.
class Edge
{
public:
	int keyOne;
	int keyTwo;
	
	// This will help calulate distance between nodes
	float edgeDistance;

	char edgeColour;

	Edge();
	~Edge();
};

