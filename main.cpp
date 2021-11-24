/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include "Dijkstra.hpp"
using namespace std;
int main()
{
    
    
    
    
    int** edgesA = new int* [2]; /*Establishes how many edges or connections a node has */
    for (int i = 0; i < 2; i++)
    {
        edgesA[i] = new int[2]; /* Need i to be 2 to represent node and distence respectfully for each edge */
    }
    edgesA[0][0] = 3;
    edgesA[0][1] = 10; /*A to C*/

    edgesA[1][0] = 5;
    edgesA[1][1] = 3; /*A to E */

    
    Node* node1= new Node(1, edgesA, 2);


    
    int** edgesB = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        edgesB[i] = new int[2];
    }
    
    edgesB[0][0] = 3;
    edgesB[0][1] = 2; /*B to C */

    edgesB[1][0] = 5;
    edgesB[1][1] = 4; /*B to E*/
    
    
    
    Node* node2 = new Node(2, edgesB, 2);


    //Node '3' Initialization
    int** edgesC = new int* [1];
    for (int i = 0; i < 2; i++)
    {
        edgesC[i] = new int[2]; 
    }
    
    edgesC[0][0] = 4;
    edgesC[0][1] = 9;   /* C to D */
    
    
    
   
    
    
    Node* node3 = new Node(3, edgesC, 1);


    
    int** edgesD = new int* [1];
    for (int i = 0; i < 1; i++)
    {
        edgesD[i] = new int[2];
    }
    
    edgesD[0][0] = 1;
    edgesD[0][1] = 7; /*D to A */

    Node* node4 = new Node(4, edgesD, 1);


   
    int** edgesE = new int* [3];
    for (int i = 0; i < 3; i++)
    {
        edgesE[i] = new int[2];
    }
    edgesE[0][0] = 2;
    edgesE[0][1] = 1; /*E to B */

    edgesE[1][0] = 3; 
    edgesE[1][1] = 8; /*E to C */

    edgesE[2][0] = 4;
    edgesE[2][1] = 2; /*E to D */

    Node* node5 = new Node(5, edgesE, 3);

    /*List of nodes intialized */
    Node* nodes[5] = { node1, node2, node3, node4, node5 };

  
    Dijkstra* processing = new Dijkstra(5, nodes);
    
    int cost = processing->getBestPath(node3, node1); /*Tried muliply methods of getting the nodes to have a user input, but just didn't have time*/
    cout << "Cost of path: "<<cost << "\n";

    int* finalPath = processing->getPath();
    for (int i = 0; i < 5; i++)
    {
        if(finalPath[i] != 0){
          cout << finalPath[i] << " -> ";  
        }
        
    }
    cout << " end ";
    
    
}