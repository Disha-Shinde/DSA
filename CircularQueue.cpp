#include <iostream>
using namespace std;
#define size 5

class Pizza
{
    int q[size];
    int F, R;
public:
    Pizza()
    {
        F = -1;
        R = -1;
    }
    void Accept(int );
    void Deliver();
    int Qfull();
    int Qempty();
    void Display();
};

int Pizza :: Qfull()
{
    if((R+1) % size == F)
        return 1;
    else
        return 0;
}

int Pizza ::Qempty()
{
    if(F == -1)
       return 1;
    else
        return 0;
}

void Pizza :: Accept(int order)
{
	if(F == -1 && R == -1)
		F = R = 0;
	else
    	R = (R+1) % size;
	q[R] = order;
}

void Pizza ::Deliver()
{
    int order;
    order = q[F];
    if(F == R)
    	F = R = -1;
    else
        F = (F+1) % size;
    cout << "Order no. " << order << " is delivered." << endl;
}

void Pizza:: Display()
{
    int i = F;
    while(i!=R)
    {
        cout<<" "<<q[i];
        i=(i+1)%size;
    }
    cout<<" "<<q[i];
}

int main()
{
    int ch;
    Pizza obj;

    cout << "\n\n**********WELCOME TO PIZZA HUT**********\n";
    while(1)
    {
        cout << "\n\n===========================================";
        cout << "\n1.ACCEPT Order \n2.DELIVER Order \n3.DISPLAY order list \n4.Exit \nEnter choice : ";
        cin >> ch;
        cout << "===========================================\n\n";
        switch(ch)
        {
            case 1: if(obj.Qfull())
            			cout << "Sorry!!!! Order cannot be placed. " << endl;
            		else
            		{
            			int order;
            			cout << "Enter the order no. to be placed : ";
            	        cin >> order;
            	        obj.Accept(order);
            		}
                    break;
            case 2: if(obj.Qempty())
            			cout << "Order is already placed. " << endl;
            		else
            			obj.Deliver();
                    break;
            case 3: obj.Display();
                    break;
            case 4: return 0;
        }
    }

}
