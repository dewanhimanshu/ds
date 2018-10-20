#include<iostream>
using namespace std;
#define MAX 100
class DigonalMatrix
{

    int b[MAX];
    int size;

    public:
        DigonalMatrix()
        {
            size = 0;
            for(int i=0;i<MAX;i++)
            {
                b[i] = 0;

            }
        }
        void set()
        {
            cout<<"\nEnter the number of elements you want to enter";
            cin>>size;
            while(size>MAX)
            {
                cout<<"\nLooks Like You Want To Do Big Calculation. Sorry We Support Size Of 100 only . Enter The Size";
                cin>>size;
            }
            cout<<"\n Enter "<<size<<" Elements ";
            for(int i=0;i<size;i++)
            {
                cin>>b[i];
            }
            show();
        }
        void get()
        {
            int i = 0;
            int j = 0;

            while(i!=-1&&j!=-1)
            {
            cout<<"\n Enter The Value of Indexes";
            cin>>i>>j;
                if(i>size || j>size)
                {
                    cout<<"\n This Index does not exist";
                }
                else if(i<0||j<0)
                {
                    cout<<"negative index does not exist in cs world";
                }
                else if(i!=j)
                {
                    cout<<0;
                }
                else
                {
                 cout<<b[i];
                }

            }

        }
        void show()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(i==j)
                    cout<<b[i]<<" ";
                    else
                        cout<<0<<" ";
                }
                cout<<endl;

            }
            cout<<endl;
        }


};

class LowerTriangle
{

    int b[MAX];
    int size;
    int ne;

    public:
        LowerTriangle()
        {
            size = 0;
            for(int i=0;i<MAX;i++)
            {
                b[i] = 0;

            }
        }
        void set()
        {
            cout<<"\nEnter the number of rows you want to enter";
            cin>>size;
            while(size>MAX)
            {
                cout<<"\nLooks Like You Want To Do Big Calculation. Sorry We Support Size Of 100 only . Enter The Size";
                cin>>size;
            }
            int asize = (size*(size+1))/2;
            cout<<"\n Enter "<<asize<<" Elements ";

            for(int i=0;i<asize;i++)
            {
                cin>>b[i];
            }
            show();
        }

        void get()
        {
            int i = 0;
            int j = 0;

            while(i!=-1&&j!=-1)
            {
            cout<<"\n Enter The Value of Indexes";
            cin>>i>>j;

                if(i>size || j>size)
                {
                    cout<<"\n This Index does not exist";
                }
                else if(i<0||j<0)
                {
                    cout<<"negative index does not exist in cs world";
                }
                else if(i<j)
                {
                    cout<<0;
                }
                else
                {
                 int k = (i*(i+1))/2 + j;
                 cout<<b[k];
                }

            }

        }
          void show()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(i>=j){
                    int k = (i*(i+1))/2 + j;
                    cout<<b[k]<<" ";
                    }
                    else
                        cout<<0<<" ";
                }
                cout<<endl;

            }
            cout<<endl;
        }


};
class UpperTriangular
{
    int b[MAX];
    int size;
    int asize;
    public:
        UpperTriangular()
        {
            size = 0;
            asize =0;
            for(int i=0;i<MAX;i++)
            {
                b[i] = 0;

            }
        }
        void set()
        {
            cout<<"\nEnter the number of rows you want to enter";
            cin>>size;
            while(size>MAX)
            {
                cout<<"\nLooks Like You Want To Do Big Calculation. Sorry We Support Size Of 100 only . Enter The Size";
                cin>>size;
            }
             asize = (size*(size+1))/2;
            cout<<"\n Enter "<<asize<<" Elements ";

            for(int i=0;i<asize;i++)
            {
                cin>>b[i];
            }

        }
        void get()
        {
            int i = 0;
            int j = 0;

            while(i!=-1&&j!=-1)
            {
                cout<<"\n Enter The Value of Indexes";
                cin>>i>>j;


                if(i>=size&&j>=size)
                {
                    cout<<"\ninvalid index";
                    return ;
                }
                else if(i>j)
                {
                    cout<<0;
                }
                else
                {

                    int lower_elements = ((size-i)*(size-i+1))/2 ;
                    int total = (size)*(size+1);
                    int k = total/2 - lower_elements + (j-i);
                    cout<<k<<endl;
                    cout<<endl<<b[k];
                }
            }
        }




};

int main()
{
    cout<<"********Menu Driven Program**************\n";
    cout<<"1,Digonal Matrix\n";
    cout<<"2.Lower Triangular Matrix\n";
    cout<<"3.Upper Triangular Matrix\n";
    cout<<"enter your choice";
    int ch;
    cin>>ch;
    if(ch == 1)
    {
        DigonalMatrix m;
        cout<<"********Menu Driven Program**************\n";
        cout<<"\n1.Set The Matrix";
        cout<<"\n2.Get The Matrix";
        cout<<"\n3 Exit";

        int k;

        while(true)
        {
            cout<<"\nenter your choice";
            cin>>k;
            if(k==1)
            {
                m.set();
            }
            else if(k==2)
            {
                m.get();
            }
            else if(k==3)
            {
                break;
            }
            else
            {
                cout<<"\n not a valid option";
            }
        }

    }
    else if(ch==2)
    {
        LowerTriangle m;
        cout<<"********Menu Driven Program**************\n";
        cout<<"\n1.Set The Matrix";
        cout<<"\n2.Get The Matrix";
        cout<<"\n3 Exit";

        int k;

        while(true)
        {
            cout<<"\nenter your choice";
            cin>>k;
            if(k==1)
            {
                m.set();
            }
            else if(k==2)
            {
                m.get();
            }
            else if(k==3)
            {
                break;
            }
            else
            {
                cout<<"\n not a valid option";
            }
        }
    }
    else if(ch==3)
    {
         UpperTriangular m;
         cout<<"********Menu Driven Program**************\n";
        cout<<"\n1.Set The Matrix";
        cout<<"\n2.Get The Matrix";
        cout<<"\n3 Exit";

        int k;

        while(true)
        {
            cout<<"\nenter your choice";
            cin>>k;
            if(k==1)
            {
                m.set();
            }
            else if(k==2)
            {
                m.get();
            }
            else if(k==3)
            {
                break;
            }
            else
            {
                cout<<"\n not a valid option";
            }
        }



    }

}
