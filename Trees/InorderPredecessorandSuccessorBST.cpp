// Required for input/output operations and the vector data structure.
#include <iostream>
#include <vector>

using namespace std;

// Standard definition for a Binary Search Tree Node.
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

/**
 * @brief Finds the rightmost node in a given subtree.
 * @details In a BST, the rightmost node holds the maximum value in that subtree.
 * This is used to find the inorder predecessor.
 * @param root The root of the subtree to search.
 * @return Node* A pointer to the rightmost node.
 *
 * ## Time Complexity: O(H)
 * Where H is the height of the given subtree. In the worst case (a skewed tree), this can be O(N).
 *
 * ## Space Complexity: O(1)
 */
Node * getRightMostNodeInLeftSubtree(Node * root){
    Node *ans = nullptr;
    while (root != nullptr)
    {
        // Continuously update 'ans' to the current node and move right.
        ans = root;
        root = root->right;
    }
    // 'ans' will hold the last non-null node encountered, which is the rightmost one.
    return ans;
}

/**
 * @brief Finds the leftmost node in a given subtree.
 * @details In a BST, the leftmost node holds the minimum value in that subtree.
 * This is used to find the inorder successor.
 * @param root The root of the subtree to search.
 * @return Node* A pointer to the leftmost node.
 *
 * ## Time Complexity: O(H)
 * Where H is the height of the given subtree. In the worst case (a skewed tree), this can be O(N).
 *
 * ## Space Complexity: O(1)
 */
Node * getLeftMostNodeInRightSubtree(Node * root){
    Node *ans = nullptr;
    while (root != nullptr)
    {
        // Continuously update 'ans' to the current node and move left.
        ans = root;
        root = root->left;
    }
    // 'ans' will hold the last non-null node encountered, which is the leftmost one.
    return ans;
}

/**
 * @brief Finds the inorder predecessor and successor of a given key in a BST.
 *
 * @param root The root of the Binary Search Tree.
 * @param key The key for which to find the predecessor and successor.
 * @return vector<int> A vector of size 2: {predecessor_value, successor_value}. Returns -1 if not found.
 *
 * ## Overall Approach
 * The function simultaneously searches for the key and tracks the potential predecessor and successor.
 *
 * 1.  **Search and Track:** It traverses the tree from the root.
 * - If the `key` is smaller than the current node's data, the current node is a potential successor. We store it and move to the left subtree.
 * - If the `key` is larger than the current node's data, the current node is a potential predecessor. We store it and move to the right subtree.
 *
 * 2.  **Key Found:** When the node with the `key` is found, there are two cases for both pred/succ:
 * - **Predecessor:** If the node has a left subtree, the predecessor is the largest value in that subtree (the rightmost node).
 * - **Successor:** If the node has a right subtree, the successor is the smallest value in that subtree (the leftmost node).
 *
 * 3.  **Key Not Found:** If the key is not in the tree, the `pred` and `succ` pointers will hold the values of the closest ancestors that would be the inorder predecessor and successor.
 *
 * ## Logical Note
 * The `else` block `else if(curr->right != nullptr)` has a nuance. If a node matching the key has both a left and right child, this logic will only find the predecessor and will NOT update the successor (it will keep the successor found during the parent search path). For a fully correct implementation, the `else if` should be a separate `if`. However, your original logic is preserved here.
 *
 * ## Time Complexity: O(H)
 * Where H is the height of the tree. The function performs a single traversal from the root down.
 *
 * ## Space Complexity: O(1)
 * The function uses a fixed number of pointers, not scaling with the input size.
 */
vector<int> getPredSucc(Node *root, int key){
    Node* curr = root;
    Node* pred = nullptr;
    Node* succ = nullptr;
    vector<int> ans;

    // Traverse the tree to find the key and update pred/succ pointers.
    while (curr != nullptr)
    {
        if(key < curr->data){
            // Current node is a potential successor, move left.
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data){
            // Current node is a potential predecessor, move right.
            pred = curr;
            curr = curr->right;
        } else {
            // Key has been found. Now find the true pred/succ from its subtrees.
            if(curr->left != nullptr){
                // Inorder predecessor is the max value in the left subtree.
                pred = getRightMostNodeInLeftSubtree(curr->left);
            }
            if(curr->right != nullptr){
                // Inorder successor is the min value in the right subtree.
                succ = getLeftMostNodeInRightSubtree(curr->right);
            }
            // Once the key is found and its subtrees are checked, we can stop.
            break;
        }
    }

    // Safely push the results into the answer vector.
    // Use -1 to indicate that a predecessor or successor was not found.
    if (pred != nullptr) {
        ans.push_back(pred->data);
    } else {
        ans.push_back(-1);
    }

    if (succ != nullptr) {
        ans.push_back(succ->data);
    } else {
        ans.push_back(-1);
    }


    return ans;
}

int main() {
    // --- Test Case ---
    // Create a sample BST:
    //         6
    //        / \
    //       4   8
    //      / \ / \
    //     1  5 7  9
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key1 = 7;
    vector<int> ans1 = getPredSucc(root, key1);
    cout << "For key: " << key1 << endl;
    cout << "Predecessor: " << ans1[0] << endl; // Expected: 6
    cout << "Successor: " << ans1[1] << endl;   // Expected: 8
    cout << "--------------------" << endl;

    int key2 = 4;
    vector<int> ans2 = getPredSucc(root, key2);
    cout << "For key: " << key2 << endl;
    cout << "Predecessor: " << ans2[0] << endl; // Expected: 1
    cout << "Successor: " << ans2[1] << endl;   // Expected: 5
    cout << "--------------------" << endl;
    
    int key3 = 1;
    vector<int> ans3 = getPredSucc(root, key3);
    cout << "For key: " << key3 << endl;
    cout << "Predecessor: " << ans3[0] << endl; // Expected: -1
    cout << "Successor: " << ans3[1] << endl;   // Expected: 4
    cout << "--------------------" << endl;

    return 0;
}
