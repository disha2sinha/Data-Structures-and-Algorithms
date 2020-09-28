class Node:
    def __init__(self,item):
        self.left=None
        self.right=None
        self.value=item

def leftview(root):
    if root is None:
        return
    queue=[]
    queue.append(root)
    while queue:
        count=len(queue)
        for i in range(0,count):
            current=queue.pop(0)
            if i==0:
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
print("Left View Of Binary Tree")
leftview(root)