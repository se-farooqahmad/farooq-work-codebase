#include<iostream>
using namespace std;
double largest(double x, double y, double z)
{
    if( x>y && x>z )
        return x;
    else if( y>x && y>z )
        return y;
    else return z;
}
double smallest(double x, double y,double z)
{
    if( x<y && x<z )
        return x;
    else if ( y<x && y<z )
        return y;
   else return z;
}
int main()
{
    double a,b,c;
    cout<<"Enter three numbers :"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cout<<"The largest among the three is "<<largest(a,b,c)<<endl;
    cout<<"The smallest among the three is "<<smallest(a,b,c)<<endl;
}