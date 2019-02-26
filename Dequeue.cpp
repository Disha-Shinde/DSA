#include <iostream>
using namespace std;
class deque
{
	int a[5];
	int front,rear;
public:
	deque()
{
		front=-1;
		rear=-1;
}
	void add_beg(int z);
	void add_end(int z);
	void del_beg();
	void del_end();
	void display();
};

void deque::add_beg(int z)
{
	if(rear>=4)
	{
		cout<<"que full";
	}
	else if(front==-1)
	{
		front++;
		rear++;
		a[front]=z;
	}
	else
	{
		int i=rear;
		while(i>=front)
		{
			a[i+1]=a[i];
			i--;
		}
		a[front]=z;
		rear++;
	}

}

void deque::add_end(int z)
{
	if(rear>=4)
	{
		cout<<"que full";
	}
	else
	{
	rear++;
	a[rear]=z;
	}

}



void deque::del_beg()
{
	if(front==-1)
	{
		cout<<"empty";
	}
else
{
	cout<<"deleted element is "<<a[front];
	if(front==rear)
	{
		front=rear-1;
		return;
	}
	else
	{
		front++;
	}

}
}

void deque::del_end()
{
		if(front==-1)
		{
			cout<<"empty";
		}
		else
		{
			cout<<"deleted elemnt is "<<a[rear];
			if(front==rear)
			{
				front=rear-1;
			}
			else
			{
				rear--;
			}
		}
}

void deque::display()
{
	if(front==-1)
	{
		cout<<"deque empty";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<a[i]<<"\t";
		}
	}

}

int main()
{
	deque x;
	int z;
	int choice;
	cout<<"**DEQUE**\n";
	cout<<"**menu**\n";
    while(1)
    {
        cout<<"\n\n1.Add at beg\n2.Add at end\n3.Delete at beg\n4.Delete at end\n5.Display\n6.Exit";
        cout<<"\nEnter choice : ";
        cin>>choice;
        switch(choice)
        {

            case 1:
                cout<<"enter item to be added at beg";
                cin>>z;
                x.add_beg(z);
                break;
            case 2:
                cout<<"\nenter item to be added at end";
                cin>>z;
                x.add_end(z);
                break;
            case 3:
                x.del_beg();
                break;
            case 4:
                x.del_end();
                break;
            case 5:
                x.display();
                break;
            case 6:
                return 0;
        }
	}

}
