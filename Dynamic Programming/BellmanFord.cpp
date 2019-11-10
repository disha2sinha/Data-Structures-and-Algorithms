#include<bits/stdc++.h>
using namespace std;
void printSolution(int dist[], int n)
{
    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << 'A' << "->" << char('A' + i) << "\t\t" << dist[i] << endl;
    }
}
void Bellmanford(int graph[][100],int n,int e,int source)
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        if (i != source)
        {
            dist[i] = 9999;
        }
        else
        {
            dist[i] = 0;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if (graph[j][k]!=0 && dist[k]>dist[j]+graph[j][k])
                {
                    dist[k]=dist[j]+graph[j][k];
                }
            }
        }
    }
    printSolution(dist,n);
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (graph[j][k] != 0 && dist[k] > dist[j] + graph[j][k])
            {
                cout<<"The graph has negative weight cycle\n";
            }
        }
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
    int edge=0;
    cout << "Enter weights of the paths connecting each vertex(Enter 9999 for the pair of vertices with no path):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter weight of path between " << char('A' + i) << " to " << char('A' + j) << endl;
            cin >> graph[i][j];
            if (graph[i][j]!=0)
            edge++;
        }
    }
    
    cout << "The data showing shortest paths connecting source and rest of the vertices:" << endl;
    printDistance(graph, n);
    Bellmanford(graph, n,edge, 0);
}
