#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include"LinkedList.h"
#include"LinkedList.cpp"
using namespace std;

int main()
{   	
	Queue<int> *q =new Queue<int>();
	if(q->IsEmpty())
		cout<<"Queue is currently empty"<<endl;

	q->Put(1);
	q->Put(2);
	q->Put(3);
	
	q->PrintQueue();
	cout<<"**********************\n";

	int value=q->Get();
	cout<<value<<endl;
	value=q->Get();
	cout<<value<<endl;
	value=q->Get();
	cout<<value<<endl;


	system("pause");
	return 0;
}
