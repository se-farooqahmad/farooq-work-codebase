#include <iostream>
#include <fstream>
#include<iomanip>
#include <cmath>
using namespace std;
int main()
{
    ifstream inn;
    inn.open("inFile.txt");
    int x;
    ofstream outt;
    outt.open("outFile.txt");
    while(!inn.eof())
    {   
        inn>>x;
        outt<<x<<setw(10)<<pow(x,2)<<setw(10)<<pow(x,3)<<endl;
    }
    inn.close();
    outt.close();
    return 0;
}