#include<iostream>
using namespace std;
int linear(int a[] ,int n ,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    int a[n];
    cout<<"\nEnter "<<n<<" elements:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cout<<"\nEnter the elements to search";
    cin>>x;
    cout<<linear(a,n,x);
}
