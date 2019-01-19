#include<iostream>
using namespace std;


class dsa
{
	int roll_no,dsa_mks,c,p,f;
	string name;
public:
	void get_data();
	void put_data();
	void max_score(dsa *, int);
	void min_score(dsa *, int);
	void avg_score(dsa *, int);
	void absent(dsa *, int);
	void fail(dsa *, int);
	void max_freq(dsa *, int);
};


void dsa::get_data()
{
	cout<<"Enter roll no. : ";
	cin>>roll_no;
	cout<<"Enter name : ";
	cin>>name;
	cout<<"Enter marks scored in dsa.If absent enter -1 : ";
	cin>>dsa_mks;
}

void dsa::put_data()
{
	cout<<endl<<"Roll no : "<<roll_no<<endl;
	cout<<"Name : "<<name<<endl;
	if(dsa_mks!=-1)
		cout<<"Marks : "<<dsa_mks<<endl;
	else
		cout<<"Not appeared for test."<<endl;
}

void dsa::max_score(dsa *d, int n)
{
	int max=d[0].dsa_mks;
	for(int i=1;i<n;i++)
		if(d[i].dsa_mks>max)
			max=d[i].dsa_mks;
	cout<<"\nMax marks scored : "<<max<<endl;
}

void dsa::min_score(dsa *d, int n)
{
	int min=30;
	for(int i=0;i<n;i++)
		if(d[i].dsa_mks<min && d[i].dsa_mks!=-1)
			min=d[i].dsa_mks;
	cout<<"Min marks scored : "<<min<<endl;
}

void dsa::absent(dsa *d, int n)
{
	c=p=0;
	for(int i=0;i<n;i++)
		if(d[i].dsa_mks==-1)
			c++;
		else
			p++;
	cout<<"No. of absent students : "<<c<<endl;
	cout<<"No. of students appeared : "<<p<<endl;
}

void dsa::avg_score(dsa *d, int n)
{
	int sum=0,avg;
	for(int i=0;i<n;i++)
		if(d[i].dsa_mks!=-1)
			sum=sum+d[i].dsa_mks;
	avg=sum/(n-c);
	cout<<"Average marks scored : "<<avg<<endl;
}

void dsa::fail(dsa *d, int n)
{
	f=0;
	for(int i=0;i<n;i++)
		if(d[i].dsa_mks<15)
			f++;
	cout<<"No. of students failed : "<<f<<endl;
}

void dsa::max_freq(dsa *d, int n)
{
	int temp[n],freq,mfreq=1,index;
	for(int i=0;i<n;i++)
		temp[i]=d[i].dsa_mks;
	for(int i=0;i<n;i++)
	{
		if(temp[i]==99 || temp[i] == -1)
			continue;
		freq=1;
		for(int j=i+1;j<n;j++)
		{
			if(temp[i]==temp[j])
			{
		 		temp[j]=99;
		 		freq++;
			}
		}//for loop j
		if(freq>=mfreq)
		{
			mfreq=freq;
			index=i;
		}
	}//for loop i
	cout<<"\n\nMax frequency : "<<mfreq<<endl;
	cout<<"Max freq is of marks : "<<d[index].dsa_mks<<endl;
}


int main()
{
	int n;
	cout<<"Enter total no. of students : ";
	cin>>n;
	dsa d[n];
	for(int i=0;i<n;i++)
		d[i].get_data();
	cout<<endl<<"****Student Data****"<<endl;
	for(int i=0;i<n;i++)
		d[i].put_data();
	cout<<"----------------------\n\n";
	d[0].absent(d,n);
	d[0].fail(d,n);
	d[0].max_score(d,n);
	d[0].min_score(d,n);
	d[0].avg_score(d,n);
	d[0].max_freq(d,n);
	return 0;
}
