#include<iostream>
#include"stack.h"
using namespace std;
bool balance_brackets(char a[])
{
    stack <char> s;
    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i]=='{'||a[i]=='('||a[i]=='[')
        {
            s.push(a[i]);
        }
        else if(a[i]=='}')
        {
            if(s.isEmpty())
            {
                return 0;
            }
            char x = s.pop();
            if(x!='{')
            {
                return 0;
            }
        }
        else if(a[i]==')')
        {
            if(s.isEmpty())
            {
                return 0;
            }
            char x = s.pop();
            if(x!='(')
            {
                return 0;
            }

        }
        else if(a[i]==']')
        {
            if(s.isEmpty())
            {
                return 0;
            }
            char x = s.pop();
            if(x!='[')
            {
                return 0;
            }

        }

    }

    if(s.isEmpty())
    {
        return 1;
    }
    return 0;

}

int main()
{
    cout<<balance_brackets("(a+b)");
}

