#include<iostream>
using namespace std;
int n;
class student
{
private:
	int rollno,B,C;
	string name;
public:
	void getdata();
	void display();
	void count_cricket(student*);
	void count_Badminton(student*);
	void count_bothgames(student*);
	void count_eithergame(student*);
	void count_neither(student*);

};
void student :: count_neither(student*s)
{
	int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i].C==0 && s[i].B==0)
	          cnt++;
		}
		            cout<<"\n\n Number of students who plays neither Cricket and Badminton: "<<cnt;
		            cout<<"\n\n Name\t|\tRollno"<<endl;
		 for(int i=0;i<n;i++)
		 {
			 if(s[i].C==0&&s[i].B==0)


		cout<<"\n"<<s[i].name<<"\t|\t"<<s[i].rollno;

		}
		 cout<<"\n\n-------------------------------"<<endl;
}
void student :: count_eithergame(student*s)
{
	int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i].C==1||s[i].B==1)
				cnt++;
		}
			 cout<<"\n\n Number of students who play Cricket or Badminton: "<<cnt;
			 cout<<"\n\n Name\t|\tRollno";
			 for(int i=0;i<n;i++)
			 		{
			 			if(s[i].C==1||s[i].B==1)
			 				cout<<"\n"<<s[i].name<<"\t|\t"<<s[i].rollno;

		}
			 cout<<"\n\n-------------------------------"<<endl;

}
void student :: count_bothgames(student*s)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i].C==1&&s[i].B==1)
          cnt++;
	}
	            cout<<"\n\n Number of students who plays Cricket and Badminton: "<<cnt;
	            cout<<"\n\n Name\t|\tRollno"<<endl;
	 for(int i=0;i<n;i++)
	 {
		 if(s[i].C==1&&s[i].B==1)


	cout<<s[i].name<<"\t|\t"<<s[i].rollno;

	}
	 cout<<"\n\n-------------------------------"<<endl;
}
void student :: count_Badminton(student *s)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i].B==1)
			cnt++;
	}
	cout<<"\n\nNo of Students playing Badminton are: "<<cnt;
	cout<<"\n\n Name\t|\tRollno"<<endl;
	for(int i=0;i<n;i++)
	{
		if(s[i].B==1)
			cout<<s[i].name<<"\t|\t"<<s[i].rollno<<endl;
	}
	cout<<"\n\n-------------------------------"<<endl;
}
void student :: count_cricket(student*s)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i].C==1)
			cnt++;
	}
	cout<<"\n\nNo of Students playing cricket are:"<<cnt;
	cout<<"\n\n Name\t|\tRollno"<<endl;
	for(int i=0;i<n;i++)
		{
			if(s[i].C==1)
				cout<<s[i].name<<"\t|\t"<<s[i].rollno<<endl;
		}
	cout<<"\n\n-------------------------------"<<endl;
}
void student :: getdata()
{
	cout<<"Enter the Roll no"<<endl;
	cin>>rollno;
	cout<<"Enter the name "<<endl;
	cin>>name;
	cout<<"If student plays Cricket press 1 else 0"<<endl;
	cin>>C;
	cout<<"If student plays Badminton press 1 else 0"<<endl;
	cin>>B;
	cout<<"\n\n-------------------------------"<<endl;
}
void student :: display()
{
	cout<<"\n\nName:"<<name;
	cout<<"\nRoll no:"<<rollno<<"\n";
	if(C==1)
        cout<<"\nStudent plays Cricket";
    if(B==1)
        cout<<"\nStudent plays Badminton";
	cout<<"\n\n-------------------------------"<<endl;
}
int main()
{

	cout<<"Enter no of student"<<endl;
	cin>>n;
	student s[n];
	for(int i=0;i<n;i++)
		s[i].getdata();
	cout<<"    \n\n\n\n\n                     All Details"<<endl;
	for(int j=0;j<n;j++)
	s[j].display();
	s[0].count_cricket(s);
	s[0].count_Badminton(s);
	s[1].count_bothgames(s);
	s[0].count_eithergame(s);
	s[0].count_neither(s);


	cout<<"\n\n\n****....Exit from the Program....*****";
	return 0;

}
