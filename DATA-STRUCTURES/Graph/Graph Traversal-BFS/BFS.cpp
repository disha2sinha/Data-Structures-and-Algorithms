#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
    int nodes;
    vector<int> *adjacency_list;

public:
    Graph(int nodes);
    void addEdgetoList(int node1, int node2);
    void bfs(int starting_node);
};
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    adjacency_list = new vector<int>[nodes];
}
void Graph::addEdgetoList(int node1, int node2)
{
    adjacency_list[node1].push_back(node2);
}
void Graph::bfs(int starting_node)
{
    vector<bool> visited(nodes, false);
    queue<int> node_queue;
    visited[starting_node]=true;
    node_queue.push(starting_node);
    while (node_queue.empty() != true)
    {
        int node = node_queue.front();
        node_queue.pop();
        cout << node << " ";
        visited[node] = true;
        for (int i = 0; i < adjacency_list[node].size(); ++i)
        {
            if (visited[adjacency_list[node][i]] == false)
                node_queue.push(adjacency_list[node][i]);
        }
    }
}
int main()
{
    cout << "Enter number of nodes in graph: " << endl;
    int nodes, edges;
    cin >> nodes;
    Graph g(nodes);
    cout << "Enter number of edges in graph: " << endl;
    cin >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int node1, node2;
        cout << " Enter Nodes joining edge: " << endl;
        cin >> node1 >> node2;
        g.addEdgetoList(node1, node2);
    }
    int start;
    cout<<"Enter starting vertex:"<<endl;
    cin>>start;
    cout << "Following is Depth First Traversal" << endl;

    g.bfs(start);

    return 0;
}
