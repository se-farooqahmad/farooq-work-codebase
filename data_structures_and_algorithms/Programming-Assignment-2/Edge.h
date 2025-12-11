# include <stack>
# include <queue>
#include<iostream>
using namespace std;
#ifndef EDGE_H
#define EDGE_H
class Edge
{
public:

	inline Edge(int numVertex);
	inline void insertEdge(int frmVertex, int toVertex, int weight);
	inline void prims();
	inline void print();
	inline void depthfirstSearch(int s, bool check);
	inline void breadthfirstSearch(int s);
private:
	int **adj_matrix;
	int numVertices;
};

#endif