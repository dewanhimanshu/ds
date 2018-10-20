#include"stack.h"
#include<ctype.h>
using namespace std;
bool priority(stack<char> s, char x)
{
    char top_element = s.topElement();
    if(top_element=='*')
    {
        return 1;
    }
    else if(top_element=='+'||top_element=='-')
    {
        if(x!='*')
        {
            return 1;
        }
    }
    return 0;


}
void convert(char infix[], char postfix[])
{
    int index = 0;
    stack <char>s;
    for(int i=0; infix[i]!='\0'; i++)
    {
        if(isalpha(infix[i]))
        {
            postfix[index++] = infix[i];
        }
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if(infix[i]=='+'||infix[i]=='/'||infix[i]=='*'||infix[i]=='-')
        {
            while(priority(s,infix[i]))
            {
                if(s.isEmpty())
                {
                    cout<<"expression entered is incorrert";
                    return;
                }
                char x = s.pop();
                postfix[index++] = x;

            }
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            if(s.isEmpty())
            {
                cout<<"expression entered is incorrert";
                return;
            }
            char x = s.pop();

            while(x!='(')
            {
                postfix[index++] = x;
                x = s.pop();
            }
        }
    }
}


int main()
{
    char infix[]="(a+b*c)";
    char postfix[MAX];
    convert(infix,postfix);
    for(int i=0; postfix[i]!='\0'; i++)
    {
        cout<<postfix[i];
    }

}
