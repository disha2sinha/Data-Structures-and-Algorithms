class Node:
    def __init__(self,item):
        self.left=None
        self.right=None
        self.value=item
def preorder(root):
    if root:
        print(root.value)
        preorder(root.left)
        preorder(root.right)
def inorder(root):
    if root:
        inorder(root.left)
        print(root.value)
        inorder(root.right)
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.value)
root=Node(int(input("Enter Element:")))
root.left=Node(int(input("Enter Element: ")))
root.right=Node(int(input("Enter Element: ")))
root.left.left=Node(int(input("Enter Element: ")))
root.left.right=Node(int(input("Enter Element: ")))
root.right.left=Node(int(input("Enter Element: ")))
root.right.right=Node(int(input("Enter Element: ")))
print("Preorder Traversal")
preorder(root)
print("Inorder Traversal")
inorder(root)
print("Postorder Traversal")
postorder(root)



