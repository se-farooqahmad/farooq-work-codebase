# include"Edge.h"
# include <iostream>
using namespace std;
inline Edge::Edge(int numVertex)
{
		numVertices = numVertex;
		adj_matrix = new int *[numVertex];
		for (int k = 0; k<numVertices; k++)
		{
			adj_matrix[k] = new int[numVertex];
		}
		for (int i = 0; i<numVertices; i++)
		{
			for (int j = 0; j<numVertices; j++)
			{
				adj_matrix[i][j] = 0;
			}
		}	
}


inline void Edge::insertEdge(int frmVertex, int toVertex, int weight)
{
	adj_matrix[frmVertex ][toVertex ] = weight;
}
inline void Edge::depthfirstSearch(int s, bool check)
{
	stack<int> *t = new stack<int>();
	bool *explore = new bool[numVertices];
	for (int i = 0; i<numVertices; i++)
	{
		explore[i] = false;
	}
	t->push(s);
	explore[s] = true;
	while (!t->empty())
	{
		s = t->top();
		t->pop();
		if (check == false)
		cout << s + 1 << " " << endl;
		else
		cout << s << " " << endl;
		for (int i = 0; i < numVertices; i++)
		{
			if ((adj_matrix[s][i] != -1) && (adj_matrix[s][i] != 0) && (explore[i] == false))
			{
				t->push(i);
				explore[i] = true;
				break;
			}
		}
	}
}
inline void Edge::breadthfirstSearch(int s)
{
	bool *explore = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		explore[i] = false;
	}
	queue<int> *q = new queue<int>();
	q->push(s);
	explore[s] = true;
	while (!q->empty())
	{
		s = q->front();
		q->pop();
		cout << s << " " << endl;
		for (int j = 0; j < numVertices; j++)
		{
			if ((adj_matrix[s][j] != 0) && (adj_matrix[s][j] != -1) && (explore[j] == false))
			{
				q->push(j);
				explore[j] = true;
			}
		}
	}
}
inline void Edge::print()
{
	for (int i = 0; i < numVertices ; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			
			cout << adj_matrix[i][j]<<" ";
		}
		cout << endl;
	}


}
inline void Edge::prims()
{
	int  x, y, ne;
	bool *explore = new bool[numVertices];
	int infi = 50000;
	int *xe, *ye, *ge;
	xe = new int[numVertices];
	ye = new int[numVertices];
	ge = new int[numVertices];


	for (int i = 0; i<numVertices; i++)
		explore[i] = false;

	explore[0] = true;
	ne = 0;

	while (ne < numVertices - 1)
	{
		int min = infi;

		for (int i = 0; i<numVertices; i++)
		{
			if (explore[i] == true)
			{
				for (int j = 0; j<numVertices; j++)
				{
					if (explore[j] == false)
					{
						if (min > adj_matrix[i][j])
						{
							min = adj_matrix[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		explore[y] = true;

		xe[ne] = x;
		ye[ne] = y;
		ge[ne] = adj_matrix[x][y];

		ne = ne + 1;
	}

	for (int i = 0; i<numVertices; i++)
	{
		for (int j = 0; j<numVertices; j++)
		{
			adj_matrix[i][j] = -1;
		}
	}

	for (int n = 0; n< numVertices; n++)
	{
		adj_matrix[n][n] = 0;
	}

	for (int i = 0; i<ne; i++)
	{
		adj_matrix[xe[i]][ye[i]] = ge[i];
		adj_matrix[ye[i]][xe[i]] = ge[i];
	}


	print();
	cout << endl;

	///////////////////////////////////////////////////////////////////////
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			if (adj_matrix[i][j] == -1)
			{
				adj_matrix[i][j] = 0;
			}
			else if ((adj_matrix[i][j] != 0) && (adj_matrix[i][j] != -1))
			{
				adj_matrix[i][j] = 1;
			}
		}
	}

}

