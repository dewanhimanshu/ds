#include<iostream>
using namespace std;
template<class T>
class queue
{
public:
    class node
    {
    public:
        T info;
        node* next=NULL;

    };

    node* front = NULL;
    node* rear = NULL;
    void enqueue()
    {
        int x;
        cout<<"\n enter the value to be inserted";
        cin>>x;
        node* n = new node;
        n->info = x;
        if(rear==NULL)
        {
            front = rear = n;
            return;
        }

        rear->next = n;
        rear = n;

    }
    T dequeue()
    {
        if(front==NULL)
        {
            cout<<"\nQueue is Empty";
            return NULL;
        }
        if(front==rear)
        {
            node* temp = front;
            T x = temp->info;
            front=rear=NULL;
            delete temp;
            return x;
        }

        node* temp = front;
        T x = temp->info;
        front = front->next;
        delete temp;
        return x;
    }
    void print()
    {
        node* temp = front;
        if(front==NULL)
        {
            cout<<"\nQueue is Empty";
            return;
        }
        while(temp!=NULL)
        {
            cout<<"\nNode is"<<temp->info;
            temp=temp->next;
        }
    }
};

int main()
{
    queue<int> s;
     while(1)
    {
        cout<<"\n*******************************";
        cout<<"\nMenu Driven Program";
        cout<<"\n1.enqueue";
        cout<<"\n2. dequeue";
        cout<<"\n3.print the queue";
        int ch;
        cout<<"\n4.Enter your choice";
        cin>>ch;
        if(ch==1)
        {
            s.enqueue();
        }
        else if(ch==2)
        {

            cout<<"\nDeleted node value is"<<s.dequeue();

        }
        else if(ch==3)
        {
            s.print();
        }
        else
        {
            break;
        }
    }


}
