#include <iostream>
#include<cstring>
using namespace std;

struct node
{
	char prn[5];
	string name;
	node *next;

};

class club
{
	node *header;
public:
	club()
	{
		header = NULL;
	}
	void add_beg();
	void add_position();
	void add_end();
	void remove();
	void display();

};

void club :: add_beg()
{
	node *nn;
	nn = new node;
	cout << "Enter prn no. of member	: ";
	cin >> nn->prn;
	cout << "Enter name of member	: ";
	cin >> nn->name;
	nn->next = header;
	header = nn;
}

void club :: add_position()
{
	int n;
	node *nn;
	nn = new node;
	cout << "Enter position : ";
	cin >> n;
	cout << "Enter prn no. of member	: ";
	cin >> nn->prn;
	cout << "Enter name of member	: ";
	cin >> nn->name;
	node *temp;
	temp = header;


	for( int i=1;i<n-1;i++)
	{
		temp = temp -> next;
	}
	nn ->next = temp -> next;
	temp -> next =  nn;

}

void club :: add_end()
{
	node *nn;
	nn = new node;
	cout << "Enter prn no. of member	: ";
	cin >> nn->prn;
	cout << "Enter name of member	: ";
	cin >> nn->name;
	nn->next = NULL;
	if(header == NULL)
	{
		header = nn;
	}
	else
	{
		node *cn;
		cn = header;
		while(cn->next != NULL)
				cn = cn->next;
		cn->next = nn;
	}


}


void club :: remove()
{
	node *temp, *prev;
	temp = header;
	prev = NULL;
	char tprn[5];
	cout << "Kindly enter the prn no. of member to be removed : ";
	cin >> tprn;
	if(strcmp(header->prn, tprn) == 0)
		header = header->next;
	else
	{
		while(temp != NULL)
		{
			if(strcmp(temp->prn, tprn) == 0)
				break;
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
	}
}

void club :: display()
{
	node *temp;
	temp = header;
	while(temp != NULL)
	{
		cout << "\t" << temp->prn << "  " << temp->name << "\t";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	club c;
	int ch ;
	while(1)
	{
		cout << "\n\n1.Add at beginning \n";
		cout << "2.Add at any particular position \n";
		cout << "3.Add at the end \n";
		cout << "4.Remove a member from PINACCLE CLUB \n";
		cout << "5.Display the link list \n";
		cout << "6.Exit \n";
		cout << "Enter your choice	: ";
		cin >> ch;
		switch(ch)
		{
			case 1 : c.add_beg();
				 	 break;
			case 2 : c.add_position();
				 	 break;
			case 3 : c.add_end();
					 break;
			case 4 : c.remove();
					 break;
			case 5 : c.display();
				 	 break;
			case 6 : return 0;
		}

	}
}
