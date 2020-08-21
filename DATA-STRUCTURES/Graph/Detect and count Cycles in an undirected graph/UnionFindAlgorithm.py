class Graph:
    def __init__(self,nodes):
        self.nodes=nodes
        self.graph=dict()
    def add_edge(self,node1,node2):
        if node1 not in self.graph.keys():
            self.graph[node1]=[]
        self.graph[node1].append(node2)
    def find(self,parent,curr_node):
        if parent[curr_node]<=-1:
            return curr_node
        
        return self.find(parent,parent[curr_node])
    def show_graph(self):
        print("Graph Looks Like : ")
        print(self.graph)
    def union(self,parent,node1,node2):
        parent_node1 = self.find(parent, node1)
        parent_node2 = self.find(parent, node2)
        if parent_node1>parent_node2:
            parent[parent_node1]=parent_node2
            parent[parent_node2]-=1
        elif parent_node1<parent_node2:
            parent[parent_node2] = parent_node1
            parent[parent_node1] -= 1
        elif parent_node1==parent_node2:
            parent[parent_node2]=parent_node1
            parent[parent_node1]-=1
    def detectCycles(self):
        cycles=0
        parent=[-1]*self.nodes
        for node1 in self.graph.keys():
            for node2 in self.graph[node1]:
                parent_node1=self.find(parent,node1)
                parent_node2=self.find(parent,node2)
                if parent_node1==parent_node2:
                    cycles+=1
                self.union(parent,parent_node1,parent_node2)
        if cycles>0:
            print("Graph has {} cycles".format(cycles))
        else:
            print("No cycles detected")
g=Graph(int(input("Enter Number of Nodes: ")))
edges=int(input("Enter number of edges: "))
for i in range(1,edges+1):
    node1=int(input("Enter First Node :"))
    node2 = int(input("Enter Second Node :"))
    g.add_edge(node1,node2)
g.show_graph()
g.detectCycles()
