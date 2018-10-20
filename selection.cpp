#include<iostream>
using namespace std;
void selection(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = a[i];
        int pos = i;
        for(int j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min = a[j];
                pos = j;
            }
        }

       int t = a[i];
       a[i] = a[pos];
       a[pos] = t;

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
    selection(a,n);
    cout<<"\nElements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
