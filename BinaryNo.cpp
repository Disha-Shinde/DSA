#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
class BinaryNumber
{
    node *header;
    node *hn2;
    int count;
    int store[20];
public:
    BinaryNumber()
    {
        header = NULL;
        hn2=NULL;
        count = 0;

    }
    void createnode();
    void create(int m)
    {
    	node *nn;
    	nn=new node;
    	nn->data=m;
    	nn->next=NULL;
    	nn->prev=NULL;
    	if(hn2==NULL)
    	{
    		hn2=nn;
    	}
    	else
    	{
    		node *cn;
    		cn = hn2;
    		while(cn->next != NULL)
    		{
    			cn = cn->next;
    		}
    		cn->next = nn;
    		nn->prev = cn;

    	}
    }
    void displaynode();
    void onescomp();
    void twoscomp();
    void sumofbinary();

};

void BinaryNumber::createnode()
{

    node *nn;
    nn = new node;
    cin >> nn->data;
    nn->next = NULL;
    nn->prev = NULL;
    if(header == NULL)
    {
        header = nn;
    }
    else
    {
        node *cn;
        cn = header;
        while(cn->next != NULL)
        {
            cn = cn->next;
        }
        cn->next = nn;
        nn->prev = cn;
    }

}
void BinaryNumber::displaynode()
{

    node *cn;
    cn = header;
    while(cn != NULL)
    {
        cout << cn->data;
        cn = cn->next;
        count++;
    }
    cout << "\n";
}
void BinaryNumber::onescomp()
{
    node *cn;
    cn = header;
    while(cn != NULL)
    {
        if(cn->data == 0)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
        cn = cn->next;
    }
    cout << "\n";

}
void BinaryNumber::twoscomp()
{
	node *cn;
	cn=header;
	while(cn->next!=NULL)
		cn=cn->next;
	while(cn!=NULL)
	{
		if(cn->data==0)
		{
			create(0);
			cn=cn->prev;
		}
		else if (cn->data==1)
		{
			create(1);
			break;
		}
	}
	cn=cn->prev;
	while(cn!=NULL)
		{
			if(cn->data==0)
			{
				create(1);

			}
			else if (cn->data==1)
			{
				create(0);

			}
			cn=cn->prev;
		}

	cn=hn2;
	while(cn->next!=NULL)
		cn=cn->next;
	while(cn!=NULL)
	{
		cout << cn->data;
		cn=cn->prev;
	}



}
void BinaryNumber :: sumofbinary()
{
    node *hn1 , *hn2;
    hn1 = NULL;
    hn2 = NULL;
    int n;
    cout << "size of binary number 1 ?\n";
    cin >> n;
    cout << "enter binary number\n";
    for(int i = 0;i<n;i++)
    {
        node *nn;
        nn = new node;
        cin >> nn->data;
        nn->next = NULL;
        nn->prev = NULL;
        if(hn1 == NULL)
        {
            hn1 = nn;
        }
        else
        {
            node *cn;
            cn = hn1;
            while(cn->next != NULL)
            {
                cn = cn->next;
            }
            cn->next = nn;
            nn->prev = cn;
        }
    }
    cout<<"enter second number\n";
    for(int i=0;i<n;i++)
    {
        node *nn;
        nn = new node;
        cin >> nn->data;
        nn->next = NULL;
        nn->prev = NULL;
        if(hn2 == NULL)
        {
            hn2 = nn;
        }
        else
        {
            node *cn;
            cn = hn2;
            while(cn->next!=NULL)
            {
                cn = cn->next;
            }
            cn->next = nn;
            nn->prev = cn;
        }

    }
    node *cn1,*cn2;
    cn1 = hn1;
    cn2 = hn2;
    while(cn1->next != NULL)
    {
        cn1 = cn1->next;
        cn2 = cn2->next;
    }

    int carry = 0;
    for(int i=0;i<n;i++)
    {
        if(cn1->data == cn2->data)
        {
            if(cn1->data == 1 && carry == 0)
            {
                store[i] = 0;
                carry = 1;

            }
            else if(cn1->data == 1 && carry == 1)
            {
                store[i] = 1;
                carry = 1;
            }
            else if(cn1->data == 0 && carry == 0)
            {
                store[i] = 0;
                carry = 0;
            }
            else if(cn1->data == 0 && carry == 1)
            {
                store[i] = 1;
                carry = 0;
            }

        }
        else
        {
            if(carry == 0)
            {
                store[i] = 1;
                carry = 0;
            }
            else
            {
                store[i] = 0;
                carry = 1;
            }
        }
        cn1 = cn1->prev;
        cn2 = cn2->prev;

    }
    cout << carry;
    for(int i = n;i>0;i--)
    {
        cout << store[i-1];

    }
    cout << "\n";

}
int main()
{
    BinaryNumber n1;
    int n,ch;
    while(1)
    {
        cout << "1.INPUT A N-BIT BINARY NUMBER\n2.DISPLAY NUMBER\n3.ONE's COMPLEMENT\n4.TWO's COMPLEMENT\n5.SUM\n6.EXIT";
        cout << "\nEnter choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1 :
                cout << "enter size of binary number : ";
                cin >> n;
                cout << "enter binary number : ";
                for(int i = 0;i<n;i++)
                {
                    n1.createnode();
                }
                break;
            case 2 :
                n1.displaynode();
                break;
            case 3 :
                n1.onescomp();
                break;
            case 4 :
                n1.twoscomp();
                break;
            case 5 :
                n1.sumofbinary();
                break;
            case 6 :
                cout << "terminated\n";
                return 0;
                break;
        }
    }

}
