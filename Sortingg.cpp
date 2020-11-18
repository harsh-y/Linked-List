#include<iostream>
 #include<limits>

 using namespace std;

 template <class T>
 class Sort
{
  T ar[25];
  int size;
 public:
  void input()
  {
      cout<<"Enter size of the array ";
      cin>>size;
      cout<<"\nEnter elements in Array"<<endl;
      for(int i=0;i<size;i++)
        {
            cin>>ar[i];
        }
  }
  void insertionsort()
  {
      T temp;
      int j;
      for(int i=1;i<size;i++)
        {
            temp=ar[i];
            j=i-1;
            while(temp<ar[j])
                {
                    ar[j+1]=ar[j];
                    j--;
                }
            ar[j+1]=temp;
        }
    }
    void bubblesort()
    {
        T temp;
        for(int i=0;i<size;i++)
            {
                for(int j=0;j<size-i-1;j++)
                {
                    if(ar[j]>ar[j+1])
                    {
                        temp=ar[j];
                        ar[j]=ar[j+1];
                        ar[j+1]=temp;
                    }
                }
            }
    }
    void selectionsort()
    {
        T temp;
        for(int i=0;i<size;i++)
            {
                for(int j=i+1;j<size;j++)
                {
                    if(ar[i]>ar[j])
                    {
                        temp=ar[i];
                        ar[i]=ar[j];
                        ar[j]=temp;
                    }
                }
            }
    }
    void display()
    {
        for(int i=0;i<size;i++)
            {
                cout<<ar[i]<<" ";
            }
    }
 };

int main()
{
  Sort<int> arr;
  int n;
  char ch;
  arr.input();
  arr.display();
  do
  {
      cout<<"\nSelect the Sorting method";
      cout<<"\n1.Insertion Sort";
      cout<<"\n2.Bubble Sort";
      cout<<"\n3.Selection Sort\n";
      cin>>n;
      switch(n)
      {
      case 1:
        cout<<"\nSorted Array (Insertion sort)\n";
        arr.insertionsort();
        arr.display();
        break;
      case 2:
        cout<<"\nSorted Array (Bubble sort)\n";
        arr.bubblesort();
        arr.display();
        break;
      case 3:
        cout<<"\nSorted Array (Selection sort)\n";
        arr.selectionsort();
        arr.display();
        break;
      default:
        cout<<"\nInvalid choice";
        break;
      }
      cout<<"\nWant to Continue ? (Y/N)";
      cin>>ch;
  }while(ch=='Y'||ch=='y');
  return 0;
 }
