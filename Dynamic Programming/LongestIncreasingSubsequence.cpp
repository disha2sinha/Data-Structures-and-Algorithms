#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSequence(int n,int arr[]){
    int lis[n];
    lis[0]=1;
    for (int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if (arr[i]>arr[j]&& lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    return *max_element(lis,lis+n);
}
int main()
{
   int n;
   cout<<"Enter The No. Of Terms in Array:"<<"\n";
   cin>>n;
   int array[n];
   cout<<"Enter elements"<<"\n";
   for(int i=0;i<n;i++)
   {
       cout<<"Enter"<<i+1<<"th Element:"<<"\n";
       cin>>array[i];
   }
   int length=longestIncreasingSequence(n,array);
   cout<<"Length of the Longest Increasing Subsequence:"<<length;
}