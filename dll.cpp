#include<iostream>
using namespace std;

class list
{
     struct node
    {
        float info;
        struct node *next;
        struct node *prev;
    }*first,*last,*head, *temp,*temp1;
public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    ~list()
    {
        temp=first;
        while(temp!=NULL)
        {
            temp=temp->next;
            delete first;
            first=temp;
        }
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
        if(first==NULL)
        {
            first=head;
            last=head;
        }
    else
        {
            last->next=head;
            head->prev=last;
            last=head;
        }
        cout<<"\n want to enter more ??";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}
void insertfirst()
{
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->next=NULL;
    head->prev=NULL;
    head->next=first;
    first->prev=head;
    first=head;
}
void insertpos()
{
    int pos;
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->next=NULL;
    head->prev=NULL;
    cout<<"\nEnter the position (1 is the first position) ";
    cin>>pos;
    if(pos<1)
    {
        cout<<"\nInvalid Input";
    }
    else if(pos==1)
    {
        insertfirst();
    }
    else
    {
        temp=first;
    for(int i=1;i<(pos-1);++i)
    {
        temp=temp->next;
    }
    head->next=temp->next;
    head->prev=temp;
    temp->next=head;
    }
}
void delbegin()
{
    if(first=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=first;
        first=temp->next;
        first->prev=NULL;
        delete temp;
    }
}
void delend()
{
    if(first=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=last->prev;
        last=temp;
        temp=temp->next;
        last->next=NULL;
        delete temp;
    }
}
void delpos()
{
    if(first=NULL)
    {
        cout<<"\nlinked list is empty";
    }
    int pos;
    cout<<"\nEnter the position";
    cin>>pos;
    if(pos==1)
    {
        delbegin();
    }
    else
    {
        temp=first;
        temp1=first;
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
void reversedll()
{
    temp=last;
    while(temp!=NULL)
    {
        cout<<temp->info;
        temp=temp->prev;
    }
}
void display()
    {
        cout<<"The list is as follows : ";
        temp=first;
        while(temp!=NULL)
        {
         cout<<temp->info<<" ";
         temp=temp->next;
        }
    }
 void searchdll()
    {
        int ctr,i=1,flag=0;
        cout<<"\nEnter element to be found ";
        cin>>ctr;
        temp=first;
        while(temp!=NULL)
        {
            if(temp->info==ctr)
            {
                cout<<"\nElement found at "<<i<<" position ";
                flag=1;
                break;
            }
            temp=temp->next;
            i++;
        }
         if(flag==0)
            {
                cout<<"\nItem not found ";
            }
    }
};
int main()
    {

        list a1;
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
            cout<<"\n7.Reverse list";
            cout<<"\n8.Search Element";
            cout<<"\n9.Display linked list";
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
		case 5 :
			a1.delbegin();
			break;
		case 6 :
			a1.delpos();
			break;
		case 7 :
			a1.reversedll();
			a1.display();
			break;
        case 8 :
            a1.searchdll();
            break;
        case 9 :
            a1.display();
            break;
	}
            cout<<"\nwant to continue ?? ";
            cin>>chh;
        }while(chh=='y'||chh=='Y');
       return 0;
    }

