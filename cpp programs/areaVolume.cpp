#include <iostream>
#include <cmath>
using namespace std;
double area(double radius)
{
    double a;
    a = 4 * 3.14 * pow(radius,2);
    return a; 
}
double volume(double radius)
{
    double v;
    v = (4/3) * 3.14 * radius*radius*radius;
    return v;
}
int main()
{
    int r;
    cout<<"Enter Radius: ";
    cin>>r;
    cout<<"Area is: "<<area(r)<<" cm^2"<<endl;
    cout<<"Volume is: "<<volume(r)<<" cm^3"<<endl;
}