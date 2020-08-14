#include<iostream>
#include<stack>
#include <vector>
#include<algorithm>
using namespace std;

class Graph{
    int nodes;
    vector<int> *adjacency_list;
    public:
        Graph(int nodes);
        void addEdgetoList(int node1,int node2);
        void dfs(int starting_node);
};
Graph::Graph(int nodes)
{
    this->nodes=nodes;
    adjacency_list= new vector<int>[nodes];
}
void Graph::addEdgetoList(int node1,int node2)
{
    adjacency_list[node1].push_back(node2);
}
void Graph::dfs(int starting_node)
{
    vector<bool> visited(nodes,false);
    stack<int> node_stack;
    node_stack.push(starting_node);
    while( node_stack.empty()!= true)
    {
        int node=node_stack.top();
        node_stack.pop();
        if(visited[node]==false)
        {
            cout<<node<<" ";
            visited[node]=true;
        }
        for (int i=0;i<adjacency_list[node].size();++i)
        {
            if (visited[adjacency_list[node][i]]==false)
                node_stack.push(adjacency_list[node][i]);
        }
    }

}
int main()
{
    cout<<"Enter number of nodes in graph: "<<endl;
    int nodes,edges;
    cin>>nodes;
    Graph g(nodes);
    cout << "Enter number of edges in graph: " << endl;
    cin>>edges;
    for(int i=1;i<=edges;i++)
    {
        int node1,node2;
        cout<<" Enter Nodes joining edge: "<<endl;
        cin>>node1>>node2;
        g.addEdgetoList(node1,node2);
    }
    /*g.addEdgetoList(1, 0);
    g.addEdgetoList(0, 2);
    g.addEdgetoList(2, 1);
    g.addEdgetoList(0, 3);
    g.addEdgetoList(1, 4);*/

    cout << "Following is Depth First Traversal"<<endl;
    g.dfs(0);

    return 0;
}
