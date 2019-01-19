#include <iostream>
using namespace std;


class str_opr
{
	int l1 = 0,l2 = 0;
	char s1[30], s2[30], s3[20];
public:
	void accept();
	void display();
	void len_str();
	void copy_str();
	void cat_str();
	void sub_str();
	void rev_str();

};


void str_opr :: accept()
{
	cout << "Enter string 1	: ";
	cin >> s1;
	cout << "Enter string 2	: ";
	cin >> s2;
	cout << "String 1		: " << s1 << endl;
	cout << "String 2		: " << s2 << endl;
}

void str_opr :: sub_str()
{
	cout << "Enter the sub string to be found	: ";
	cin >> s3;
	int i,j=0,flag=0;
	for(i = 0;s1[i]!='\0';i++)
	{
		if(s1[i] == s3[j])
		{
			j++;
			if(s3[j]=='\0')
			{
				flag=1;
				break;
			}
		}
		else
		{
			j=0;
			if(s1[i] == s3[j])
				i--;
		}


	}
	if(flag == 0)
		cout << "Not found" << endl;
	else
		cout<<"Substring is found" << endl;


}

void str_opr :: len_str()
{
	for(int i=0;s1[i]!='\0';i++)
		l1++;
	for(int i=0;s2[i]!='\0';i++)
		l2++;

	cout << "Length of string 1	: " << l1 << endl;
	cout << "Length of string 2	: " << l2 << endl;
}

void str_opr :: copy_str()
{
	int i;
	for(i=0;s2[i]!='\0';i++)
		s1[i] = s2[i];
	s1[i] = '\0';

	cout << "String copy`	: " << s1 << endl;
}

void str_opr :: cat_str()
{
	for(int i=0;s2[i]!='\0';i++)
	{
		s1[l1] = s2[i];
		l1++;
	}
	s1[l1] = '\0';

	cout << "String concatenation : " << s1 << endl;

}
void str_opr :: rev_str()
{
	char s4[20];
	int l=0;
	cout << "Enter the string to be reversed : ";
	cin >> s4;
	cout << "String reverse : ";
	for(int i=0;s4[i]!='\0';i++)
		l++;
	for( ;l>=1;l--)
		cout << s4[l-1];

}

int main()
{
	str_opr s;
	s.accept();
	s.len_str();

	s.cat_str();
	s.sub_str();
	s.copy_str();
	s.rev_str();

	return 0;
}
