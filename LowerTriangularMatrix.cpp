#include<iostream>
#include<stdlib.h>
using namespace std;

class lowertriangular
{
private:
    int *ar;
	int x,n;
public:
	 lowertriangular(int size=10)
	 {
	 	 n=size;
	 	 if(size!=0)
	 	 {
	 	 	ar=new int[n*(n+1)/2];
	 	 }
	 }
	 ~lowertriangular()
	 {
	 	delete []ar;
	 }
	 void input(int val,int i,int j)
	 {
	     if(i<j && val!=0)
         {
            cout<<"\nReplaced by 0";
         }
         else
         {
            x=(i*(i-1)/2)+j;
            ar[x]=val;
         }
	 }
	 int getvalue(int i,int j)
	 {
	      if (i>=j)
        {
             x=(i*(i-1)/2)+j;
             return ar[x];
        }
        else
        {
            return 0;
        }
	 }
	 void display()
	 {
	      int m=1;
	     cout<<"\n--Matrix--\n";
	     for(int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (i<j)
                    {
                        cout<<"0"<<" ";
                    }
                    else
                    {
                        cout<<ar[m++]<<" ";
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
	lowertriangular lt(row);
	cout<<"\nEnter the elements of array\n";
	for (i=1;i<=row;++i)
	{
		for (j=1;j<=col;++j)
		{
			if(i>=j)
			{
				cin>>a;
	            lt.input(a,i,j);
			}
		}
	}
    lt.display();
    cout<<"\nEnter the location\n";
    cin>>i>>j;
    cout<<"value is "<<lt.getvalue(i,j)<<"\n";
	return 0;
}
