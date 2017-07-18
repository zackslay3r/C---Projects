#pragma once
#include "Node.h"
#include "Edge.h"
#include "Global.h"
class NodeManager
{
private:
		
		
		

		// the size of which node will be spaced against.
		float nodeSize = 50;
		

	public:
		float getNodeSize();
		int getIndex(int posX, int posY);
		void fillGameNodes();
		void linkNodes();
		void linkEdges();
		bool distanceCheck(Node* nodeOne, float distance, Node* nodeTwo);
		void withinDistance(Node* nodeOne, Node* nodeTwo);
		float magnitudeSqrd(float x, float y);
		float magnitude(float x, float y);
		Node* gameNodes;
		Edge* gameEdges;
		NodeManager();
		// This will be responsible for creating the nodes.
		~NodeManager();
};

