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

bool Grid::Navigate(point start,point goal)
{
	//implemment this function using a stack
	
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
	Grid g;
	point start;
	point end;
	g.ReadGridAndStartEnd("grid.txt", start, end);	
	g.Navigate(start,end);
	//now add function to g to print the results to file and call them here
	
} 

