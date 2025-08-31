#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *buildBST(vector<int> values) {
    Node *root = nullptr;
    for (int value : values) {
        root = insert(root, value);
    }
    return root;
}
Node *buildBSTFromSorted(vector<int> arr, int st, int end){
    if(st>end){
        return nullptr;
    }
        int mid = st + (end-st)/2;
    
        Node *root = new Node(arr[mid]);
        root->left = buildBSTFromSorted(arr, st, mid-1);
        root->right = buildBSTFromSorted(arr, mid+1, end);

        return root;
}

void inorderTraversalHelper(Node *root, vector<int> &result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversalHelper(root->left, result);
    result.push_back(root->data);
    inorderTraversalHelper(root->right, result);
}

vector<int> inorderTraversal(Node *root) {
    vector<int> result;
    inorderTraversalHelper(root, result);
    return result;
}

Node *merge2BST(Node *root1, Node *root2) {
    vector<int> arr1 = inorderTraversal(root1);
    vector<int> arr2 = inorderTraversal(root2);
    
    vector<int> temp; // Final BST inorder sorted

    int i = 0, j = 0;

    while (i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while (i<arr1.size())
    {
        temp.push_back(arr1[i++]);
    }
    while (j<arr2.size())
    {
        temp.push_back(arr2[j++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size()-1);
}


int main(){
    vector<int> values1 = {8, 2, 1, 10};
    vector<int> values2 = {5, 3, 0};

    Node *root1 = buildBST(values1);
    Node *root2 = buildBST(values2);

    Node *mergedRoot = merge2BST(root1, root2);

    vector<int> result = inorderTraversal(mergedRoot);

    cout << "BST after merging : " << endl;
    for(int el : result){
        cout << el << " ";
    }

    return 0;
}