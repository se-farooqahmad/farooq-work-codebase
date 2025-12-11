#include <iostream>
#include <fstream>
#include "maze.h"
using namespace std;


bool Grid::ReadGridAndStartEnd(char *FileName,point &start,point &end)
{
	int rows,cols;
	ifstream stream(FileName);
	if (!stream.is_open())
		return false;
	
	stream >>rows;
	stream >>cols;
	
	start.TakeInput(stream);
	end.TakeInput(stream);

	maze.initialize(rows,cols);
	maze.TakeInput(stream);

	visitedArr.initialize(rows,cols);

	for(int i=0; i<rows;i++)
		for(int j=0; j<cols;j++)
			visitedArr.Set(i, j, false);

	 
	return true;
}

void Grid::setVisited(point state,int value)
{
	visitedArr.Set(state.getx(),state.gety(),true);
}

void Grid::printPath()
{
	ofstream write;
	write.open("path.txt");
	point temp;
 	while (!pathPoints.IsEmpty())
	{
		temp = pathPoints.Pop();
		write << temp.getx() << "," << temp.gety() << endl;
	}
}
bool Grid::Navigate(point start,point goal)
{
	point choice;
	ofstream write;
	write.open("visited.txt");


	bool goalFound = false;
	point current = start;
	Stack<point> stateStack;
	point child[4];
	int total = 0;
	stateStack.Push(current);
	while (!stateStack.IsEmpty() || goalFound != true)
	{
		
		current = stateStack.Pop();
		setVisited(current, true);
		visitedPoints.Push(current);

		if(goalFound == false)
			pathPoints.Push(current);

		write << current.getx() << "," << current.gety() << endl; // Writing Visiting Points

		if (current == goal)
		{
			cout << "Code Complete" << endl;
			goalFound = true;
		}
		else
		{
			next(current, child, total);
			
			if (total > 0)
			{
				if(total >= 2)
					choice = current;

				while (total-1 != -1)
				{
					stateStack.Push(child[total - 1]);
					total--;
				}
			}
			else
			{
				if (goalFound == false)
				{
					while (current != choice)
						current = pathPoints.Pop();

					pathPoints.Push(current);
				}
			}
		}
 	}
	return goalFound;
}
		

//check if point p is visited
bool Grid::visited(point p)
{
	bool value = false;
	visitedArr.Get(p.getx(),p.gety(),value);
	return value;
}
//check if there is a barrier in the maze at point p
int Grid::legal(point p)
{
	int value = false;
	maze.Get(p.getx(),p.gety(),value);
	return value;
	
}

void Grid::next(point current, point *child,int &total)
{
	total=0;
	point left,right,up,down;
	left = right = up = down = current;
	left.sety(left.gety()-1);
	up.setx(up.getx()-1);
	right.sety(right.gety()+1);
	down.setx(down.getx()+1);
	
	if (left.gety()>=0 && !visited(left)&&legal(left))
	{	child[total] = left;
		total++;
	}
	if (right.gety()<maze.GetCols() && !visited(right) && legal(right))
	{	child[total] = right;
		total++;
	}
	if (down.getx()<maze.GetRows() && !visited(down) && legal(down))
	{	child[total] = down;
		total++;
	}
	if (up.getx()>=0 && !visited(up)&&legal(up))
	{	child[total] = up;
		total++;
	}
	
}


int main()
{
	char name[] = "grid.txt";
	Grid g;
	point start;
	point end;
	g.ReadGridAndStartEnd(name, start, end);
	g.Navigate(start,end);
	//now add function to g to print the results to file and call them here
	g.printPath();
	
} 

