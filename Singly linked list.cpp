#include<iostream>
using namespace std;

    class list
{
    struct node
    {
        float info;
        struct node *ptr;
    }*head,*temp,*temp1,*first,*last;
public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    ~list()
    {
        temp=first;
        while(temp->ptr!=NULL)
        {
            temp=temp->ptr;
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
        head->ptr=NULL;
        if(first==NULL)
        {
            first=head;
            last=head;
        }
    else
        {
            last->ptr=head;
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
    head->ptr=NULL;
    head->ptr=first;
    first=head;
}
void insertpos()
{
    int pos;
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->ptr=NULL;
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
        temp=temp->ptr;
    }
    head->ptr=temp->ptr;
    temp->ptr=head;
    }
}
void delbegin()
{
    if(first=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=first;
        first=temp->ptr;
        delete temp;
    }
}
void delend()
{
    if(first=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=first;
        temp1=last;
        while(temp->ptr!=last)
        {
            temp=temp->ptr;
        }
        temp->ptr=NULL;
        last=temp;
        delete temp1;
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
            temp=temp->ptr;
        }
        temp1=temp->ptr;
        temp->ptr=temp1->ptr;
        delete temp1;
    }
}
void reverselist()
{
	temp=first;
	head=temp1=NULL;
	while(temp!=NULL)
	{
		temp1=temp->ptr;
		temp->ptr=head;
		head=temp;
		temp=temp1;
	}
	last=first;
	first=head;
}
    void display()
    {
        cout<<"The list is as follows : ";
        temp=first;
        while(temp!=NULL)
        {
         cout<<temp->info<<" ";
         temp=temp->ptr;
        }
    }
    void searchlist()
    {
        int ctr,i=1,flag=0;
        cout<<"\nEnter element to be found ";
        cin>>ctr;
        temp=first;
        while(temp->ptr!=NULL)
        {
            if(temp->info==ctr)
            {
                cout<<"\nElement found at "<<i<<"position ";
                flag=1;
                break;
            }
            temp=temp->ptr;
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
			a1.reverselist();
			a1.display();
			break;
        case 8 :
            a1.searchlist();
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

