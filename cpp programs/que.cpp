#include <iostream>
using namespace std;
template <typename T>
class Node
{
    private: 
	     T data;
	     Node *link;
    public: 
        // constructor 
        Node(T element)
        {
            data = element;
            link = NULL;
        }	 
        //sets the KeyType data in the Node
        void setData(T pVal)
        {
            data = pVal;
        }
        // returns the KeyType data in the Node
        T getData()
        {
            return data;
        }
        // sets the link to the next node
        void SetNext(Node *x)
        {
            link = x;
        }
        // returns the link to the next node
        Node* GetNext()
        {
            return link;
        }
        

};
template <typename T>
class Queue
{
    private:
        Node<T> *front;
        Node<T> *rear;
    public:
        //contructor
        Queue()
        {
            front= NULL;
            rear = NULL;
        }
    bool isEmpty(){return (front==NULL && rear==NULL)?true:false}
    void enqueue(T value);
    //gets the element to be inserted, creates a new node, and insert it and then update positions of rear and front as required.
    T dequeue();
    // if queue not empty then delete the first element else no.
    void display();
    //displays the queue
 };
template <typename T>
void Queue<T> :: enqueue(T value)
{
    Node<T> *temp = new Node<T>();
    temp->setData(value);
    if(isEmpty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->SetNext(temp);
        rear = temp;
    }
}
template <typename T>
T Queue<T> ::dequeue()
{
    if(!isEmpty())
    {
        Node<T> * temp = front;
        T t;
        front = front->GetNext();
        t = temp->getData();
        delete temp;
        return t;
    }
    else{cout<<"Queue empty";}

}
template<typename T>
void Queue<T>::display()
{
    Node<T> * temp = first;
    if(!isEmpty())
    {
        while(temp!=rear)
        {
            cout<<temp->getData();
            temp = temp->GetNext();
        }
        cout<<temp->getData();
        cout<<endl;
    }
}
int main()
{
	Queue<int> *q= new Queue<int>();
	cout<<"ENQUEUE\t";
	q->enqueue(5);
	q->display();
	cout<<"ENQUEUE\t";
	q->enqueue(7);
	q->display();
	cout<<"ENQUEUE\t";
	q->enqueue(8);
	q->display();
	cout<<"DEQUE\t";
	cout<<q->dequeue()<<endl;
	q->display();
	cout<<"DEQUE\t";
	cout<<q->dequeue()<<endl;
	q->display();
	system("pause");
}
