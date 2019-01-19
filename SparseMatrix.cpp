#include<iostream>
using namespace std;

int main()
{
	int r,c,index=1,val,cnt=0;
	cout<<"Enter the no. of rows and columns : ";
	cin>>r>>c;
	int s[5][3];
	s[0][0]=r;
	s[0][1]=c;
	cout<<"Enter the data : "<<endl;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cout<<"\nEnter element present at "<<i<<" "<<j<<" : ";
			cin>>val;
			if(val!=0)
			{
				s[index][0]=i;
				s[index][1]=j;
				s[index][2]=val;
				index++;
				cnt++;
			}
		}
	s[0][2]=cnt;


    int k=1;
    cout<<"\n\n      ***ORIGINAL MATRIX 1***\n";
	for(int i=0;i<s[0][0];i++)
    {
        for(int j=0;j<s[0][1];j++)
        {
            if(s[k][0]==i && s[k][1]==j)
            {
                cout << " \t" << s[k][2];
                k++;
            }
            else
                cout << "\t0";
        }
        cout << endl;
    }

    cout<<"\n\n      ***SPARSE FORM***"<<endl;
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<3;j++)
            cout<<"\t"<<s[i][j];
        cout<<"\n";
    }

    //*******TRANSPOSE*******


	int ind = 1, t[k][3];

	t[0][0]=s[0][1];
	t[0][1]=s[0][0];
	t[0][2]=s[0][2];

	for(int i=0;i<r;i++)
	{
		for(int j=1;j<k;j++)
		{
			if(i == s[j][1])
			{
				t[ind][0] = s[j][1];
				t[ind][1] = s[j][0];
				t[ind][2] = s[j][2];
				ind++;
			}

		}

	}


	cout<<"\n\n      ***TRANSPOSE***"<<endl;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<3;j++)
            cout<<"\t"<<t[i][j];
        cout<<"\n";
    }


    //**********FAST TRANSPOSE**********

	int ftrans[k][3];
	ftrans[0][0] = c;
	ftrans[0][1] = r;
	ftrans[0][2] = cnt;
	int term[c],rowp[c];
	for(int i=0;i<c;i++)
		term[i] = 0;
	for(int i=1;i<=cnt;i++)
	{
		term[s[i][1]]++;
	}
	rowp[0] = 1;
	for(int i=1;i<c;i++)
	{
		rowp[i] = rowp[i-1] + term[i-1];
	}
	for(int i=1;i<=cnt;i++)
	{
		int p;
		p = rowp[s[i][1]];
		ftrans[p][0] = s[i][1];
		ftrans[p][1] = s[i][0];
		ftrans[p][2] = s[i][2];
		rowp[s[i][1]]++;

	}

	cout << "\n\n      ***FAST TRANSPOSE***\n\n";
	for(int i=0;i<k;i++)
	{
			for(int j=0;j<3;j++)
			{
				cout<<"\t"<<ftrans[i][j];
			}
			cout<<endl;
	}



    //*******ADDITION*******

        int index1=1;
		cnt=0;
		cout<<"Enter the no. of rows and columns : ";
		cin>>r>>c;


		int s1[5][3];
		s1[0][0]=r;
		s1[0][1]=c;
		cout<<"Enter the data : "<<endl;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				cout<<"\nEnter element present at "<<i<<" "<<j<<" : ";
				cin>>val;
				if(val!=0)
				{
					s1[index1][0]=i;
					s1[index1][1]=j;
					s1[index1][2]=val;
					index1++;
					cnt++;
				}
			}
		s1[0][2]=cnt;


		cout<<"\n\n      ***SPARSE FORM 1***"<<endl;
			for(int i=0;i<index;i++)
			{
				for(int j=0;j<3;j++)
					cout<<"\t"<<s[i][j];
				cout<<"\n";
			}

		cout<<"\n\n      ***SPARSE FORM 2***"<<endl;
		for(int i=0;i<index1;i++)
		{
			for(int j=0;j<3;j++)
				cout<<"\t"<<s1[i][j];
			cout<<"\n";
		}

	cout<<"------------------------------------"<<endl;
	int s3[20][3];

	if(s[0][0] == s1[0][0] && s[0][1] == s1[0][1])
	{
		s3[0][0] = s[0][0];
		s3[0][1] = s[0][1];
		int p=1;
		int q=1;
		int r=1;
		while(p<=s[0][2] && q<=s1[0][2])
		{
		if(s[p][0] == s1[q][0])//row checking
		{
			if(s[p][1] == s1[p][1])//column checking
			{
				s3[r][0] = s[p][0] ;
				s3[r][1] = s[p][1] ;
				s3[r][2] = s[p][2] + s1[q][2] ;
				p++;q++;r++;
			}
			else if(s[p][1] <s1[q][1])//column checking
			{
				s3[r][0] = s[p][0];
				s3[r][1] = s[p][1];
				s3[r][2] = s[p][2];
				r++;p++;
			}
			else					//column checking
			{
				s3[r][0] = s1[q][0];
				s3[r][1] = s1[q][1];
				s3[r][2] = s1[q][2];
				r++;q++;
			}
		}
		else if(s[p][0] > s1[q][0])//row checking
		{
			s3[r][0] = s1[q][0];
			s3[r][1] = s1[q][1];
			s3[r][2] = s1[q][2];
			r++;q++;
		}
		else					//row checking
	    {
			s3[r][0] = s[p][0];
			s3[r][1] = s[p][1];
			s3[r][2] = s[p][2];
			r++;p++;
		}
		}

		while(p <= s[0][2])//number of rows greater
		{
			s3[r][0] = s[p][0];
			s3[r][1] = s[p][1];
			s3[r][2] = s[p][2];
			r++;p++;
		}
		while(q <= s1[0][2])//number of columns greater
				{
					s3[r][0] = s1[q][0];
					s3[r][1] = s1[q][1];
					s3[r][2] = s1[q][2];
					r++;q++;
				}

		s3[0][2] = r-1;
		cout<<"\n\n      ***ADDITION IS***"<<endl;
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<3;j++)
					cout<<"\t"<<s3[i][j];
				cout<<"\n\n\n";
			}

	}

	else
		cout<<"No addition is possible"<<endl;



	cout<<"EXIT FROM PROGRAM"<<endl;


	return 0;

}
