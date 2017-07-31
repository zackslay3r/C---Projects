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
		
		struct edgePair
		{
			float edgeDistance;
			Node* node;

		};
		
		
		float getNodeSize();
		int getIndex(int posX, int posY);
		void fillGameNodes();
		void linkNodes();
		void linkEdges();
		bool distanceCheck(Node* nodeOne, float distance, Node* nodeTwo);
		bool showNodes, showSquares, showKeys , showClosedSet, showOpenSet = false;
		void withinDistance(Node* nodeOne, Node* nodeTwo);
		std::list<Node*> pathFinding(Node* nodeOne, Node*  nodeTwo);
		float heuristicEstimate(Node* nodeOne, Node* nodeTwo);
		std::list<Node*> reconstruct_path(Node* currentNode);

		std::list<Node*> completedClosedSet, completedOpenSet;
		void wallSetter(int nodeKey);
		void CleanUpEdgePointers();
		float magnitudeSqrd(float x, float y);
		float magnitude(float x, float y);
		Node* gameNodes;
		Edge* gameEdges;
		
		NodeManager();
		// This will be responsible for creating the nodes.
		~NodeManager();
};

