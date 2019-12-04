#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int knapsack(int profit[],int weight[],int n,int knapsack_size)
{
    int solution[n+1][knapsack_size+1];

    for(int i=0;i<n+1;i++)
    {
        for(int w=0;w<knapsack_size+1;w++)
        {
            if(i==0||w==0)
            {
                solution[i][w]=0;
            }
            else if(w>=weight[i-1])
            {
                solution[i][w]=max(solution[i-1][w],solution[i-1][w-weight[i-1]]+profit[i-1]);
            }
            else
            {
                solution[i][w]=solution[i-1][w];
            }
            
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < knapsack_size + 1; w++)
        {
            cout << solution[i][w] << "\t";
        }
        cout << endl;
    }

    return solution[n][knapsack_size];
}
int main()
{
    int n,knapsack_size;
    cout<<"Enter Number of Items:"<<endl;
    cin>>n;
    cout<<"Enter Knapsack Size:"<<endl;
    cin>>knapsack_size;
    int profit[n],weight[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Details Of Item "<<i+1<<":"<<endl;
        cout<<"Enter Profit:"<<endl;
        cin>>profit[i];
        cout<<"Enter Weight:"<<endl;
        cin>>weight[i];
    }
    int total_profit=knapsack(profit,weight,n,knapsack_size);
    cout<<"Maximum profit:"<<total_profit;
    return 0;
}