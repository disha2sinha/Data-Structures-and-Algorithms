class Node{
    int value;
    Node left;
    Node right;
    Node(int item)
    {
        value=item;
        left=null;
        right=null;
    }
}
class binaryTree{
    Node root;
    void getLCA(int data1,int data2)
    {
        Node result= findLCA(root,data1,data2);
        System.out.println("Lowest Common Ancestor of "+data1+" and "+data2+": "+ result.value);
    }
    Node findLCA(Node node,int data1, int data2)
    {
        if(node==null)
        {
            return null;
        }
        if (node.value==data1 || node.value==data2)
        {
            return node;
        }
        Node leftLCA=findLCA(node.left, data1, data2);
        Node rightLCA = findLCA(node.right, data1, data2);
        if (leftLCA != null && rightLCA != null)
            return node;
        if(leftLCA!=null)
            return leftLCA;
        return rightLCA;

    }
}
class LCA {
    public static void main(String[] args) {
        binaryTree tree = new binaryTree(); 
        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3); 
        tree.root.left.left = new Node(4); 
        tree.root.left.right = new Node(5); 
        tree.root.right.left = new Node(6); 
        tree.root.right.right = new Node(7); 
        tree.getLCA(4, 5); 
        tree.getLCA(4, 6); 
        tree.getLCA(3, 4); 
        tree.getLCA(2, 4); 

    }
        
}