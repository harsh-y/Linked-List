#include <iostream>
using namespace std;

int ar[25],size,front= - 1,rear = - 1;
void Insert(int x)
{
   if ((front==0 && rear==size-1) || rear==(front-1)%(size-1))
   {
       cout<<"\nOverflow"<<endl;
   }
    else if (front==-1)
      {
          front=0;
          rear=0;
          ar[rear]=x;
      }
    else if (rear == size-1 && front != 0)
       {
           rear = 0;
           ar[rear]=x;
       }
    else
       {
           rear++;
           ar[rear]=x;
       }
}
void Delete()
{
   if (front==-1)
    {
      cout<<"\nUnderflow ";
      return ;
   }
   else if(front==rear)
   {
       front=-1;
       rear=-1;
   }
   else if(front==size-1)
   {
       cout<<ar[front]<<" deleted\n";
       front=0;
   }
   else
   {
      cout<<ar[front]<<" deleted\n";
      front++;;
   }
}
void Display()
{
   if (front==-1)
   cout<<"\nQueue is empty"<<endl;
   else if(rear>=front)
   {
      cout<<"\nElements are : ";
      for (int i=front;i<=rear;i++)
      cout<<ar[i]<<" ";
   }
   else
   {
       for(int i=front;i<=size-1;i++)
       {
           cout<<ar[i]<<" ";
       }
       for(int i=0;i<=rear;i++)
       {
           cout<<ar[i]<<" ";
       }
   }
}
int main()
{
   int n,a;
   char ch;
   cout<<"\nEnter Size of queue ";
   cin>>size;
   cout<<"1) Insert"<<endl;
   cout<<"2) Delete"<<endl;
   cout<<"3) Display"<<endl;
   do {
      cout<<"\nEnter choice: ";
      cin>>n;
      switch (n)
      {
         case 1:
             cout<<"\nEnter value to be entered in queue ";
             cin>>a;
             Insert(a);
         break;
         case 2:
             Delete();
             break;
         case 3:
             Display();
             break;
         default:
             cout<<"\nInvalid choice";
      }
      cout<<"\nWant to continue?";
      cin>>ch;
   } while(ch=='y'||ch=='Y');
   return 0;
}
