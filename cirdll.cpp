#include<iostream>
using namespace std;

class circulardll
{
    struct node
    {
        float info;
        struct node *next;
        struct node *prev;
    }*last,*head, *temp,*temp1;
	public:
	    circulardll()
		{
		    last=NULL;
		}
		void insertlast()
		{
		     char ch;
    do
    {
		    struct node* head=new node;
		    cout<<"\nEnter data to be entered in the list ";
            cin>>head->info;
            head->next=NULL;
            head->prev=NULL;
	        if(last == NULL)
                {
                    head->next=head;
		            head->prev=head;
                    last=head;
                }
	        else
                {
                    head->next=last->next;
                    head->prev=last;
                    last->next=head;
                    last=head;
                }
                 cout<<"\nWant to enter more ?? ";
        cin>>ch;
    }while(ch=='Y'||ch=='y');
        }

		void insertfirst()
		{
		    struct node* head=new node;
		    cout<<"\nEnter data to be entered in the list ";
            cin>>head->info;
            head->next=NULL;
            head->prev=NULL;
            head->next=last->next;
            last->next->prev=head;
            head->prev=last;
        }
		void insertpos()
		{
		    int pos;
		    struct node* head=new node;
		    cout<<"\nEnter data to be inserted ";
		    cin>>head->info;
		    head->next=NULL;
		    head->prev=NULL;
		    cout<<"\nInsert position (1st position is the start)";
		    cin>>pos;
		    temp= last->next;
		    for(int i=1;i<(pos-1);++i)
                {
                    temp=temp->next;
                }
                head->next=temp->next;
                temp->next->prev=head;
                head->prev=temp;
                temp->next=head;
        }
		void delend()
		{
		    if(last=NULL)
                cout<<"\nlink list is empty ";
            else
                {
                    temp=last->prev;
                    last=temp;
                    temp=temp->next;
                    last->next=temp->next;
                    delete temp;
                }
            }
		void delbeg()
		{
		     if(last=NULL)
                cout<<"\nlink list is empty ";
             else
                {
                    temp=last->next;
                    temp->next->prev=last;
                    last->next=temp->next;
                    delete temp;
                }
        }
        void delpos()
        {
            if(last=NULL)
                {
                    cout<<"\nlinked list is empty";
                }
            int pos;
            cout<<"\nEnter the position";
            cin>>pos;
            if(pos==1)
                {
                    delbeg();
                }
                else
                    {
                        temp = last->next;
                for(int i=1;i<(pos-1);++i)
                    {
                        temp=temp->next;
                    }
                    temp1=temp->next;
                    temp->next=temp1->next;
                    temp1->next->prev=temp;
                    delete temp1;
                    }
        }
		void searchlistt()
		{
		    int ctr,i=1,flag=0;
            cout<<"\nEnter element to be found ";
            cin>>ctr;
            temp=last->next;
		    while(temp->next!=last->next)
		    {
		       if(temp->info==ctr)
            {
                cout<<"\nElement found at "<<i<<" position ";
                flag=1;
                break;
            }
                    temp = last->next;
                    i++;
            }
            if(last->info==ctr)
            {
                cout<<"\nElement found at "<<i<<"position ";
                flag=1;
            }
                    if(flag==0)
                        cout<<"\nItem not found";
		}
         void display()
         {
             cout<<"The list is as follows : ";
             temp=last->next;
             while(temp->next!=last->next)
             {
                 cout<<temp->info<<" ";
                 temp=temp->next;
             }
             cout<<temp->info;
        }
};

int main()
{
	circulardll a1;
        char chh;
        int n;
do
        {
            cout<<"\n1.Insert Element at end";
            cout<<"\n2.Insert Element at begining";
            cout<<"\n3.Insert at position";
            cout<<"\n4.Delete from End";
            cout<<"\n5.Delete from begining";
            cout<<"\n6.Delete from position";
            cout<<"\n7..Display linked list";
            cout<<"\n8.Search element";
            cout<<"\nEnter Choice ";
            cin>>n;
            switch(n)
	{
		case 1 :
			a1.insertlast();
			break;
		case 2 :
			a1.insertfirst();
			break;
		case 3 :
			a1.insertpos();
			break;
		case 4 :
			a1.delend();
			a1.display();
			break;
		case 5 :
			a1.delbeg();
			a1.display();
			break;
		case 6 :
			a1.delpos();
			a1.display();
			break;
        case 7 :
            a1.display();
            break;
        case 8:
            a1.searchlistt();
            break;
	}
        cout<<"\nwant to continue ?? ";
        cin>>chh;
        }while(chh=='y'||chh=='Y');
    return 0;
    }
