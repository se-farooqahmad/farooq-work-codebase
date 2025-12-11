#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(int argc, char*argv[])
{   
fstream file;
file.open(argv[1]);
if(file.is_open())
{
    char arr;
    while(!file.eof())
    {
        file.get(arr);
        cout<<arr;
    }
    cout<<endl;
}

else
{
    cout<<"ERROR, file not found";
}


cout<<endl;
file.close();
}