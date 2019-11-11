#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

bool canbecoloured(int graph[][100],int color[],int c,int vertex,int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[vertex][i] && c==color[i])
        {
            return false;
        }
    }
    return true;
}
bool m_colouring(int graph[][100],int vertex,int n,int m,int color[])
{
    if (vertex==n)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if (canbecoloured(graph,color,c,vertex,n))
        {
            color[vertex]=c;
            if (m_colouring(graph,vertex+1,n,m,color))
            {
                return true;
            }
            color[vertex]=0;
        }

    }
    return false;
}
void printSolution(int n,int color[])
{
    cout<<"Vertex are printed in assigned Colors:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\e[0;"<<color[i]+34<<"m"<<char('A'+i)<<"\t";

    }
}
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
                cout << "Dist "
                     << "\t";
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

int main()
{
    int n;

    cout << "Enter number of vertices in the graph:" << endl;
    cin >> n;
    int graph[100][100];
    int m=3;
    int color[m];
    cout << "Enter 1 if there is an edge between the pair of vertices else enter 0:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Is there an edge between " << char('A' + i) << " to " << char('A' + j)<<"?" << endl;
            cin >> graph[i][j];
        }
    }

    cout << "The data showing shortest paths connecting source and rest of the vertices:" << endl;
    printDistance(graph, n);
    if(m_colouring(graph,0, n,m,color)==false)
        cout<<"Solution doesn't exist";
    else
    {
        printSolution(n,color);
    }
    
}
