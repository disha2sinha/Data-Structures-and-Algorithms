#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int low,int high,int array[])
{
    int i=low;
    int j=high;
    int pivot=low;
    while(i<j)
    {
        do{
            i++;
        }while(array[i]<=array[pivot]);
        while (array[j] >array[pivot])
        {
            j--;
        }
        if(i<j)
        {
            swap(&array[i],&array[j]);
        }

    }
    swap(&array[low],&array[j]);
    return j;
}
void quicksort(int low,int high ,int array[] )
{
    if(low<high)
    {
        int j=partition(low,high,array);
        quicksort(low,j,array);
        quicksort(j+1,high,array);
    }
}
int main()
{
    int n,array[25];
    cout<<"Enter Number of items in array:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element"<<(i+1)<<":"<<endl;
        cin>>array[i];
    }
    cout << "Before Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "\t";
    }
    quicksort(0,n-1,array);

    cout<<"\nAfter Sorting:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<"\t";
    }
}