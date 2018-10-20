#include<iostream>
using namespace std;
int partition(int a[],int start,int end)
{
    int pivot = a[start];
    int count = 0;
    for(int i=start+1;i<=end;i++)
    {
        if(a[i]<=pivot)
        {
            count++;
        }
    }
    count = start+ count;
    int temp = a[count];
    a[count] = pivot;
    a[start] = temp;

    int i = start , j = end;
    while(i<=count&&j>=count)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(a[i]>pivot&&a[j]<pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;

        }
    }
    return count;

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
