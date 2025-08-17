#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;
Node *buildTreePreorder(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return nullptr;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTreePreorder(preorder);
    root->right = buildTreePreorder(preorder);

    return root;
}
void preOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        // cout << -1 << " ";
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        // cout << -1 << " ";
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        // cout << -1 << " ";
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == nullptr)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(nullptr);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}

int heightOfBinaryTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int countNodesOfBinaryTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int noOfLeftNodes = countNodesOfBinaryTree(root->left);
    int noOfRightNodes = countNodesOfBinaryTree(root->right);

    return (noOfLeftNodes + noOfRightNodes) + 1;
}

int sumOfNodesBinaryTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftSum = sumOfNodesBinaryTree(root->left);
    int rightSum = sumOfNodesBinaryTree(root->right);

    return leftSum + rightSum + root->data;
}
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTreePreorder(preorder);

    cout << "Data of Root Node : " << root->data << endl;
    cout << "Data of Left Child of Root Node : " << root->left->data << endl;
    cout << "Data of Right Child of Root Node : " << root->right->data << endl;
    cout << "Pre Order Traversal : " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "In Order Traversal : " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Post Order Traversal : " << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "Height of the Binary Tree is : " << heightOfBinaryTree(root) << endl;
    cout << "No of Nodes in the Binary Tree are : " << countNodesOfBinaryTree(root) << endl;
    cout << "Sum of all Nodes in the Binary Tree is : " << sumOfNodesBinaryTree(root) << endl;

    return 0;
}