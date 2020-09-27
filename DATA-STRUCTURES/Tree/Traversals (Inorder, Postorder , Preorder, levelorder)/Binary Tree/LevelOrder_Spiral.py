class Node:
    def __init__(self,item):
        self.left=None
        self.right=None
        self.value=item
def spiralLevelOrder(root):
    stack1=[]
    stack2=[]
    stack1.append(root)
    while stack1 or stack2:
        while stack1:
            current=stack1.pop()
            print(current.value,end=" ")
            if current.right:
                stack2.append(current.right)
            if current.left:
                stack2.append(current.left)
        while stack2:
            current=stack2.pop()
            print(current.value,end=" ")
            if current.left:
                stack1.append(current.left)
            if current.right:
                stack1.append(current.right)
root=Node(int(input("Enter Element: ")))
root.left=Node(int(input("Enter Element: ")))
root.right=Node(int(input("Enter Element: ")))
root.left.left=Node(int(input("Enter Element: ")))
root.left.right=Node(int(input("Enter Element: ")))
root.right.left=Node(int(input("Enter Element: ")))
root.right.right=Node(int(input("Enter Element: ")))
print("Level-order Traversal in Spiral Form:")
spiralLevelOrder(root)

