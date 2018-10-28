#include<iostream>
using namespace std;
int partition(int a[],int start,int end)
{
    int pivot = a[start];
    int left = start , right = end;
    while(left<right)
    {
        if(a[left]<=pivot)
        {
            left++;
        }
        if(a[right]>pivot)
        {
            right--;
        }
        else
        {
            int t = a[left];
            a[left] = a[right];
            a[right] = t;

        }


    }
    a[start] = a[right];
    a[right] = pivot;

    return right;

}

void quicksort(int a[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int p = partition(a,start,end);
    quicksort(a,start,p-1);
    quicksort(a,p+1,end);

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
    quicksort(a,0,n-1);
    cout<<"\nElements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
