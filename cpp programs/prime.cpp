#include <iostream> 
using namespace std;
int main(){

    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    int count = 0;
    for (int i=0; i<num; i++)
    {
        if(i==0 | i==1)
            continue;
        if (i==2)
            cout<<i<<" ";
        if(i==3)
            cout<<i<<" ";
        if(i%2!=0 && i%3 !=0)
            cout<<i<<" ";
        
    }
    return 0;
}