#include<iostream>
#include"stack.h"
using namespace std;
stack <char> add(stack<char> a,stack<char> b )
{
   stack <char> result;
    int r = 0;
    while(!a.isEmpty()&&!b.isEmpty())
    {

       int x = a.pop()-'0';
       int y = b.pop()-'0';
       int s = (x+y+r);

        r = s / 10;
        s = s % 10;


        result.push(s+'0');
    }
    while(!a.isEmpty())
    {
        int x = a.pop()-'0';
        int s = (x+r);
        r = s / 10;
        s = s % 10;

        result.push(s+'0');

    }
    while(!b.isEmpty())
    {
        int x = b.pop()-'0';
        int s = (x+r);
        r = s / 10;
        s = s % 10;
        result.push(s+'0');

    }

    return result;



}

int main()
{
    char x[MAX];
    char y[MAX];
    stack <char> a;
    stack <char> b;
    cout<<"\nenter the first number";
    cin>>x;
    cout<<"\nenter the second number";
    cin>>y;
    for(int i=0;i<x[i]!='\0';i++)
    {
        a.push(x[i]);
    }
    for(int i=0;i<y[i]!='\0';i++)
    {
        b.push(y[i]);
    }



   stack<char>result = add(a,b);
   while(!result.isEmpty())
   {
    cout<<result.pop();
   }



}
