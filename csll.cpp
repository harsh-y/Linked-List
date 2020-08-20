#include<iostream>
using namespace std;

    class circularlist
{
    struct node
    {
        float info;
        struct node *ptr;
    }*head,*temp,*temp1,*last;
public:
    circularlist()
    {
        last=NULL;
    }
    void create()
{
    char ch;
    do
    {
        struct node* head=new node;
        cout<<"\nEnter data to be entered in the list ";
        cin>>head->info;
        head->ptr=NULL;
        if(last==NULL)
        {
            head->ptr=head;
            last=head;
        }
        else
        {
            head->ptr=last->ptr;
            last->ptr=head;
            last=head;
        }
        cout<<"\nWant to enter more ?? ";
        cin>>ch;
    }while(ch=='Y'||ch=='y');
}
void insertlast()
{
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->ptr=NULL;
    head->ptr=last->ptr;
    last->ptr=head;
    last=head;
}
void insertfirst()
{
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->ptr=NULL;
    head->ptr=last->ptr;
    last->ptr=head;
}
void insertpos()
{
    int pos;
	struct node* head=new node;
	cout<<"\nEnter data to be inserted ";
    cin>>head->info;
	head->ptr=NULL;
	cout<<"\nInsert position (1st position is the start)";
	cin>>pos;
	temp=last->ptr;
	for(int i=1;i<pos-1;++i)
    {
        temp=temp->ptr;
    }
	head->ptr=temp->ptr;
	temp->ptr=head;
}
void delend()
{
    if(last=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=last->ptr;
        temp1=last;
        while(temp->ptr!=last)
        {
            temp=temp->ptr;
        }
        temp->ptr=last->ptr;
        last=temp;
        delete temp1;
    }
}
void delbeg()
{
    {
    if(last=NULL)
        cout<<"\nlink list is empty ";
    else
    {
    temp=last->ptr;
    last->ptr=temp->ptr;
    delete temp;
    }
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
        temp=last->ptr;
        temp1=last->ptr;
        for(int i=1;i<(pos-1);++i)
        {
            temp=temp->ptr;
        }
        temp1=temp->ptr;
        temp->ptr=temp1->ptr;
        delete temp1;
    }
}
    void display()
    {
        cout<<"The list is as follows : ";
        temp=last->ptr;
        while(temp->ptr!=last->ptr)
        {
         cout<<temp->info<<" ";
         temp=temp->ptr;
        }
        cout<<last->info;
    }
};
    int main()
    {
        circularlist a1;
        char chh;
        int n;
do
        {
            cout<<"\n1.Create a linked list";
            cout<<"\n2.Insert Element at end";
            cout<<"\n3.Insert Element at begining";
            cout<<"\n4.Insert at position";
            cout<<"\n5.Delete from End";
            cout<<"\n6.Delete from begining";
            cout<<"\n7.Delete from position";
            cout<<"\n8..Display linked list";
            cout<<"\nEnter Choice ";
            cin>>n;
            switch(n)
	{
		case 1 :
			a1.create();
			break;
		case 2 :
			a1.insertlast();
			break;
		case 3 :
			a1.insertfirst();
			break;
		case 4 :
			a1.insertpos();
			break;
		case 5 :
			a1.delend();
		case 6 :
			a1.delbeg();
			break;
		case 7 :
			a1.delpos();
			break;
        case 8 :
            a1.display();
            break;
	}
        cout<<"\nwant to continue ?? ";
        cin>>chh;
        }while(chh=='y'||chh=='Y');
    return 0;
    }

