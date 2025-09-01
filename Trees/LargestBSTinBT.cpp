#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Info
{
public:
    int size;
    int min;
    int max;
    Info(int s, int mn, int mx) : size(s), min(mn), max(mx) {}
};

Info helper(Node *root)
{
    if (root == nullptr)
    {
        return Info(0, INT_MAX, INT_MIN);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if (root->data > left.max && root->data < right.min)
    {
        int currMin = min(left.min, root->data);
        int currMax = max(right.max, root->data);
        int currSize = left.size + right.size + 1;
        return Info(currSize, currMin, currMax);
    }
    return Info(max(left.size, right.size), 0, 0);
}

int largestBST(Node *root)
{
    Info inf = helper(root);
    return inf.size;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << "Largest BST size: " << largestBST(root) << endl;
    
    return 0;
}