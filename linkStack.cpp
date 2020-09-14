#include <iostream>
using namespace std;

struct node
{
   int info;
   struct node *next;
};
struct node* top=NULL;
void push(int x)
{
   struct node* head=new node;
   head->info=x;
   head->next=top;
   top=head;
}
void pop()
{
   if(top==NULL)
   cout<<"\nUnderflow";
   else
   {
      cout<< top->info<<" popped\n ";
      top=top->next;
   }
}
void display()
{
   struct node* head;
   if(top==NULL)
   cout<<"\nStack is empty";
   else
    {
      head=top;
      cout<<"\nElements are: ";
      while (head!=NULL)
      {
         cout<<head->info<<" ";
         head=head->next;
      }
   }
   cout<<endl;
}
int main() {
   int n, a;
   char ch;
   cout<<"1) Push"<<endl;
   cout<<"2) Pop"<<endl;
   cout<<"3) Display"<<endl;
   do
    {
      cout<<"\nEnter choice: ";
      cin>>n;
      switch(n)
      {
         case 1:
            cout<<"\nEnter value to be entered in stack ";
            cin>>a;
            push(a);
            break;
         case 2:
            pop();
            break;
         case 3:
            display();
            break;
         default:
            cout<<"\nInvalid Choice"<<endl;
         }
         cout<<"\nWant to continue? ";
         cin>>ch;
   }while(ch=='y'||ch=='Y');
   return 0;
}
