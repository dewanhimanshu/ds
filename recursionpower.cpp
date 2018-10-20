#include<iostream>
using namespace std;
float power(float x , int y)
{
    if(y==0)
        return 1;
    return x*power(x,y-1);

}

int main()
{
cout<<"\nEnter the number";
float x;
int y;
cin>>x;
cout<<"\nenter the value of power";
cin>>y;

cout<<"\n Answers is "<<power(x,y);


}
