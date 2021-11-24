#include "Dijkstra.hpp"
#include <limits>
using namespace std;

Dijkstra::Dijkstra(int nodes, Node** allNodes)
{
	this->numNodes = nodes;
	this->nodes = allNodes;
	this->totalCost = 0;
	

	this->unvisited = new int[this->numNodes];
	for (int i = 0; i < this->numNodes; i++)
	{
		this->unvisited[i] = this->nodes[i]->getId(); 
	}

	this->visited = new int[this->numNodes];
	for (int i = 0; i < this->numNodes; i++)
	{
		this->visited[i] = 0;
	}
}

void Dijkstra::addVisited(int Id)
{
    /*Adds nodes that are visted during bestpath fuction*/

	for (int i = 0; i < this->numNodes; i++)
	{
		if (this->visited[i] == 0)
		{
			this->visited[i] = Id;
			break;
		}
	}
}

int Dijkstra::getBestPath(Node* start, Node* dest)
{
	/*This is where most of the short path finding happens first taking two nodes from the inputed nodes */

	Node* currNode = start;
	Node* tempNode = start;
	int smallestDistance = numeric_limits<int>::max(); /*Setting the default distence to a maximum value for each node */

	int iterations = currNode->getNumConnections();
	for (int i = 0; i < iterations; i++)
	{
		int tempDistance = currNode->getDistance();

		if (tempDistance > currNode->getMatrix()[i][1])
		{
			tempDistance = currNode->getMatrix()[i][1];
			
			getNode(currNode->getMatrix()[i][0])->setDistance(tempDistance); /*Goes through each node and checks distence if edge is the shortest possible path to destination then that edge is chosen. Along with the node being put into visted, the next node that is examined is the node that has the edge that has the shortest distence  */
		}


		if (tempDistance < smallestDistance)
		{
			smallestDistance = tempDistance;
			tempNode = getNode(currNode->getMatrix()[i][0]);
		}
	}

	this->totalCost += smallestDistance;
	addVisited(currNode->getId());

	if (tempNode->getId() == dest->getId())
	{
		addVisited(tempNode->getId());           /* Once node ID matches the end nodes ID then the program ends */
		return this->totalCost;
	}
	else
		return getBestPath(tempNode, dest);
}

Node* Dijkstra::getNode(int Id)
{
	for (int i = 0; i < this->numNodes; i++)
	{
		if (this->nodes[i]->getId() == Id)
			return this->nodes[i];
	}
	return nullptr;
}

int* Dijkstra::getPath()
{
	return this->visited;
}