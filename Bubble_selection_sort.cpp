#include<iostream>
using namespace std;
#define size 5
class Sort
{
public:
	float a[size];
	void accept()
	{
		cout<<"\n Enter marks of students to be sorted:";
		for(int i=0;i<size;i++)
		{
			cin>>a[i];
		}
	}

	void bubble()
	{
		cout<<"\n Using bubble sort:";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size-1;j++)
			{
				if(a[j]>a[j+1])
				{
					float temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}

	void selection()
	{
		cout<<"\n Using selection sort:";
        int i,j,min,temp;
        for(i=0;i<size;i++)
        {
            min =i;
            for(j=i+1;j<size;j++)
            {
                if(a[min]>a[j])
                {
                    min =j;
                }
            }

            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
	}

	void display()
	{
		cout<<"\n Sorted marks list is:";
		for(int i=0;i<size;i++)
		{
			cout<<"  "<<a[i];
		}
		cout << "\n Top five scores : ";
		for(int i=size-1;i>=size-5;i--)
		{
			cout<<"  "<<a[i];
		}
	}
};
int main()
{
	Sort s;
	int ch;
	while(1)
	{
        cout << "\n1.Enter data \n2.Bubble sort \n3.Selection sort \n4.Exit";
		cout<<"\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
            case 1:
                s.accept();
                break;
            case 2:
				s.bubble();
				s.display();
				break;
            case 3:
				s.selection();
				s.display();
				break;
            case 4:
                return 0;
		}
	}

	return 0;
}

