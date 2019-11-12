#include<bits/stdc++.h>
using namespace std;

bool canbeadded(int graph[][100], int path[], int vertex, int n,int index)
{
    if (graph[path[index - 1]][vertex] == 0)
        return false;
    for (int i = 0; i < index; i++)
    {
        if (path[i] == vertex)
        {
            return false;
        }
    }
    return true;
}
bool hamiltonian(int graph[][100],int path[],int n,int index)
{
    if(index==n)
    {
        if(graph[path[index-1]][path[0]])
        {
;            return true;
        }
        else
        {
            return false;
        }
        
    }
    for (int i=1;i<n;i++)
    {
        if (canbeadded(graph,path,i,n,index)){
            path[index] = i;
            if(hamiltonian(graph,path,n,index+1))
                return true;
            path[index]=-1;
        }
    }
    return false;
}

void printSolution(int n, int path[])
{
    cout << "Vertex are printed in assigned Colors:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << char('A'+path[i])<< "->";
    }
    cout<<'A';
    cout<<endl;
}
/*void hamiltoniancycles(int graph[][100],int path[],int n, int index)
{
    do{
    hamiltonian(graph,path,n,index);
    if (path[index]==-1)
    {
        cout<<"Solution doesn't exist"<<endl;
        return;
    }
    else if(index==n)
        printSolution(n,path);
    else
        hamiltonian(graph,path,n,index+1);
    }while(true);

    
}*/
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
    int path[n];
    path[0]=0;
    for(int i=1;i<n;i++)
    {
        path[i]=-1;
    }
    cout << "Enter 1 if there is an edge between the pair of vertices else enter 0:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Is there an edge between " << char('A' + i) << " to " << char('A' + j) << "?" << endl;
            cin >> graph[i][j];
        }
    }

    cout << "The data showing shortest paths connecting source and rest of the vertices:" << endl;
    printDistance(graph, n);
    //hamiltoniancycles(graph,path,n,1);
    int index=1;
    if(hamiltonian(graph,path,n,1)==false)
        cout<<"Solution doesn't exist";
    else{
        printSolution(n,path);
    }
}
