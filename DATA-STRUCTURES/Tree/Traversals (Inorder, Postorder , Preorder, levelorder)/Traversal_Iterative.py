class Node:
    def __init__(self,item):
        self.left=None
        self.right=None
        self.value=item
def preorder(root):
    if not root:
        return
    visited=[]
    visited.append(root)
    while len(visited)>0:
        current=visited.pop()
        print(current.value, end=" ")
        if current.right is not None:
            visited.append(current.right)
        if current.left is not None:
            visited.append(current.left)
def inorder(root):
    current=root
    visited=[]
    while True:
        if current:
            visited.append(current)
            current=current.left
        elif visited:
            current=visited.pop()
            print (current.value,end=" ")
            current=current.right
        else:
            break
def postorder(root):
    current=root
    visited=set()
    while current and current not in visited:
        if current.left and current.left not in visited:
            current=current.left
        elif current.right and current.right not in visited:
            current=current.right
        else:
            print (current.value,end=" ")
            visited.add(current)
            current=root
def levelorder(root):
    if root is None:
        return
    queue=[]
    queue.append(root)
    while queue:
        current=queue.pop(0)
        print(current.value,end=" ")
        if current.left is not None:
            queue.append(current.left)
        if current.right is not None:
            queue.append(current.right)
        
root=Node(int(input("Enter Element: ")))
root.left=Node(int(input("Enter Element: ")))
root.right=Node(int(input("Enter Element: ")))
root.left.left=Node(int(input("Enter Element: ")))
root.left.right=Node(int(input("Enter Element: ")))
root.right.left=Node(int(input("Enter Element: ")))
root.right.right=Node(int(input("Enter Element: ")))
print("Pre-order Traversal")
preorder(root)
print("\nIn-order Traversal")
inorder(root)
print("\nPost-order Traversal")
postorder(root)
print("\nLevel-order Traversal")
levelorder(root)



