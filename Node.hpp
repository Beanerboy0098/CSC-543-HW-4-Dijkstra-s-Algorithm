class Node
{
    /* Header file for nodes methods */
private:
	int distance;
	int Id;
	int numConnections;
	int** collectionOfEdges; 


public:
	Node(int id, int** matrix, int numcon);
	int getDistance();
	void setDistance(int val);
	int getId();
	int getNumConnections();
	int** getMatrix();
};