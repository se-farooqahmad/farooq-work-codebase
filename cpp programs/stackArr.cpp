#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
template <class KeyType>
class Stack
{ //
private:
	KeyType * arr;
	int maxsize;
	int top;
public:
// constructor , creates an empty stack
Stack(int max)
{
    maxsize = max;
    top = -1;
    arr = new KeyType[max];
}
// returns true if Stack is full, otherwise return false
bool IsFull()
{	
    return (top == maxsize)?true : false;
}
//If number of elements in the Stack is zero return true, otherwise return false
bool IsEmpty()
{	
    return (top == -1)?true : false;
}
// If Stack is not full, insert item into the Stack
// Must be an O(1) operation
void Push(const KeyType item)
{	
    if(!IsFull())
    {
        top++;
        arr[top] = item;
    }
    else
    {
        cout<<"Stack is full";
    }

}
// If Stack is full return 0 or NULL;
// else return appropriate item from the Stack. Must be an O(1) operation
KeyType Pop()
{	
    if(!IsEmpty())
    {
        KeyType temp;
        temp = arr[top];
        top--;
        return temp;
    }
    else{
        cout<<"Stack is empty";
    }
}
void print();

//Add private data members yourself;
};
 template <class KeyType>
 void Stack<KeyType> :: print()
 {
    for(int i = top; i>= 0; i--)
    {
        cout<<arr[i]<<" ";
    }
 }

 int main()
 {
    Stack <int> st(6);
    for (int i = 0; i<6; i++)
    {
        st.Push(rand()%100);
    }
    cout<<"Original Stack"<<endl;
    st.print();
    cout<<endl;
    cout<<"After popping"<<endl;
    cout<<st.Pop();
	cout<<endl;
	st.print();
	cout<<endl;
	cout<<st.Pop();
	cout<<endl;
	st.print();
    cout<<endl;
    st.Push(68);
    st.Push(23);
    st.print();

    system("pause");
    return 0;
 }

