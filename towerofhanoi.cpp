#include<iostream>
using namespace std;
void tower(int n,char from, char to , char aux)
{
    if(n==1)
    {
        cout<<"\nMove disk 1 from"<<from<<"to"<<to;
        return ;
    }
    tower(n-1,from,aux,to);
    cout<<"\nMove disk "<<n<<" from"<< from <<"to"<<to;
    tower(n-1,aux,to,from);
}
int main()
{
    cout<<"\nenter the number of disks";
    int n;
    cin>>n;
    tower(n,'A','B','C');
}
