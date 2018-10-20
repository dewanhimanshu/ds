#include<iostream>
using namespace std;
void merge(int a[],int a ,int l[] ,int ln ,int r[],int rn )
{
    if()
}

void mergesort(int a[],int n)
{
    if(n==1)
    {
        return ;
    }
    int l[n/2];
    int r[n-n/2];
    for(int i=0;i<n/2;i++)
    {
        l[i] = a[i];
    }
    for(int i=((n/2) + 1),j=0;i<n;i++,j++)
    {
        r[j] = a[i];
    }
    mergesort(l,n/2);
    mergesort(r,n-n/2);
    merge(a,n,l,n/2,r,n-n/2);

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
    mergesort(a,n);
    cout<<"\nElements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
