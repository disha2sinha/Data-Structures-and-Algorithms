#include <iostream>
#include <climits>
#include <queue>
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
bool isIdentical(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    queue<Node *> queue1;
    queue<Node *> queue2;
    queue1.push(root1);
    queue2.push(root2);
    while (!queue1.empty() && !queue2.empty())
    {
        Node *current1 = queue1.front();
        Node *current2 = queue2.front();
        queue1.pop();
        queue2.pop();
        if (current1->value != current2->value)
            return false;
        if (current1->left && current2->left)
        {
            queue1.push(current1->left);
            queue2.push(current2->left);
        }
        else if ((current1->left == NULL || current2->left == NULL) && !(current1->left == NULL && current2->left == NULL))
            return false;
        if (current1->right && current2->right)
        {
            queue1.push(current1->right);
            queue2.push(current2->right);
        }
        else if ((current1->right == NULL || current2->right == NULL) && !(current1->right == NULL && current2->right == NULL))
            return false;
    }
    return true;
}
int main()
{
    struct Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    struct Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    bool flag = isIdentical(root1,root2);
    if (flag)
        cout << "Trees are Identical" << endl;
    else
        cout << "Trees are NOT Identical" << endl;
}