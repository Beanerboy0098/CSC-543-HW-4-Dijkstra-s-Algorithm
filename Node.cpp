#include "Node.hpp"
#include <limits>
using namespace std;

Node::Node(int id, int** matrix, int numcon)
{
	this->Id = id;
	this->collectionOfEdges = matrix;
	this->numConnections = numcon;
	this->distance = numeric_limits<int>::max(); 
}

int Node::getDistance()
{
	return this->distance;
}

void Node::setDistance(int val)
{
	this->distance = val;
}

int Node::getId()
{
	return this->Id;
}

int Node::getNumConnections()
{
	return this->numConnections;
}

int** Node::getMatrix()
{
	return this->collectionOfEdges;
}