#include<iostream>
using namespace std;
int reverse(int n,int r)
{
    if(n==0)
    {
        return r;
    }
    r = r*10+n%10;
    return reverse(n/10,r);

}
int main()
{
    int x;
    cout<<"\nENter the number to be reversed";
    cin>>x;
    cout<<reverse(x,0);
}
