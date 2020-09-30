class Node:
    def __init__(self,item):
        self.left=None
        self.right=None
        self.value=item

def maxDepth(root):
    if root is None:
        print(0)
        return 
    queue=[]
    queue.append(root)
    result=0
    while queue:
        count=len(queue)
        result+=1
        for i in range(0,count):
            current=queue.pop(0)
            if current.left is not None:
                queue.append(current.left)
            if current.right is not None:
                queue.append(current.right)
    print(result)

root=Node(int(input("Enter Element: ")))
root.left=Node(int(input("Enter Element: ")))
root.right=Node(int(input("Enter Element: ")))
root.left.left=Node(int(input("Enter Element: ")))
root.left.right=Node(int(input("Enter Element: ")))
root.right.left=Node(int(input("Enter Element: ")))
root.right.right=Node(int(input("Enter Element: ")))
print("Height/Maximum Depth Of Binary Tree")
maxDepth(root)
