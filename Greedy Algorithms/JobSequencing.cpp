#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
        char JobID[5];
        int profit;
        int deadline;
    public:
        Job(){

        }
};
bool compare(Job a,Job b)
{
    return a.profit>b.profit;
}
bool comparison(Job a ,Job b)
{
    return a.deadline>b.deadline;
}
void Jobsequencing(Job array[],int n)
{
    char result[n];
    sort(array,array+n,compare);
    int slot[n];
    for(int i=0;i<n;i++)
    {
        slot[i]=0;
        for(int j=min(n,array[i].deadline)-1;j>=0;j--)
        {
            if(slot[j]==0){
                result[j]=i;
                slot[j]=j+1;
                break;
            }

        }
        
    }
    cout<<"JOB ID"<<"\t\t"<<"SLOT"<<"\t\t"<<"PROFIT"<<endl;
    for (int i = 0; i <n; i++)
    {
        if (slot[i])
        {
            cout<<array[result[i]].JobID<<"\t\t"<<slot[i]<<"\t\t"<<array[result[i]].profit<<endl;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter Number of Jobs:"<<endl;
    cin>>n;
    Job array[n];
    for (int i=0;i<n;i++)
    {
        cout<<"ENTER DETAILS FOR JOB "<<i+1<<endl;
        cout<<"ENTER JOB ID:"<<endl;
        cin>>array[i].JobID;
        cout<<"ENTER PROFIT:"<<endl;
        cin>>array[i].profit;
        cout<<"ENTER DEADLINE OF JOB:"<<endl;
        cin>>array[i].deadline;

    }
    Jobsequencing(array,n);
    return 0;
}
