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
int isHeightBalanced(Node *root, int *height)
{
    int left_height = 0, right_height = 0;
    bool left_flag = false, right_flag = false;

    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    left_flag = isHeightBalanced(root->left, &left_height);
    right_flag = isHeightBalanced(root->right, &right_height);
    *height = std::max(left_height, right_height) + 1;
    if (abs(left_height-right_height)>=2)
    {
        return false;
    }
    return left_flag && right_flag;
}
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    int height = INT_MIN;
    int flag = isHeightBalanced(root, &height);
    if (flag ==0)
        cout << "Tree is NOT Height Balanced " << endl;
    else
        cout << "Tree is Height Balanced " << endl;
}