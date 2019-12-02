#include<bits/stdc++.h>
using namespace std;
void max_heapify(int array[],int n,int index)
{
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<n && array[left]>array[largest])
    {
        largest=left;

    }
    if(right<n && array[right]>array[largest])
    {
        largest=right;
    }
    if (largest!=index)
    {
        swap(array[index],array[largest]);
        max_heapify(array,n,largest);
    }
}

void heapsort(int array[],int n)
{
    for(int i=((n-1)/2)-1;i>=0;i--)
    {
        max_heapify(array,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(array[0],array[i]);
        max_heapify(array,i,0);
    }
}
int main()
{
    int n;
    cout<<"Enter Number of Terms in Array:"<<endl;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element"<<i+1<<":";
        cin>>array[i];
    }
    heapsort(array,n);
    cout<<"After Heap Sort:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<"\t";
    }
    return 0;
}