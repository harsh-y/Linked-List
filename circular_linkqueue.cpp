#include <iostream>
using namespace std;

struct node
{
   int info;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
void enqueue()
{
    int x;
    cout<<"\nEnter value to be entered in queue "<<endl;
    cin>>x;
    if (rear==NULL)
    {
      struct node* head=new node;
      head->info=x;
      head->next=front;
      front=head;
      rear=head;
    }
    else
    {
      struct node* head=new node;
      rear->next=head;
      head->info=x;
      head->next=front;
      rear=head;
   }
}
void dequeue()
{
   if (front==NULL)
    {
      cout<<"\nUnderflow";
    }
   else if(head==rear)
    {
      cout<<front->info<<" deleted\n";
      front=NULL;
      rear=NULL;
    }
   else
    {
        head=front;
        front=front->next;
        cout<<head->info<<" deleted\n";
        rear->next=front;
        delete head;
    }
}
void Display()
{
   head=front;
   if(front==NULL && rear==NULL)
    {
      cout<<"\nQueue is empty";
   }
   cout<<"\nElements are: ";
   while (head->next!=front)
   {
      cout<<head->info<<" ";
      head=head->next;
   }
   cout<<head->info;
}
int main()
{
   int n;
   char ch;
   cout<<"1) enqueue"<<endl;
   cout<<"2) dequeue"<<endl;
   cout<<"3) Display"<<endl;
   do
    {
      cout<<"\nEnter your choice: "<<endl;
      cin>>n;
      switch (n)
      {
         case 1:
             enqueue();
             break;
         case 2:
             dequeue();
             break;
         case 3:
             Display();
             break;
         default:
             cout<<"\nInvalid choice";
      }
      cout<<"\nWant to continue? ";
      cin>>ch;
   } while(ch=='y'||ch=='Y');
   return 0;
}
