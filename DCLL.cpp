#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
	int status;
	char name[25];
	Node *next,*prev;
};

class Theater
{
	Node *a[10];
public:
	Node *header,*nn;
	Theater()           //Creates 10x7 Nodes as seats in row and column
	{
		header=NULL;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<7;j++)
			{
				Node *cn;
                nn=new Node;
				nn->status=0;
				if(j==0)
				{
					a[i]=nn;
					a[i]->prev=a[i];
					a[i]->next=a[i];
				}
				else
				{
					cn=a[i];
					do
					{
						cn=cn->next;
					}while(cn->next!=a[i]);

					nn->next=cn->next;
					cn->next->prev=nn;
					cn->next=nn;
					nn->prev=cn;
				}
			}
		 }
	}

	void bookSeat();
	void deleteBooking();
	void display();
};

void Theater::bookSeat()
{
	int row,seat;
	cout<<"\nEnter which seat you want to book(Row number and Seat number):";
	cin>>row;
	cin>>seat;
	if(row>10 || row<0 || seat>7 || seat<0)
	{
		cout<<"\nInvalid Seat choice!!!";
		return;
	}

	Node *cn;
	cn=a[--row];

	for(int i=1;i<seat;i++)
	{
		cn=cn->next;
	}
    if(cn->status == 1)
    {
        cout << "Already booked!!!" << endl;
    }
    else
    {
        cn->status=1;
        cout<<"\nEnter Name:";
        cin>>cn->name;

        display();
    }
}

void Theater::deleteBooking()
{
	Node *cn;
	int row,seat;
	cout<<"\nEnter row no. and seat no. to delete booking:";
	cin>>row>>seat;
	if(row>10 || row<0 || seat>7 || seat<0)
	{
		cout<<"\nInvalid Seat choice!!!";
		return;
	}

	cn=a[--row];
	for(int i=1;i<seat;i++)
	{
		cn=cn->next;
	}
	if(cn->status==0)
		cout<<"\nSeat is already Empty!!!";
	else
	{
		cn->status=0;
		strcpy(cn->name,"");
		display();
	}
}

void Theater::display()
{
	cout<<"\n================================================================\n";
	Node *cn;
	for(int j=0;j<8;j++)
		cout<<j<<"\t";

	cout<<"\n";
	for(int k=0;k<8;k++)
		cout<<"--------";

	cout<<"\n";
	for(int i=0;i<10;i++)
	{
		cn=a[i];
		int k=i;
		cout<<++k<<"\t";
		for(int j=0;j<7;j++)
		{
			cout<<cn->status<<"\t";
			cn=cn->next;
		}
		cout<<"\n";
	}
	cout<<"\n================================================================\n";
}

int main()
{
	Theater t;
	int ch;
    t.display();
	while(1);
	{
		cout<<"\n==========================\n\tMain Menu";
		cout<<"\n--------------------------";
		cout<<"\n1.Book a seat\n2.Delete Booking\n3.Exit\nEnter Choice:";
		cin>>ch;
		cout<<"\n--------------------------";
		switch(ch)
		{
			case 1: t.bookSeat();
                    break;
			case 2: t.deleteBooking();
                    break;
			case 3: cout<<"\nExiting from Menu...";
                    return 0;
		}
	}
}
