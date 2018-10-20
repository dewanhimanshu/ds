#include<iostream>
using namespace std;
int binary(int a[],int n,int x)
{
    int start = 0 , end = n-1;
    while(start<=end)
    {
        int mid =(start+end)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if(a[mid]<x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid -1;
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
    cout<<binary(a,n,x);
}
