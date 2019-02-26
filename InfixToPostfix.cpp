#include <iostream>
using namespace std;

int priority(char opr)
{
	if(opr == '*' || opr == '/')
		return 2;
	else if(opr == '+' || opr == '-')
		return 1;
    else
        return 0;
}

struct stk_node
{
	char data;
	stk_node *next;
};

class stack
{
	stk_node *top;
public:
	stack()
	{
		top = NULL;
	}
	void PUSH(char );
	char POP();
	int EMPTY();
    void parenthesis(char );
};

void stack ::PUSH(char c)
{
	stk_node *nn;
	nn = new stk_node;
	nn->data = c;
	if(top == NULL)
	{
		nn->next = NULL;
		top = nn;
	}
	else
	{
		nn->next = top;
		top = nn;
	}
}

char stack ::POP()
{
	char c;
	c = top->data;
	top = top->next;
	return c;
}

int stack ::EMPTY()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

void stack :: parenthesis(char c)
{
    stk_node *cn;
    cn = top;
    if(c == ')')
    {
        while(cn->next != NULL && cn->data != '(')
        {
            cout << POP();
            cn = cn->next;
        }
    }
    else if(c == ']')
    {
        while(cn->next != NULL && cn->data != '[')
        {
            cout << POP();
            cn = cn->next;
        }
    }
    else
    {
        while(cn->next != NULL && cn->data != '{')
        {
            cout << POP();
            cn = cn->next;
        }
    }
    POP();
}

int main()
{
	stack s;
	string s1;
	cout << "\nEnter the  Infix expression.";
	cin >> s1;
	int i=0;

	while(s1[i] != '\0')
	{
		if(s1[i] == '*' || s1[i] == '/' || s1[i] == '+' || s1[i] == '-')
		{
			if(!s.EMPTY())
			{
				char opr;
				opr = s.POP();
				if(priority(s1[i]) > priority(opr))
				{
					s.PUSH(opr);
					s.PUSH(s1[i]);
					i++;
				}
				else
				{
					while(priority(s1[i]) <= priority(opr))
					{
						cout << opr;
						if(!s.EMPTY())
							opr = s.POP();
						else
							break;
					}
                    if(priority(s1[i]) <= priority(opr))
                    {
                        s.PUSH(s1[i]);
                        i++;
                    }
				}
			}
			else
			{
				s.PUSH(s1[i]);
				i++;
			}
		}


		else if(s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
		{
			s.PUSH(s1[i]);
			i++;
		}
        else if(s1[i] == ')' || s1[i] == '}' || s1[i] == ']')
		{
            s.parenthesis(s1[i]);
            i++;
        }
		else
		{
			cout << s1[i];
			i++;
		}
	}
	while(!s.EMPTY())
	{
		char c;
		c = s.POP();
		cout << c;
	}


	return 0;
}
