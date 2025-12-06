#include<iostream>
#include <string>
using namespace std;
int main()
{
    string phrase;
    char letter;
    cout<<"Enter a phrase : ";
    getline(cin,phrase);
    cout<<"Enter a letter to find in the phrase : ";
    cin>>letter;
    int count =  0;
    for (int i = 0; i<phrase.length(); i++)
    {
        char c = phrase[i];
        if ( c == letter)
            count++;
    }
    cout<<"The letter \""<<letter<<"\" has occured "<<count<<" time(s) in the phrase";
    cout<<endl;
    cout<<phrase;
}