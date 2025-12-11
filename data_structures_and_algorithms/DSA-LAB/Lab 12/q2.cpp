#include <iostream>
using namespace std;
class graph
{

	int vertices;
	int **graph_arr;
public:
	graph(){}
	void set(int v)
	{
		vertices =v;
		graph_arr = new int*[v];
		for(int i=0;i<v;i++)
		graph_arr[i]= new int[v];
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
				graph_arr[i][j]=0;
		}
	}
	void print()
	{
		cout<<"\nprint\n";
		cout<<"\t";
		for(int i=0;i<vertices;i++)
		{
			cout<<i<<"\t";
		}
		cout<<endl;
		for(int i=0;i<vertices;i++)
		{
			cout<<i<<"\t";
			for(int j=0;j<vertices;j++)
				cout<<graph_arr[i][j]<<"\t";
			cout<<endl;
		}
	}
	void edge(int i,int j)
	{
		graph_arr[i][j]=1;
	}
	void check_edge(int i)
	{
		cout<<"\nlinks\n";
		for(int j=0;j<vertices;j++)
			{
				if(graph_arr[i][j]==1)
					cout<<j<<"\t";
		}
	}

};
void main()
{
	int vertice;
	cout<<"ENTER NO OF VERTICES \n";
	cin>>vertice;
	graph g;
	g.set(vertice);
	g.print();
	g.edge(1,0);
	g.edge(1,2);
	g.edge(2,3);
	g.edge(3,4);
	g.edge(4,0);
	g.edge(1,1);
	g.edge(2,1);
	g.edge(4,1);
	g.edge(3,1);
	g.print();
	g.check_edge(3);
	system("pause");

}