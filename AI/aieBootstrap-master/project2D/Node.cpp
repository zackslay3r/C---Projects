#include "Node.h"
#include <math.h>


Node::Node()
{
}


Node::~Node()
{
}

float Node::getFScore()
{
	return hScore + dScore;
}

float Node::getHScore()
{
	return hScore;
}

float Node::getdScore()
{
	return dScore;
}


void Node::setHScore(float newHScore)
{
	hScore = newHScore;
}

void Node::setdScore(float newdScore)
{
	dScore = newdScore;
}

int Node::getKey()
{
	return key;
}

float Node::magnitude()
{
	return sqrt((posX*posX) + (posY*posY));
}

//void Node::normalise()
//{
//	float tempMag = magnitude();
//	posX /= tempMag;
//	posY /= tempMag;
//}



