#include<iostream>
#include<string>
using namespace std;
int main(){
    string phrase;int count = 0;
    cout<<"Enter a phrase : ";
    getline(cin,phrase);
    for(char c : phrase){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||c == 'O' ||c == 'U' )
            count++;}
    cout<<"Total number of vowels in the sentence are "<<count;
}