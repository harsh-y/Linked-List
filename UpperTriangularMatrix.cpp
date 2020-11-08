#include<iostream>
#include<stdlib.h>
using namespace std;

class uppertriangular
{
private:
    int *ar;
	int x,n;
public:
	 uppertriangular(int size=10)
	 {
	 	 n=size;
	 	 if(size!=0)
	 	 {
	 	 	ar=new int[n*(n+1)/2];
	 	 }
	 }
	 ~uppertriangular()
	 {
	 	delete []ar;
	 }
	 void input(int val,int i,int j)
	 {
	     if(i>j && val!=0)
         {
            cout<<"\nReplaced by 0";
         }
         else
         {
            x=(j*(j-1)/2)+i-1;
            ar[x]=val;
         }
	 }
	 int getvalue(int i,int j)
	 {
	      if (i>=j)
        {
             x=(j*(j-1)/2)+i-1;
             return ar[x];
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
                    if (i>j)
                    {
                        cout<<"0"<<" ";
                    }
                    else
                    {
                        x=(j*(j-1)/2)+i-1;
                        cout<<ar[x]<<" ";
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
	uppertriangular ut(row);
	cout<<"\nEnter the elements of array\n";
	for (i=1;i<=row;++i)
	{
		for (j=1;j<=col;++j)
		{
			if(i<=j)
			{
				cin>>a;
	            ut.input(a,i,j);
			}
		}
	}
    ut.display();
    cout<<"\nEnter the location\n";
    cin>>i>>j;
    cout<<"value is "<<ut.getvalue(i,j)<<"\n";
	return 0;
}
