#include <iostream>
using namespace std;
#define N 10

int BinarySearch(int a[N], int x, int low, int high)
{
	int mid;
	if(low > high)
		return (-1);
	mid = (low + high) / 2;
	if(x == a[mid])
		return mid;
	else if(x < a[mid])
		BinarySearch(a, x, low, mid-1);
	else
		BinarySearch(a, x, mid+1, high);
}

int Fib(int n)
{
    int a, b, f;
    if(n<1)
        return n;
    a=0;
    b=1;
    while(b<n)
    {
        f=a+b;
        a=b;
        b=f;
    }
    return a;
}

void FibSearch(int A[N], int n, int key, int f, int b, int a)
{
    if(f<1||f>n)
        cout<<"\n The student has not attended the training program. ";
    else if(key < A[f])
    {
        if(a<=0)
            cout<<"\n The student has not attended the training program. ";
        else
            FibSearch(A ,n ,key ,f-a ,a ,b-a );
    }
    else if(key > A[f])
    {
        if(b<=1)
            cout<<"\n The student has not attended the training program. ";
        else
            FibSearch(A ,n ,key ,f+a ,b-a ,a-b );
    }
    else
        cout<<"\n The student has attended the training program. ";
}

int main()
{
	int x, loc, ch;
	int a[N] = {10, 22, 31, 32, 33, 39, 46, 47, 48, 64};
	int nmax = N;
	cout << "The roll no. of students are : \n";
	for(int i=0;i<N;i++)
		cout << " " << a[i];
	while(1)
	{
		cout << "\n\n\nMain menu \n1.Binary search \n2.Fibonacci Search\n3.Exit\nEnter your choice : ";
		cin >> ch;
		switch(ch)
		{
            case 1: cout << "\nEnter the roll number to be searched : ";
                    cin >> x;
                    loc = BinarySearch(a ,x ,0 ,N-1 );
                    if(loc == -1)
                        cout << "\n The student has not attended the training program. ";
                    else
                        cout << "\n The student has attended the training program";
                    break;
            case 2: cout << "\nEnter the roll number to be searched : ";
                    cin >> x;
                    FibSearch(a ,nmax-1 ,x ,nmax-1 ,Fib(nmax-1) ,Fib( Fib(nmax-1) ) );
                    break;
            case 3: return 0;
		}
	}
}
