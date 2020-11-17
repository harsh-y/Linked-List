#include <iostream>
using namespace std;

struct node
{
   int info;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* head;
void enqueue(int x)
{
   if (rear==NULL)
    {
      struct node* head=new node;
      head->info=x;
      head->next=NULL;
      front=head;
      rear=head;
   }
   else
    {
      struct node* head=new node;
      rear->next=head;
      head->info=x;
      head->next=NULL;
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
   while (head!=NULL)
   {
      cout<<head->info<<" ";
      head=head->next;
   }
}
int main()
{
   int n,a;
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
             cout<<"\nEnter value to be entered in queue "<<endl;
             cin>>a;
             enqueue(a);
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
