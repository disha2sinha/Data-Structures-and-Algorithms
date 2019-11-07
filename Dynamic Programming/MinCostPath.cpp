#include <bits/stdc++.h>
using namespace std;
int cost[100][100];
int MinCostPath(int cost[][100],int m,int n)
{
    int table[m+1][n+1];
    table[0][0]=cost[0][0];
    for (int i=1;i<=m;i++)
    {
        table[i][0]=table[i-1][0]+cost[i][0];
    }
    for (int j=1;j<=n;j++)
    {
        table[0][j]=table[0][j-1]+cost[0][j];
    }
    cout<<"Memoization Table:"<<endl;
    for (int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            table[i][j]=min(min(table[i][j-1],table[i-1][j]),table[i-1][j-1])+cost[i][j];
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }
    return table[m][n];
}
int main()
{
    int r,c;
    cout<<"Enter number of rows:"<<endl;
    cin>>r;
    cout << "Enter number of columns:" << endl;

    cin>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"Enter element: "<<endl;
            cin>>cost[i][j];
        }
    }
    cout<<"The cost matrix looks like"<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<< cost[i][j]<<"\t";
        }
        cout<<endl;
    }
    int m,n;
    cout<<"Enter position of the matrix whose min cost path is to be computed:"<<endl;
    cin>>m>>n;
    int total=MinCostPath(cost,m,n);
    cout<<"Minimum cost to reach ("<<m<<","<<n<<"): "<<total<<endl;

}