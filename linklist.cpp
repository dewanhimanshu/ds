#include<iostream>
using namespace std;
template <class T>
class stack
{
public:
    class node
    {
    public:
        T info;
        node* next=NULL;

    };

    node* top;
    stack()
    {
        top  = NULL;
    }
    void insert()
    {
        int x;
        cout<<"\n enter the value to be inserted";
        cin>>x;
        node* n = new node;
        n->info = x;
        if(top==NULL)
        {
            top = n;
        }
        else
        {
            node* temp = top;
            top = n;
            n->next = temp;
        }
    }

    void print()
    {
        node* temp = top;
        while(temp!=NULL)
        {
            cout<<"\n Node value is"<<temp->info;
            temp  = temp->next;
        }
    }
    T del()
    {

         if(top==NULL)
         {
            cout<<"STACK EMPTY";
            return NULL;
         }
         node* temp = top;
         T x = temp->info;
         if(top->next==NULL)
         {
            top = NULL;
            delete temp;
            return x;
         }

        top = top->next;
        delete temp;
        return x;
    }
};

int main()
{
    stack<int>s;
    while(1)
    {
        cout<<"\n*******************************";
        cout<<"\nMenu Driven Program";
        cout<<"\n1.insert into stack";
        cout<<"\n2.delete the element";
        cout<<"\n3.print the stack";
        int ch;
        cout<<"\n4.Enter your choice";
        cin>>ch;
        if(ch==1)
        {
            s.insert();
        }
        else if(ch==2)
        {

            cout<<"\nDeleted node value is"<<s.del();

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
