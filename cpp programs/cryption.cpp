#include<iostream>
using namespace std;
char encryption(char sentence[], int key)
{
    int i = 0;
    while(sentence[i]!= '\0')
    {
        if(sentence[i]!= ' ')
            sentence[i]+= key;
        else sentence[i]+= 0;
            i++;
        }
    cout<<"Encryted data is "<<sentence;
    return 0;
}
char decryption(char sentence[], int key)
{
    int i = 0;
    while(sentence[i]!= '\0')
    {
        if(sentence[i]!= ' ')
            sentence[i]-= key;
        else sentence[i]-= 0;
            i++;
        }
    cout<<"Decryted data is "<<sentence;
    return 0;
}

int main()
{
    char sentence[100];
    cout<<"Enter Data : ";
    cin.get(sentence,100);
    cout<<"Do you want to encrypt or decrypt?"<<endl;
    cout<<"Press 1 for encryption and Press 2 for decryption : ";
    int choice;
    cin>>choice;
    if(choice == 1)
    {
        cout<<"Enter key for encryption : ";
        int key;
        cin>>key;
        encryption(sentence,key);
    }
    else if (choice == 2)
    {
        cout<<"Enter key for decryption : ";
        int key;
        cin>>key;
        decryption(sentence,key);
    }
    else cout<<"Invalid entry";
}