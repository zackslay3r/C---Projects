#pragma once
#include "Node.h"
#include "Edge.h"
#include "Global.h"
#include "Object.h"

#include <functional>


/*
* class NodeManager
*
* this is the nodeManger class, which is responsible for laying out the nodes on the game arena.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/

class NodeManager
{
private:
		
		
		

		// the size of which node will be spaced against.
		float nodeSize = 50;
		
		// These are the 3 custom heuristic's.
		std::function<float(Node* startNode, Node* endNode)> heuristicEuclidean;
		std::function<float(Node* startNode, Node* endNode)> heuristicManhattian;
		std::function<float(Node* startNode, Node* endNode)> heuristicDiagonal;
	
public:
		struct edgePair
		{
			float edgeDistance;
			Node* node;

		};
		
		
		/*
		* float getNodeSize();
		*
		* this function returns a float of nodeSize.
		*
		*/
		float getNodeSize();
		/*
		* int getIndex(int posX, int posY);
		*
		* this function returns a int that can link to a node based on two floats of position X and position Y.
		*
		*/
		int getIndex(int posX, int posY);
		
		/*
		* void fillGameNodes();
		*
		* this function is responsible for setting up the game area with gameNodes and returns void. 
		*
		*/
		void fillGameNodes();
		/*
		* void linkNodes();
		*
		* this function is responsible for linking gameNodes together and returns void.
		*
		*/
		void linkNodes();
		/*
		* void linkNodes();
		*
		* this function is responsible for linking gameNodes edges together and returns void.
		*
		*/
		void linkEdges();
		/*
		* bool distanceCheck(Node* nodeOne, float distance, Node* nodeTwo);
		*
		* this function is responsible checking to see if two nodes are within a certain distance,
		* its takes 3 parameters, 2 Node*'s that are being compared against and a float variable of distance
		* and returns a boolean.
		*
		*/
		bool distanceCheck(Node* nodeOne, float distance, Node* nodeTwo);
		/*
		* bool distanceCheck(Object* nodeOne, float distance, Object* nodeTwo);
		*
		* this function is responsible checking to see if two nodes are within a certain distance,
		* its takes 3 parameters, 2 Object*'s that are being compared against and a float variable of distance
		* and returns a boolean.
		*
		*/
		bool distanceCheck(Object * objectOne, float distance, Object * objectTwo);
		
		bool showNodes, showSquares, showKeys , showClosedSet, showOpenSet = false;
		
		/*
		* std::list<Node*> pathFinding(Node* nodeOne, Node*  nodeTwo);
		*
		* this function is responsible for creating an A* path from one node to another.
		* It takes in two nodes as parameters (the start and end node) and returns a list of Node*'s.
		*
		*/
		//std::list<Node*> pathFinding(Node* nodeOne, Node*  nodeTwo);
		//std::list<Node*> pathFinding(Node * startNode, Node * endNode, std::function<float()> heuristicEstimate(Node* nodeOne, Node* nodeTwo)) { return pathFinding(startNode, endNode, nullptr); };
		std::list<Node*> pathFinding(Node * startNode, Node * endNode, std::function<float(Node* startNode2, Node* endNode2)> heuristic);
		std::list<Node*> pathFinding(Node * startNode, Node * endNode) { return pathFinding(startNode, endNode, nullptr); };


		/*
		* float heuristicEstimate(Node* nodeOne, Node* nodeTwo);
		*
		* this function is responsible for the creation of a Hscore estimate between two Nodes.
		* it takes two Node*'s as parameters and returns a float value.
		*
		*/
		/*float heuristicEstimate(Node* nodeOne, Node* nodeTwo);*/

		/*
		* std::list<Node*> reconstruct_path(Node* currentNode);
		*
		* this function is responsible for the reconstruction of a A* path and takes in a Node* as a parameter and 
		* returns a std::list of Node*'s 
		*
		*/
		std::list<Node*> reconstruct_path(Node* currentNode);
		
	
		std::list<Node*> completedClosedSet, completedOpenSet;
		
		/*
		* void wallSetter(int nodeKey);
		*
		* This function is responsible for being able to set nodes to walls, it will compare all the nodes
		* against the parameter of type int and will set it to be a wall, and it returns void.
		*
		*/
		void wallSetter(int nodeKey);
		
		/*
		* void CleanUpEdgePointers();
		*
		* This function is responsible for cleaning up the edges of a node after it is set to be a wall. and returns void.
		*
		*/
		void CleanUpEdgePointers();
		
		/*
		* float magnitudeSqrd(float x, float y);
		*
		* This function is responsible for calculating the magnitude squared based off of the two float parameters.
		* and returns a float.
		*
		*/
		float magnitudeSqrd(float x, float y);
		/*
		* float magnitude(float x, float y);
		*
		* This function is responsible for calculating the magnitude  based off of the two float parameters.
		* and returns a float.
		*
		*/
		float magnitude(float x, float y);
		Node* gameNodes;
		Edge* gameEdges;
		
		/*
		* NodeManager();
		*
		* This is the default constructor.
		*
		*/
		NodeManager();
		/*
		* ~NodeManager();
		*
		* This is the default destructor.
		*
		*/
		~NodeManager();
};

