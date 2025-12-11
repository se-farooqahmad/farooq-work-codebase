# include <iostream>
# include <fstream>
# include "Edge.h"
# include "Edge_Def.cpp"
using namespace std;
int main()
{
	ifstream infile;
	infile.open("DSA Assignment 3 file nodes.txt");
	int count = 0;
	int temp[5000], temp1[5000], temp2[5000], temp3[5000], i = 0;
	while (!infile.eof())
	{
		infile >> temp[count];
		count++;
	}
	infile.close();
	//new is the file which has starting or ending vertex as zero
	infile.open("new.txt");
	//connect is the file whcih doesnt have any starting or endign vertex as zero
	//infile.open("connect.txt"); 
	while (!infile.eof())
	{
		infile >> temp1[i] >> temp2[i] >> temp3[i];
		i++;
	}
	bool check = false;
	for (int j = 0; j < i; j++)
	{
		if (temp1[j] == 0) 
		{
			check = true;
			break;
		}
	}

	if (check == false)
	{
		Edge *g;
		g = new Edge(count);
		for (int j = 0; j < i; j++)
		{
			g->insertEdge(temp1[j] - 1, temp2[j] - 1, temp3[j]);
		}
		g->print();
		g->prims();
		g->print();
		g->depthfirstSearch(2,check);
	}
	else if(check == true)
	{
		Edge *g;
		g = new Edge(count);

		for (int j = 0; j < i; j++)
		{
			g->insertEdge(temp1[j], temp2[j], temp3[j]);
		}
		g->print();
			g->prims();
			g->print();
			g->depthfirstSearch(2,check);

	}
	system("pause");
	return 0;
}
