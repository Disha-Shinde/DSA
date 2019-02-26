#include <iostream>
using namespace std;

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
};

void stack :: PUSH(char c)
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

char stack :: POP()
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

int main()
{
	stack s;
	string s1;
	cout << "\nEnter the expression.";
	cin >> s1;
	int i = 0;

	while(s1[i] != '\0')
	{
		if(s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
		{
			s.PUSH(s1[i]);
			i++;
		}
		else
		{
			if(s.EMPTY())
			{
				cout << "\nExpression is not well parenthesized";
				return 0;
			}
			else
			{
				char c;
				c = s.POP();
				if((c == '(' && s1[i] == ')') || (c == '{' && s1[i] == '}') || (c == '[' && s1[i] == ']'))
					i++;
				else
				{
					cout << "\nExpression is not well parenthesized";
					return 0;
				}
			}
		}
	}//end of while

	if(s.EMPTY())
		cout << "\nExpression is valid";
	else
		cout << "\nExpression is not valid";
	return 0;
}
