// Required for input/output operations, like printing to the console, and for using vectors.
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node, specifically for a BST.
class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to easily create a new node.
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

/**
 * @brief Inserts a new value into the Binary Search Tree.
 * @param root The root of the tree/subtree to insert into.
 * @param val The value to insert.
 * @return Node* The root of the modified tree.
 *
 * ## Overall Approach
 * This function recursively finds the correct position for the new value while maintaining
 * the BST property: for any node, all values in its left subtree are smaller, and all
 * values in its right subtree are larger.
 *
 * ## Time Complexity: O(H), where H is the height of the tree.
 * - Best/Average Case (Balanced Tree): O(log N)
 * - Worst Case (Skewed Tree): O(N)
 * ## Space Complexity: O(H) due to the recursion stack.
 */
Node *insert(Node *root, int val) {
    // Base Case: If we've found an empty spot, create the new node here.
    if (root == nullptr) {
        return new Node(val);
    }

    // Recursive Step: Decide whether to go left or right.
    if (val < root->data) {
        // If the value is smaller, it belongs in the left subtree.
        root->left = insert(root->left, val);
    } else {
        // If the value is larger or equal, it belongs in the right subtree.
        root->right = insert(root->right, val);
    }

    return root;
}

/**
 * @brief Searches for a target value in the BST.
 * @param root The root of the tree/subtree to search in.
 * @param target The value to find.
 * @return bool True if the target is found, false otherwise.
 *
 * ## Overall Approach
 * This function leverages the BST property to efficiently search for a value. By comparing
 * the target with the current node's data, it can eliminate half of the remaining tree
 * in each step.
 *
 * ## Time Complexity: O(H), where H is the height of the tree.
 * ## Space Complexity: O(H) due to the recursion stack.
 */
bool searchBST(Node* root, int target) {
    // Base Case 1: If we reach a null pointer, the target is not in the tree.
    if (root == nullptr) {
        return false;
    }

    // Base Case 2: If we find the target, return true.
    if (root->data == target) {
        return true;
    }
    // Recursive Step: Decide which subtree to search.
    else if (root->data < target) {
        // If the target is larger, it must be in the right subtree.
        return searchBST(root->right, target);
    } else {
        // If the target is smaller, it must be in the left subtree.
        return searchBST(root->left, target);
    }
    return false; // This line is technically unreachable but good practice.
}

/**
 * @brief Constructs a BST from a vector of integers.
 * @param arr The vector of values to insert.
 * @return Node* The root of the newly constructed BST.
 *
 * ## Time Complexity: O(N * H)
 * This is because it performs N insertions, and each insertion takes O(H) time.
 * For a balanced tree, this is O(N log N). For a skewed tree, it's O(N^2).
 */
Node *buildBST(vector<int> arr) {
    Node *root = nullptr;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}

/**
 * @brief Performs an inorder traversal of the BST, printing values in sorted order.
 * @param root The root of the tree to traverse.
 *
 * ## Time Complexity: O(N)
 * ## Space Complexity: O(H) for the recursion stack.
 */
void inOrderTraversal(Node *root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

/**
 * @brief Finds the inorder successor (the smallest value in a subtree).
 * @param root The root of the subtree.
 * @return Node* A pointer to the node with the smallest value.
 *
 * ## Time Complexity: O(H)
 */
Node *getInorderSuccessor(Node *root) {
    // The smallest value is the leftmost node.
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

/**
 * @brief Deletes a node with a given key from the BST.
 * @param root The root of the tree/subtree.
 * @param key The key of the node to delete.
 * @return Node* The root of the modified tree.
 *
 * ## Overall Approach
 * First, it recursively finds the node to delete. Once found, there are three cases:
 * 1. Node has 0 or 1 child: The node can be easily removed by linking its parent to its child.
 * 2. Node has 2 children: This is the complex case. We find the node's inorder successor
 * (the smallest node in its right subtree), copy its data to the current node, and then
 * recursively delete the inorder successor node.
 *
 * ## Time Complexity: O(H)
 * ## Space Complexity: O(H) for the recursion stack.
 */
Node *deleteNodeBST(Node *root, int key) {
    // Base Case: If the tree is empty, return.
    if (root == nullptr) {
        return nullptr;
    }
    // Find the node to delete.
    if (key < root->data) {
        root->left = deleteNodeBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNodeBST(root->right, key);
    } else { // Node found, now handle deletion cases.
        // Case 1: Node has no left child.
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        // Case 2: Node has no right child.
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        // Case 3: Node has two children.
        } else {
            // Find the inorder successor (smallest node in the right subtree).
            Node *IS = getInorderSuccessor(root->right);
            // Copy the successor's data to this node.
            root->data = IS->data;
            // Recursively delete the successor node from the right subtree.
            root->right = deleteNodeBST(root->right, IS->data);
        }
    }
    return root;
}

int main() {
    // Hardcoded array to build the BST.
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    // Build the BST from the array.
    Node *root = buildBST(arr);

    // Print the inorder traversal to verify the structure (should be sorted).
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Test the search function.
    cout << "Searching for 2: " << (searchBST(root, 2) ? "Found" : "Not Found") << endl;
    cout << "Searching for 7: " << (searchBST(root, 7) ? "Found" : "Not Found") << endl;

    // Test the deletion function.
    cout << "Deleting node 6..." << endl;
    deleteNodeBST(root, 6);

    // Print the inorder traversal again to see the result of the deletion.
    cout << "In-order Traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
