#include <bits/stdc++.h>
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
int travellingSalesman(int source,int n, int cost[][100])
{
    int dist[100][100];
    vector<int> remaining;
    for (int i = 0; i < n; i++)
    {
        if (i!=source)
            remaining.push_back(i);
    }
    int minimum=9999;
    int path_cost=0;
    int visited=source;
    while(true){
        for (int k = 0; k < remaining.size(); k++)
        {
            path_cost=path_cost+cost[visited][remaining[k]];
            visited=remaining[k];
        }
        path_cost=path_cost+cost[visited][source];
        minimum=min(minimum,path_cost);
            
        if (!next_permutation(remaining.begin(),remaining.end()))
            break;
        
    }

    return minimum;

}

int main()
{
    int n;

    cout << "Enter number of vertices in the graph:" << endl;
    cin >> n;
    int cost[100][100];
    cout << "Enter costs of the paths connecting each vertex(Enter 9999 for the pair of vertices with no path):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter cost of path between " << char('A' + i) << " to " << char('A' + j) << endl;
            cin >> cost[i][j];
        }
    }
    cout << "The matrix showing costs of paths connecting vertices:" << endl;
    printDistance(cost, n);
    cout<<"Minimum cost:"<<travellingSalesman(1,n,cost);
}