#include<iostream>
using namespace std;
template<class T>
class circular
{

    class node
    {
    {
        public:
        T info;
        node* next;
    };
    node* top = NULL;
      public:
    void insert(T x)
    {
        node* t = new node;
        t->info = x;

        if(top==NULL)
        {
            top=t;
            t->next = t;
            return ;
        }
        else if(top->next==top)
        {
            top->next = t;
            t->next = top;
            return ;
        }

         node* temp = top;
         while(temp->next!=top)
         {
            temp = temp->next;
         }
         temp->next = t;
         t->next = top;
         return;


    }
    void print()
    {
        node* temp = top;
        if(temp==NULL)
        {
            return;
        }
        while(temp->next!=top)
        {
            cout<<"\nNode value is:"<<temp->info;
            temp = temp->next;
        }
         cout<<"\nNode value is:"<<temp->info;
    }
    void reverse()
    {
       node* temp = top;
        if(temp==NULL)
        {
            return;
        }
        while(temp->next!=top)
        {

            temp = temp->next;
        }
        temp->next = NULL;
        top = reverseit(top);
        node* t = top;
        while(t->next!=NULL)
        {
                t = t->next;
        }
        t->next top;
    }


};
int main()
{
     circular<int>  l;

    while(true)
    {
        cout<<"\n*********MENU DRIVEN PROGRAM************";
        cout<<"\n1,Insert";
        cout<<"\n2.Delete";
        cout<<"\n3.reverse";
        cout<<"\n4.print";
        cout<<"\n5.Reverse Print";
        cout<<"\n6.Insert after info";
        cout<<"\nEnter your choice";
        int ch;
        cin>>ch;

        if(ch==1)
        {
            cout<<"\nEnter the number you want to insert";
            int x;
            cin>>x;
            l.insert(x);
        }
        else if(ch==2)
        {
            int f = 0;
         //   int x = l.remove(f);
            if(f==1)
            {
               // cout<<"\nRemoved node is::"<<x;
            }

        }
        else if(ch==3)
        {
            l.reverse();
        }
        else if(ch==4)
        {
            l.print();
        }
        else if(ch==5)
        {
           // l.printr();
        }
        else if(ch==6)
        {
          cout<<"\nEnter the number you want to insert";
            int x;
            cin>>x;
        cout<<"\nEnter the info";
        int y;
        cin>>y;
          //  l.newinsert(x,y);
        }
        else
            break;


    }

}
