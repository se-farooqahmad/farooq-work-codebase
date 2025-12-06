#include<iostream>
using namespace std;
void rightAngleTriangle(int a, int b, int c)
{
    if( a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a)
        cout<<"This is a right angle triangle";
    else cout<<"This is not a right angle triangle";
}
int main()
{
    int x,y,z;
    cout<<"Enter the lengths of the sides of a trianlge: ";
    cin>>x>>y>>z;
    rightAngleTriangle(x,y,z);
}
