#include<iostream>
using namespace std;
template<class T>
class doublell
{

    class node
    {
    public:
        T info;
        node* forward=NULL;
        node* backward=NULL;
        node()
        {

        }
        node(T x)
        {
            info = x;
        }
    };

    node* top = NULL;
    public :
    void input(T x)
    {
        node* t = new node(x);
        if(top==NULL)
        {
            top = t;
            t->backward = NULL;
            t->forward = NULL;
            return;
        }

        t->forward = top;
        top->backward = t;
        top = t;

    }
    T remove(int &f)
    {
        if(top==NULL)
        {
            cout<<"\nUnderflow";
            f = -1;
            return NULL;

        }
        if(top->forward==NULL)
        {
            T x = top->info;
            top = NULL;
            f = 1;
            return x;
        }
        node* temp = top;
        T x = top->info;
        top = top->forward;
        top->backward = NULL;
        delete temp;
        f = 1;
        return x;

    }
    void print()
    {
        node* temp = top;
        while(temp!=NULL)
        {
            cout<<"\nNode value is::"<<temp->info;
            temp = temp->forward;
        }
    }
    void printr()
    {
        node* temp = top;
        while(temp->forward!=NULL)
        {
            temp = temp->forward;
        }
        node* rt = temp;
        while(rt!=NULL)
        {
            cout<<"\nNode value is::"<<rt->info;
            rt = rt->backward;
        }

    }
    int search(T x)
    {
        node* temp = top;
        while(temp!=NULL)
        {
            if(temp->info == x)
            {
                return 1;
            }
            temp = temp->forward;
        }
        return -1;
    }
    node*  reverse(node* top)
    {

        if(top->forward==NULL)
        {
            return top;
        }
        node* newtop = reverse(top->forward);
        newtop->backward=NULL;
        top->forward->forward = top;
        top->backward = top->forward;
        top->forward = NULL;
        return newtop;

    }
    void reversell()
    {
        if(top!=NULL)
        {


        top = reverse(top);
        print();
        }
    }

    void newinsert(T x , T y)
    {
        node* temp = top;
        while(temp!=NULL)
        {
            if(temp->info==y)
            {
                break;
            }
            temp = temp->forward;
        }
        if(temp==NULL)
        {
            input(x);
        }

        node* t = new node(x);
       // node* before = temp->backward;
        t->backward = temp;
        t->forward = temp->forward;
        temp->forward = t;
        if(t->forward!=NULL)
        {
             t->forward->backward = t;
        }




    }
    void delpos(T x)
    {
        node* temp = top;
        if(top==NULL)
        {
            return;
        }
        if(top->forward==NULL&&top->info==x)
        {
            delete top;
            top=NULL;

            return;
        }
        if(top->info==x)
        {
            top=top->forward;
            return ;
        }
        while(temp!=NULL)
        {
            if(temp->info==x)
            {
                break;
            }
            temp = temp->forward;
        }
        if(temp==NULL)
        {
            cout<<"\nNot found";
            return;
        }
        if(temp->forward==NULL)
        {
            temp->backward->forward = NULL;
            delete temp;
            return ;
        }


        node* t = temp;
        temp->backward->forward = temp->forward;
        temp->forward->backward = t->backward;
        delete t;
    }


};

int main()
{

    doublell<int>  l;

    while(true)
    {
        cout<<"\n*********MENU DRIVEN PROGRAM************";
        cout<<"\n1,Insert";
        cout<<"\n2.Delete";
        cout<<"\n3.reverse";
        cout<<"\n4.print";
        cout<<"\n5.Reverse Print";
        cout<<"\n6.Insert after info";
        cout<<"\n7,delete pos";

        cout<<"\nEnter your choice";
        int ch;
        cin>>ch;

        if(ch==1)
        {
            cout<<"\nEnter the number you want to insert";
            int x;
            cin>>x;
            l.input(x);
        }
        else if(ch==2)
        {
            int f = 0;
            int x = l.remove(f);
            if(f==1)
            {
                cout<<"\nRemoved node is::"<<x;
            }

        }
        else if(ch==3)
        {
            l.reversell();
        }
        else if(ch==4)
        {
            l.print();
        }
        else if(ch==5)
        {
            l.printr();
        }
        else if(ch==6)
        {
          cout<<"\nEnter the number you want to insert";
            int x;
            cin>>x;
        cout<<"\nEnter the info";
        int y;
        cin>>y;
            l.newinsert(x,y);
        }
        else if(ch==7)
        {
            cout<<"\nEnter the info";
            int x;
            cin>>x;
            l.delpos(x);
        }
        else
            break;


    }





}
