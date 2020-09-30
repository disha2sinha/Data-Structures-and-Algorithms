#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

struct Node
{
 struct Node* left;
 struct Node* right;
 int value;
};
struct Node* newNode(int value)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int diameter(Node* root, int* height)
    {
        int left_height=0,right_height=0;
        int left_diameter=0,right_diameter=0;

        if (root==NULL)
        {
            *height=0;
            return 0;
        }
        left_diameter= diameter(root->left, &left_height);
        right_diameter = diameter(root->right, &right_height);

        *height=std::max(left_height,right_height) +1;
        return std::max(std::max(left_diameter,right_diameter),left_height+right_height+1);
    }
int main()
{
    struct Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->left->left=newNode(6);
    root->left->right=newNode(5);
    root->left->left->right=newNode(7);
    root->left->left->right->left = newNode(9);
    root->left->left->right->left->right= newNode(12);
    root->left->right->right = newNode(8);
    root->left->right->right->left = newNode(10);
    root->left->right->right->right = newNode(11);
    root->left->right->right->right->left = newNode(13);
    int height=INT_MIN;
    int dia=diameter(root,&height);
    cout<<"Diameter of the tree: "<< dia<<endl;

}