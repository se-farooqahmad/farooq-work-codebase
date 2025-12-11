#include "matrix.h"
#include "stack.h"
using namespace std;

//coordinates of a state
class point
{
public:
	point(){x=-1;y=-1;};
	point(int tx,int ty){x=tx;y=ty;}
	point(const point &source){x=source.x;y=source.y;}
	point & operator=(const point &source) {x=source.x;y=source.y;return *this;}
	bool operator != (const point &p){return (x!=p.x || y!=p.y);}
	bool operator == (const point &p){return (x==p.x && y==p.y);}
	void TakeInput(ifstream &stream){stream >> x;stream >> y;}

	int getx(){return x;}
	int gety(){return y;}
	void setx(int xx){x=xx;}
	void sety(int yy){y=yy;}
private:
	int x;
	int y;
};


class Grid
{
public:
	bool ReadGridAndStartEnd(char *FileName,point &start,point &end);
	bool Navigate(point start,point goal);	
	void printPath();

private:
	//implementation provided
	//when given a state current, this function finds the possible child/next states and the corresponding actions
	//to reach them.  total is the total number of child states found
	void next(point current, point *child, int &total);
	int legal(point p);
	//checks if a point is visited or not (implemented)
	bool visited(point p);
	//if a point is visited then set it to true (implemented)
	void setVisited(point state,int value);

	

	TwoDMatrix<int> maze;   //stores the actual maze
	TwoDMatrix<bool> visitedArr; //stores whether a cell is visited or not

	Stack<point> pathPoints;//you have to fill this. should store the points on the path
	Stack<point> visitedPoints;//you have to fill this with points that were visited while discovering the path	
};
