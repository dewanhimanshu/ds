#include<iostream>
using namespace std;
#define MAX 100
template<class T>
class stack
{

    T a[MAX];
    int top;
    public:
    stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top==-1?1:0;
    }
    bool isFull()
    {
        return top==MAX-1?1:0;
    }
    void push(T element)
    {
        if(isFull())
        {
            cout<<"Stack is Full";
            return ;
        }
        a[++top] = element;
    }
    T pop()
    {   if(isEmpty())
        {
            return top;
        }
        return a[top--];
    }
    T topElement()
    {
        return a[top];
    }


};


