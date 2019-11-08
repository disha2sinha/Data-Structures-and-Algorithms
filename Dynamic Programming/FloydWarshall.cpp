#include<bits/stdc++.h>
#include<string>
using namespace std;
int pred[100][100];
void printDistance(int matrix[][100], int n)
{
    char vertice1 = 'A';
    char vertice2 = 'A';
    for (int i = -1; i < n; i++)
    {
        for (int j = -1; j < n; j++)
        {
            if (i == -1 && j == -1)
            {
                cout << "Dist "<<"\t";
            }
            else if (i == -1 && j != -1)
            {
                cout << vertice1++ << "\t";
            }
            else if (j == -1 && i != -1)
            {
                cout << vertice2++ << "\t";
            }
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void path(int i, int j,int pred[][100])
{
    char vertice='A';
    if (pred[i][j]==-999)
    {
        cout<<char(vertice+i)<<"->"<<char(vertice+j)<<endl;
        return;
    }
    path(i,pred[i][j],pred);
    path(pred[i][j],j,pred);
    
}
void floydwarshall(int n,int weight[][100])
{
    int dist[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j]=weight[i][j];
            pred[i][j]=-999;
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pred[i][j]=k;
                }
            }
        }
    }
    cout<<"The matrix shows the shortest distance between each of the vertices:"<<endl;
    printDistance(dist,n);
    cout<<"The Shortest path:"<<endl;
    path(0,n-1,pred);
}

int main()
{
    int n;
    
    cout<<"Enter number of vertices in the graph:"<<endl;
    cin>>n;
    int weight[100][100];
    cout<<"Enter initial weights of the paths connecting each vertex(Enter 9999 for the pair of vertices with no path):"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter distance:"<<endl;
            cin>>weight[i][j];
        }
    }
    cout<<"The initial distances between vertices:"<<endl;
    printDistance(weight,n);
    floydwarshall(n,weight);
}