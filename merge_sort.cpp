#include<iostream>
using namespace std;
void merge(int a[],int n,int left[],int l,int right[],int r)
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)
    {
        if(left[i]<right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }
    while(i<l)
    {
        a[k++] = left[i++];
    }
    while(j<r)
    {
        a[k++] = right[j++];
    }

}
void merge_sort(int a[],int n)
{
    if(n<=1)
    {
        return;
    }
    int l = n/2;
    int r = (n-(n/2));
    int left[l];
    int right[r];
    int k=0;
    for(int i=0;i<l;i++)
    {
        left[i] = a[k++];
    }
    for(int i=0;i<r;i++)
    {
        right[i] = a[k++];
    }
    merge_sort(left,l);
    merge_sort(right,r);
    merge(a,n,left,l,right,r);
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
    merge_sort(a,n);
    cout<<"\nElements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
