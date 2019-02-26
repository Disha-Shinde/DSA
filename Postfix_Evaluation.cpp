#include <iostream>
using namespace std;

struct st_node{
	char data;
	st_node *next;
};

class stack{
	st_node *top;
public:
	stack()
{
		top = NULL;
}
	void push(char);
	char pop();

};

void stack :: push(char c)
{
	st_node *nn;
	nn = new st_node;
	nn -> data = c;

	if(top == NULL)
	{
		top = nn;
		nn -> next = top;
	}
	else
	{
		nn -> next = top;
		top = nn;
	}
}

char stack :: pop()
{
	char c;
	c = top -> data;
	top = top -> next;
	return c;
}
int cal(int a, char opr, int b)
{
	if(opr == '+')
	{
		return a+b;
	}
	else
		if(opr == '-')
	{
		return a-b;
	}
	else
		if(opr == '*')
		{
			return a*b;
		}
		else
			if(opr == '/')
			{
				return a/b;
			}
	return 0;
}


int main() {

	stack S;
		string str;
		cout<<"\n ENTER THE VALID POST FIX EXPRESSION";
		cin>>str;
		int i=0;
		while(str[i]!='\0')
		{
			int op1,op2,res;
			if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				op1 = S.pop();
				op2 = S.pop();
				res = cal(op1,str[i],op2);
				S.push(res);
			}
			else
			{
				int a=str[i]-'0';
				S.push(a);
			}
			i++;



		}
		int ans;
		ans = S.pop();
		cout<<"FINAL ANS IS :"<<ans;
		return 0;
}
