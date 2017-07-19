#include "NodeManager.h"
#include <list>


NodeManager::NodeManager()
{
	gameNodes = new Node[GAMESETTINGS->NODE_ARRAY_LENGTH];
	//gameEdges = new Edge[8];
	std::list<Edge*> gameEdges;
}


NodeManager::~NodeManager()
{
}

float NodeManager::getNodeSize()
{
	return nodeSize;
}

int NodeManager::getIndex(int posX, int posY)
{	
	posX = posX / 50;
	posY = posY / 50;
	int i = posX * 18 + posY;
	return i;
}

void NodeManager::fillGameNodes()
{
	int keyCounter = 0;
		for (int j = 0; j <= 1600 - getNodeSize();)
		{
			for (int k = 0; k <= 900 - getNodeSize();)
			{
			

				gameNodes[keyCounter].posY = k;
				gameNodes[keyCounter].posX = j;
				gameNodes[keyCounter].key = keyCounter;
				keyCounter++;
				k = k + 50;
				
			}
		
		j = j + 50;
		
		
		}


		linkNodes();

}

void NodeManager::linkNodes()
{
	// For each of the nodes, we are going to run a circle collsiion check.
	for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		for (int j = i+1; j < GAMESETTINGS->NODE_ARRAY_LENGTH; j++)
		{
			if (distanceCheck(&gameNodes[i], GAMESETTINGS->CIRCLE_CHECKER_SIZE, &gameNodes[j]))
			{
				Edge* tempEdge = new Edge();
				tempEdge->keyOne = gameNodes[i].key;
				tempEdge->keyTwo = gameNodes[j].key;
			

				float DistX = gameNodes[i].posX - gameNodes[j].posX;
				float DistY = gameNodes[i].posY - gameNodes[j].posY;

				tempEdge->edgeDistance = magnitude(DistX, DistY);
				if (tempEdge->edgeDistance > (GAMESETTINGS->gridSize + 2))
				{
					tempEdge->edgeColour = 'b';
				}
				else
				{
					tempEdge->edgeColour = 'r';
				}

				gameNodes[i].links.push_front(tempEdge);
				gameNodes[j].links.push_front(tempEdge);
			}
		}
	}
}



void NodeManager::linkEdges()
{
	//for (int i = 0; i <= GAMESETTINGS->windowLength; i = i + 50)
	//{
	//	for (int j = 0; j <= GAMESETTINGS->windowHeight; j = j + 50)
	//	{

	//	}

	//}

}

bool NodeManager::distanceCheck(Node * nodeOne, float distance, Node * nodeTwo)
{
	// temp x and temp y is used to store the values when node one and node two are minused.
	
	float DistX = nodeOne->posX - nodeTwo->posX;
	float DistY = nodeOne->posY - nodeTwo->posY;

	return (magnitudeSqrd(DistX, DistY) < (distance * distance));

}
float NodeManager::magnitudeSqrd(float x, float y)
{
	return (x*x) + (y*y);
}
float NodeManager::magnitude(float x, float y)
{
	return sqrt((x*x) + (y*y));
}

void NodeManager::withinDistance(Node* nodeOne, Node* nodeTwo)
{
	//nodeOne->links.push_front();
}

void NodeManager::pathFinding(Node * startNode, Node * endNode)
{
	// This is for the closed set of nodes.
	std::list<Node*> closedSet;
	// This is for the open set of nodes.
	std::list<Node*> openSet;

	
	//set the start node to be a part of the open list.
	openSet.push_front(startNode);

	// for every Node, set the gScore to be equal to infinity.
	for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		gameNodes[i].setdScore(INFINITY);
	}

	startNode->setdScore(0);

	for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		gameNodes[i].setFScore(INFINITY);
	}

	startNode->setFScore(heuristicEstimate(startNode, endNode));

	while (openSet.size() > 0)
	{
		// tempNode to evaluate against for finding the finish.
		Node* node_current;
		
		std::list<Node* >::iterator iter;
		Node* tempNode;
		
		// Loops though the open set and will set the current node to the one with the lowest Fscore.
		for (iter = openSet.begin(); iter != openSet.end(); ++iter)
		{
			if ((*iter)->getFScore() < tempNode->getFScore())
			{
				tempNode = *iter;
			}
		}
		node_current = tempNode;
		// if the current key is equal to the endNode key, we have found the endNode
		if (node_current->key == endNode->key)
		{
			reconstruct_path(node_current->previousNode, node_current);
			break;

		}
		// remove from the open set and push onto the closed set.
		openSet.remove(node_current);
		closedSet.push_front(node_current);
		
		struct edgePair
		{
		float edgeDistance;
		Node* node;

		};


		std::list<Edge* >::iterator edgeIter;
		std::list<edgePair> neighbours;
		for (edgeIter = node_current->links.begin(); edgeIter != node_current->links.end(); ++edgeIter)
		{
			if ((*edgeIter)->keyOne != node_current->key)
			{

				neighbours.push_front({ (*edgeIter)->edgeDistance,&gameNodes[(*edgeIter)->keyOne]});
			}
			if ((*edgeIter)->keyTwo != node_current->key)
			{
				neighbours.push_front({ (*edgeIter)->edgeDistance,&gameNodes[(*edgeIter)->keyTwo] });
			}
			
			
	

		}
		
		for(auto &var: neighbours)
		{
			float teneative_gScore = (node_current->getdScore() + var.edgeDistance);
			if(teneative_gScore >= var.node->getdScore())
			{
			continue;
			}
			else
			{
			var.node->previousNode = node_current;
			var.node->setdScore(teneative_gScore);
			var.node->setFScore(var.node->getdScore() + heuristicEstimate(var.node, endNode));
			}

		}

	}
	// This is the previous node to backtrack from
	
	// gSco


}

float NodeManager::heuristicEstimate(Node * nodeOne, Node * nodeTwo)
{
	float x, y, h;
	x = abs(nodeOne->posX - nodeTwo->posX);
	y = abs(nodeOne->posY - nodeTwo->posY);
	if (x > y)
	{
		h = 14 * y + 10 * (x - y);
	}
	else
	{
		h = 14 * x + 10 * (y - x);
	}

	return h;
}

std::list<Node*> NodeManager::reconstruct_path(Node * camefrom, Node * currentNode)
{
	std::list<Node*> tempList;
	tempList.push_back(currentNode);
	while(currentNode != camefrom)
	{
	currentNode = currentNode->previousNode;
	tempList.push_back(currentNode);
	}

	return tempList;
}




