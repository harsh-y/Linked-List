#include<iostream>
#include<stdlib.h>
using namespace std;

class diagonal
{
private:
    int *ar;
	int n;
public:
	 diagonal(int size=10)
	 {
	 	 n=size;
	 	 if(size!=0)
	 	 {
	 	 	ar=new int[n];
	 	 }
	 }
	 ~diagonal()
	 {
	 	delete []ar;
	 }
	 void input(int val,int i,int j)
	 {
	     if(i!=j && val!=0)
	     {
		cout<<"\nReplaced by 0";
	     }
	     else if(i==j)
	     {
		ar[i]=val;
	     }
	 }
	 int getvalue(int i,int j)
	 {
	     if (i==j)
	     {
		return ar[i];
	     }
        else
        {
            return 0;
        }
	 }
	 void display()
	 {
	     cout<<"\n--Matrix--\n";
	     for(int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (i!=j)
                    {
                        cout<<"0"<<" ";
                    }
                    else
                        {
                            cout<<ar[i]<<" ";
                        }
                }
                cout<<"\n";
            }
    }
};

int main()
{

	int a,row,col,i,j;
	cout<<"\nEnter no. of rows in matrix  ";
	cin>>row;
	cout<<"\nEnter no. of columns in matrix  ";
	cin>>col;
	if(row!=col)
	{
		cout<<"\nRows and Columns should be equal";
		exit(0);
	}
	diagonal d(row);
	cout<<"\nEnter the elements of array\n";
	for (i=1,j=1;i<=row,j<=col;++i,++j)
	{
		cin>>a;
	    d.input(a,i,j);
	}
    d.display();
    cout<<"\nEnter the location\n";
    cin>>i>>j;
    cout<<"value is "<<d.getvalue(i,j)<<"\n";
	return 0;
}
