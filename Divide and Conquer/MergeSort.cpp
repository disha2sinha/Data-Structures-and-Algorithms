#include<bits/stdc++.h>
using namespace std;
void merge(int array[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,temp[30];
    while(i<=mid && j<=high)
    {
        if (array[i]<=array[j])
        {
            temp[k++]=array[i++];
        }
        else
        {
            temp[k++]=array[j++];
        }
        
    }
    for(;i<=mid;i++){
        temp[k++]=array[i];
    }
    for (; j <= high; j++)
    {
        temp[k++] = array[j];
    }
    for (int p = low; p <= high; p++)
    {
        array[p] = temp[p];
    }
}
void mergesort(int array[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
int main()
{
    int n, array[25];
    cout << "Enter Number of items in array:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element" << (i + 1) << ":" << endl;
        cin >> array[i];
    }
    cout << "Before Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "\t";
    }
    mergesort(array,0, n - 1);

    cout << "\nAfter Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "\t";
    }
}
