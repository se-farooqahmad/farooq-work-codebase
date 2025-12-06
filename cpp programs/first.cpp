#include <iostream>
using namespace std;
int main()
{
    int stars;
    cout<< "Enter the size of diamond: ";
    cin>> stars;
    int space = stars -1;
    for (int i=0; i<=stars; i++)
    {
        for (int j=0; j<=space; j++)
        {
            cout<<" ";
        }
        space--;
        for (int j=0; j<i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    space = 0;
    for (int i=stars-1; i>=0; i--)
    {
        for (int j=0; j<=space; j++)
        {
            cout<<" ";
        }
        space++;
        for (int j=i; j>0;j--)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}