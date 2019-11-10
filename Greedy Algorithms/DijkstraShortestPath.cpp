#include<bits/stdc++.h>
using namespace std;
void showpath(int path[],int i)
{
    if (path[i]==-1)
    return;
    showpath(path,path[i]);
    cout<<char('A'+i);

}
int mindist(int dist[],char traversed[],int n)
{
    int min=9999;
    int min_pos;
    for(int i=0;i<n;i++){
        if (traversed[i] == '\0' && dist[i] <= min)
        {
            min = dist[i];
            min_pos = i;
        }
    }
    return min_pos;
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
                cout << "Dist "<< "\t";
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
void printSolution(int dist[],int n,int path[])
{
    cout<<"Vertex \t\t Distance from Source\t\tPath"<<endl;
    for (int i = 0; i < n; i++){
        cout<<endl<<'A'<<"->"<<char('A'+i)<<"\t\t"<<dist[i]<<"\t\t\t\t"<<'A'<<"\t";
        showpath(path,i);

    }
}

void dijktras(int weight[][100],int n,int source)
{
    int path[n];
    int dist[n];
    char traversed[n];
    for (int i=0;i<n;i++)
    {
        if (i!=source)
        {
            dist[i]=9999;
        }
        else
        {
            dist[i]=0;
            path[i]=-1;
        }
        traversed[i]='\0';
        
    }
    int min=9999;
    int min_pos;
    for (int i=0;i<n-1;i++)
    {
        int min_pos=mindist(dist,traversed,n);
        traversed[min_pos] = char('A' + i);

        for (int j=0;j<n;j++)
        {
            if(traversed[j]=='\0'&& weight[min_pos][j] && dist[min_pos]!=9999 && dist[min_pos]+weight[min_pos][j]<dist[j])
            {
                dist[j]=dist[min_pos]+weight[min_pos][j];
                path[j]=min_pos;
            }
        }
    }
    printSolution(dist,n,path);
}
int main()
{
    int n;

    cout << "Enter number of vertices in the graph:" << endl;
    cin >> n;
    int weight[100][100];
    cout << "Enter weights of the paths connecting each vertex(Enter 9999 for the pair of vertices with no path):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter cost of path between " << char('A' + i) << " to " << char('A' + j) << endl;
            cin >> weight[i][j];
        }
    }
    cout << "The matrix showing costs of paths connecting vertices:" << endl;
    printDistance(weight, n);
    dijktras(weight,n,0);
}
