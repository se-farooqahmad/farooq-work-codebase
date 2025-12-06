#include<iostream>
#include<string>
using namespace std;
int convert(char letter)
{   
    if (letter == 'A' || letter == 'B' || letter == 'C') {
        return 2;
    } else if (letter == 'D' || letter == 'E' || letter == 'F') {
        return 3;
    } else if (letter == 'G' || letter == 'H' || letter == 'I') {
        return 4;
    } else if (letter == 'J' || letter == 'K' || letter == 'L') {
        return 5;
    } else if (letter == 'M' || letter == 'N' || letter == 'O') {
        return 6;
    } else if (letter == 'P' || letter == 'Q' || letter == 'R' || letter == 'S') {
        return 7;
    } else if (letter == 'T' || letter == 'U' || letter == 'V') {
        return 8;
    } else if (letter == 'W' || letter == 'X' || letter == 'Y' || letter == 'Z') {
        return 9;
    } else {
        return 0;  // If the character is not a letter, return it as is
    }
}
int main()
{
    /*string phrase;
    cout<<"Enter a string phrase";
    getline(cin,phrase);
    cout<<"you entered: "<<phrase<<endl;*/
    cout<<"Enter a character array Phrase : "<<endl;
    char arr[10];
    cin.get(arr,10);
    cout<<"You have entered -> "<<arr<<endl;
    cout<<"Its corresponding telephone number is : ";
    int length = sizeof(arr);
    for (int i = 0; i < length; i++)
    {   
        arr[i]=toupper(arr[i]);
    }
    int count = 0;
    for (int i=0; i<9; i++)
    {  
        cout<<convert(arr[i]);
        count++;
        if (count == 3)
            cout<<"-";
        if (count == 7)
            break;
    }
}