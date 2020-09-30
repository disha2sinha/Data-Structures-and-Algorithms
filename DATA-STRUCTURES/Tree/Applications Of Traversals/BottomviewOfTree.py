class Node:
    def __init__(self,item):
        self.left=None
        self.right=None
        self.value=item
        self.horizonal_dist=0

def bottomview(root):
    if root is None:
        return
    queue=[]
    hd=0
    root.horizonal_dist=hd
    queue.append(root)
    visited={}
    while queue:
        current=queue.pop(0)
        hd=current.horizonal_dist
        visited[hd]=current.value
        if current.left is not None:
            current.left.horizonal_dist=hd-1
            queue.append(current.left)
        if current.right is not None:
            current.right.horizonal_dist=hd+1
            queue.append(current.right)
    for key in sorted(visited):
        print(visited[key],end=" ")
            
        
root =Node(20); 
root.left = Node(8); 
root.right = Node(22); 
root.left.left = Node(5); 
root.left.right = Node(3); 
root.right.left = Node(4); 
root.right.right = Node(25); 
root.left.right.left = Node(10); 
root.left.right.right = Node(14); 
print("Top View Of Binary Tree")
bottomview(root)