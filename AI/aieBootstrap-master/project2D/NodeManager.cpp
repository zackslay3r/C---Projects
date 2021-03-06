#include "NodeManager.h"
#include <list>
#include "Vector2.h"




NodeManager::NodeManager()
{
	gameNodes = new Node[GAMESETTINGS->NODE_ARRAY_LENGTH];
	//gameEdges = new Edge[8];
	std::list<Edge*> gameEdges;

	heuristicEuclidean = [](Node* nodeOne, Node* nodeTwo)->float
	{
		Vector2 dis = { nodeOne->posX - nodeTwo->posX,nodeOne->posY - nodeTwo->posY };
		float h = dis.magnitude();
		return h;
	};
	heuristicManhattian = [](Node* nodeOne, Node* nodeTwo)->float
	{
		float HScore;
		HScore = (abs(nodeOne->posX - nodeTwo->posX) + abs(nodeOne->posY - nodeTwo->posY));
		return HScore;
	};
	heuristicDiagonal = [](Node* nodeOne, Node* nodeTwo)->float
	{
		float Hscore;

		float xDist = abs(nodeOne->posX - nodeTwo->posX);
		float yDist = abs(nodeOne->posY - nodeTwo->posY);
		if (xDist > yDist)
		{
			Hscore = 1.414213f * yDist + (xDist - yDist);
		}
		else
		{
			Hscore = 1.414213f * xDist + (yDist - xDist);
		}
		return Hscore;
	};
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
			

				gameNodes[keyCounter].posY = float(k);
				gameNodes[keyCounter].posX = float(j);
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
	wallSetter(1);
	wallSetter(2);
	wallSetter(3);
	wallSetter(4);
	wallSetter(25);
	wallSetter(59);



	wallSetter((18 * 5) + 9);
	wallSetter((18 * 6) + 9);
	wallSetter((18 * 5) + 10);
	wallSetter((18 * 6) + 10);


	//wallSetter(131);
	/*wallSetter(2);
	wallSetter(3);
	wallSetter(4);
	wallSetter(37);
	wallSetter(38);
	wallSetter(39);
	wallSetter(40);
	wallSetter(41);
	wallSetter(42);
	wallSetter(43);
	wallSetter(44);
	wallSetter(74);
	wallSetter(75);
	wallSetter(76);
	wallSetter(77);
	wallSetter(78);
	wallSetter(79);
	wallSetter(80);
	wallSetter(81);
	wallSetter(82);*/
	CleanUpEdgePointers();
}



void NodeManager::linkEdges()
{


}

bool NodeManager::distanceCheck(Node * nodeOne, float distance, Node * nodeTwo)
{
	// temp x and temp y is used to store the values when node one and node two are minused.
	
	float DistX = nodeOne->posX - nodeTwo->posX;
	float DistY = nodeOne->posY - nodeTwo->posY;

	return (magnitudeSqrd(DistX, DistY) < (distance * distance));

}

bool NodeManager::distanceCheck(Object * objectOne, float distance, Object * objectTwo)
{
	// temp x and temp y is used to store the values when node one and node two are minused.

	Vector2 tempVector;
	tempVector = { objectOne->position - objectTwo->position };

	return (magnitudeSqrd(tempVector.x, tempVector.y) < (distance * distance));

}
float NodeManager::magnitudeSqrd(float x, float y)
{
	return (x*x) + (y*y);
}
float NodeManager::magnitude(float x, float y)
{
	return sqrt((x*x) + (y*y));
}



std::list<Node*> NodeManager::pathFinding(Node * startNode, Node * endNode, std::function<float(Node* startNode2, Node* endNode2)> heuristic)
{
	//Use default heuristic if none given.
	if (!heuristic) heuristic = heuristicEuclidean;


	if (endNode->getWalkable())
	{
		// This is for the closed set of nodes.
		std::list<Node*> closedSet;
		// This is for the open set of nodes.
		std::list<Node*> openSet;

		float e = 1.05f;



		// for every Node, set the gScore to be equal to infinity.
		for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
		{
			gameNodes[i].setdScore(INFINITY);
			gameNodes[i].previousNode = nullptr;
			gameNodes[i].setHScore(INFINITY);
		}

		//set the start node to be a part of the open list.
		openSet.push_front(startNode);
		startNode->setdScore(0);


		startNode->setHScore(heuristic(startNode, endNode) * e);
		Node* node_current = nullptr;
		std::list<Node* >::iterator iter;
		while (openSet.size() > 0)
		{
			// tempNode to evaluate against for finding the finish.


			float tempF = FLT_MAX;

			// Loops though the open set and will set the current node to the one with the lowest Fscore.
			for (iter = openSet.begin(); iter != openSet.end(); ++iter)
			{
				if ((*iter)->getFScore() < tempF)
				{
					node_current = *iter;
					tempF = (*iter)->getFScore();
				}
			}

			// if the current key is equal to the endNode key, we have found the endNode
			if (node_current->key == endNode->key)
			{
				return reconstruct_path(node_current);


			}
			// remove from the open set and push onto the closed set.
			openSet.remove(node_current);
			closedSet.push_front(node_current);




			std::list<Edge* >::iterator edgeIter;
			Node* node_temp = nullptr;
			for (edgeIter = node_current->links.begin(); edgeIter != node_current->links.end(); ++edgeIter)
			{
				float TempD = 0;
				if ((*edgeIter)->keyOne != node_current->key)
				{
					TempD = (*edgeIter)->edgeDistance;
					node_temp = &gameNodes[(*edgeIter)->keyOne];
				}
				if ((*edgeIter)->keyTwo != node_current->key)
				{
					TempD = (*edgeIter)->edgeDistance;
					node_temp = &gameNodes[(*edgeIter)->keyTwo];
				}
				
				
				if (node_temp->getWalkable() == false)
				{
					continue;
				}
				if (std::find(closedSet.begin(), closedSet.end(), node_temp) != closedSet.end())
				{
					continue;
				}
				if (std::find(openSet.begin(), openSet.end(), node_temp) == openSet.end())
				{
					openSet.push_back(node_temp);
				}


				float teneative_gScore = (node_current->getdScore() + TempD);
				if (teneative_gScore >= node_temp->getdScore())
				{
					continue;
				}


				node_temp->previousNode = node_current;
				node_temp->setdScore(teneative_gScore);
				node_temp->setHScore((heuristic(node_temp, endNode) * e));

			
			}
			completedClosedSet = closedSet;
			completedOpenSet = openSet;			
		}
			

	}
	return std::list<Node *>();
}

//float NodeManager::heuristicEstimate(Node * nodeOne, Node * nodeTwo)
//{
//
//	Vector2 dis = { nodeOne->posX - nodeTwo->posX,nodeOne->posY - nodeTwo->posY };
//	float h = dis.magnitude();
//	return h;
//}

std::list<Node*> NodeManager::reconstruct_path(Node * currentNode)
{
	std::list<Node*> tempList;
	tempList.push_back(currentNode);
	while(currentNode->previousNode != nullptr)
	{
	currentNode = currentNode->previousNode;
	tempList.push_back(currentNode);
	
	}

	return tempList;
}



void NodeManager::wallSetter(int nodeKey)
{
	
		gameNodes[nodeKey].setWalkable(false);
		std::list<Edge*> empty;
		Edge* tempEdge = new Edge();

		
	/*	
		for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
		{
			
			for (auto &currentEdges : gameNodes[nodeKey].links)
			{
					for (auto &edges : gameNodes[i].links)
					{
						if (edges->keyOne == currentEdges->keyTwo)
						{
							gameNodes[i].links.remove(edges);
						}
						if (edges->keyTwo == currentEdges->keyOne)
						{
							gameNodes[i].links.remove(edges);
						}
					}
			}*/

		//for (auto &&edges : gameNodes[nodeKey].links)
		std::list<Edge* >::iterator edgeIter;
		for (edgeIter = gameNodes[nodeKey].links.begin(); edgeIter != gameNodes[nodeKey].links.end(); ++edgeIter)		
		{
			if ((*edgeIter)->keyOne == nodeKey)
			{
				(*edgeIter)->keyOne = -1;
			}
			if ((*edgeIter)->keyTwo == nodeKey)
			{
				(*edgeIter)->keyOne = -1;
			}
			if ((*edgeIter)->keyOne == -1 &&
				(*edgeIter)->keyTwo == -1)
			{
				delete *edgeIter;
			}
		}
		gameNodes[nodeKey].links.clear();

		CleanUpEdgePointers();
		// sever any links to the node.
		

		// DIRTY!!! ruins the nodes making a square.
		// this will need to be changed soon
		/*gameNodes[nodeKey + 1].setWalkable(false);
		gameNodes[nodeKey + 19].setWalkable(false);
		gameNodes[nodeKey + 94].setWalkable(false);*/
		/*Node node_current = gameNodes[nodeKey];
		std::list<Edge* >::iterator edgeIter;
		std::list<edgePair> neighbours;
		for (edgeIter = node_current.links.begin(); edgeIter != node_current.links.end(); ++edgeIter)
		{
			if ((*edgeIter)->keyOne != node_current.key)
			{

				neighbours.push_front({ (*edgeIter)->edgeDistance,&gameNodes[(*edgeIter)->keyOne] });
			}
			if ((*edgeIter)->keyTwo != node_current.key)
			{
				neighbours.push_front({ (*edgeIter)->edgeDistance,&gameNodes[(*edgeIter)->keyTwo] });
			}

			for (auto &neigh : neighbours)
			{
				if (node_current.posX + 50.0f == neigh.node->posX && node_current.posY == neigh.node->posY)
				{
					gameNodes[neigh.node->key].setWalkable(false);
				}
				if (node_current.posX == neigh.node->posX && node_current.posY + 50.0f == neigh.node->posY)
				{
					gameNodes[neigh.node->key].setWalkable(false);
				}
				if (node_current.posX + 50.0f == neigh.node->posX && node_current.posY + 50.0f == neigh.node->posY)
				{
					gameNodes[neigh.node->key].setWalkable(false);
				}
			}*/



		
}

void NodeManager::CleanUpEdgePointers()
{
	std::list<Edge* > ToRemove;
	std::list<Edge* >::iterator edgeIter;
	for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)// clean up non wall edges that where pointer to a wall
	{
		for (edgeIter = gameNodes[i].links.begin(); edgeIter != gameNodes[i].links.end(); ++edgeIter)
		{
			Edge* temp = (*edgeIter);
			if (temp->keyOne == -1 ||
				temp->keyTwo == -1)
			{
				ToRemove.push_back(temp);
				delete temp;
			}
		}
		for (auto &TOremove : ToRemove)
		{
			gameNodes[i].links.remove(TOremove);
		}
	}
	
}




