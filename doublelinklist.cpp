#include<iostream>
using namespace std;
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

}
