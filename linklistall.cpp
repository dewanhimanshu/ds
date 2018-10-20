#include<iostream>
using namespace std;
template <class T>
class linklist
{
    class node
    {
        public:
        T info;
        node* next = NULL;
    };

    public:
        node* first = NULL;

    void insert(T x)
    {
        node *n = new node;
        n->info = x;
        if(first==NULL)
        {
            first = n;
        }
        else
        {
            n->next = first;
            first = n;
        }
    }
    T del()
    {
        if(first==NULL)
        {
            cout<<"Link List is Empty";
            return NULL;
        }
        node* temp = first;
        first = first->next;
        T x = temp->info;
        delete temp;
        return x;
    }
    void print ()
    {
        node* temp = first;
        while(temp!=NULL)
        {
            cout<<"\nNode is:"<<temp->info;
            temp= temp->next;
        }
    }
    bool search(T x)
    {
          node* temp = first;
          while(temp!=NULL)
          {
            if(temp->info==x)
            {
                return true;
            }
            temp = temp->next;
          }
          return false;
    }
    node* reverse(node* top)
    {
        if(top==NULL)
        {
            return NULL;
        }
        else if(top->next==NULL)
        {
            return top;
        }

        node* t = reverse(top->next);
        top->next->next = top;
        top->next = NULL;
        return t;



    }
    void reversenode()
    {
        first = reverse(first);
        print();
    }

    node* concat(node* l)
    {
        node* t = first;
        if(t==NULL)
        {
            return l;
        }
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next = l;
        return first;
    }

    void addb(T x,T y)
    {
        node* t = new node;
        t->info = x;
        if(first==NULL)
        {
            first = t;
        }
        if(first->info==y)
        {
            t->next = first;
            first = t;
            return;
        }

        node* temp = first;
        node* z = NULL;
        while(temp!=NULL)
        {
            if(temp->info==y)
            {
                break;
            }
            z = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            insert(x);
            return ;
        }

        t->next = temp;
        z->next = t;
    }

};




int main()
{
    linklist<int> list ;
    while(1)
    {
        cout<<"\n***********";
        cout<<"\nMenu Driven Program";
        cout<<"\n1.Insertion";
        cout<<"\n2.Deletion";
        cout<<"\n3.Print";
        cout<<"\n4. Search";
        cout<<"\n5,Reverse node";
        cout<<"\n6.Concat";
        cout<<"\n7.addition before info";
        cout<<"\nEnter Your Choice";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int x;
            cout<<"\nenter the element you want to enter";
            cin>>x;
            list.insert(x);
        }
        else if(ch==2)
        {
            cout<<"\nDeleted node is"<<list.del();
        }
        else if(ch==3)
        {
            list.print();
        }
        else if(ch==4)
        {
            int x;
            cout<<"\nEnter The number to be searched";
            cin>>x;
            if(list.search(x))
            {
                cout<<"\nHurray!!Number Found";
            }
            else
            {
                cout<<"\nNumber not found";
            }
        }
        else if(ch==5)
        {
            list.reversenode();
        }
        else if(ch==6)
        {
            linklist<int>  l2;
            cout<<"\nEnter the number elements in list 2 ::";
            int x;
            cin>>x;
            for(int i=0;i<x;i++)
            {
                cout<<"\nEnter the element to be inserted";
                int y;
                cin>>y;
                l2.insert(y);
            }
            linklist<int> l3;
            l3.first = list.concat(l2.first);
            l3.print();
        }
        else if(ch==7)
        {
            int x;
            cout<<"\nenter the element you want to enter";
            cin>>x;
            int y;
            cout<<"\nEnter the element info (search) :";
            cin>>y;
            list.addb(x,y);

        }
        else
        {
            break;
        }
    }
}
