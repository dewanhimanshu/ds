#include<iostream>
using namespace std;
void insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j = i-1;
        while(j>=0&&key<a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;
    }
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
    insertion(a,n);
    cout<<"\nElements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
