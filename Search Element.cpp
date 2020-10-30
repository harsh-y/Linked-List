#include<iostream>

using namespace std;

int Search(int ar[] , int size , int val)
{
        for (int i=0;i<size;i ++)
    {
        if (ar[i]==val)
        {
            return i+1;
        }
    }
            return -1;
}

int main()
{
    int ar[30],size,val, pos;
    cout<<"Enter size of array : ";
    cin>>size;
    cout<<"Enter Elements"<<endl;
    for (int i = 0; i <size; i ++)
    {
        cin >> ar[i];
    }
    cout<<"Element to be searched = " ;
    cin>>val;
    pos=Search(ar,size,val);
    if (pos!= -1 )
        cout<<"Element found at index no. "<<pos;
    else
        cout<<"Element not found";
    return 0;
}
