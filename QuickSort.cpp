#include<iostream>
using namespace std;
#define SIZE 20
class Quick
{
    float arr[SIZE];
public:
    int get_data();
    void quicksort(int, int );
    int partition(int, int );
    void swap(int, int );
    void display(int );
};

int Quick :: get_data()
{
    int i,n;
    cout << "Enter total number of elements : ";
    cin >> n;
    cout << "Enter the percentage marks of each student : ";
    for(i=0;i<n;i++)
        cin >> arr[i];
    return n;
}

void Quick :: quicksort( int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(low, high+1 );
        quicksort(low, j-1 );
        quicksort(j+1, high );

    }
}
//Function for partitioning array
int Quick :: partition(int low, int high )
{
    int i = low, j = high;
    float pivot = arr[low];

    do
    {
        do
        {
            i++;
        }while(arr[i] < pivot);

        do
        {
            j--;
        }while(arr[j] > pivot);

        if(i < j)
            swap(i,j);

    }while(i<j);

    swap(low,j);
    return j;
}

void Quick :: swap(int i, int j)
{
    float temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

 void Quick :: display(int n)
{
    cout << "The sorted array is : " << endl;
    for(int i=0;i<n;i++)
        cout << "  " << arr[i];
    cout<<"\n \t Percentage marks of top five students...\n";
    for(int i=n-1;i>=n-5;i--)
    cout << "  " << arr[i];
}

int main()
{
    Quick q;
    int n;
    cout << "\nQuick sort Method \n";
    n = q.get_data();
    q.quicksort(0, n-1 );
    q.display(n);
    return 0;
}

