#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int value;
};
struct Node *newNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int maxPathSum(Node *root, int &maxpathsum)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftmaxpath = maxPathSum(root->left, maxpathsum);
    int rightmaxpath = maxPathSum(root->right, maxpathsum);

    int maxamongchildren = std::max(std::max(leftmaxpath, rightmaxpath) + root->value, root->value);
    int maxwholenode = std::max(maxamongchildren, leftmaxpath+rightmaxpath+root->value);
    maxpathsum = std::max(maxpathsum,maxwholenode);

    return maxamongchildren;
}
int main()
{
    struct Node *root = newNode(-10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(6);
    root->left->right = newNode(5);
    root->left->left->right = newNode(7);
    root->left->left->right->left = newNode(9);
    root->left->left->right->left->right = newNode(-12);
    root->left->right->right = newNode(8);
    root->left->right->right->left = newNode(10);
    root->left->right->right->right = newNode(11);
    root->left->right->right->right->left = newNode(13);
    int maxpathsum = INT_MIN;
    int dia = maxPathSum(root, maxpathsum);
    cout << "Max Path Sum of the tree: " << maxpathsum << endl;
}