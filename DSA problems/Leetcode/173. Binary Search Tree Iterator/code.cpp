// Required for input/output, the stack data structure, and vectors.
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructors for convenience.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief An iterator for a Binary Search Tree that performs an in-order traversal.
 *
 * ## Overall Approach
 * The iterator simulates an in-order traversal (Left, Root, Right) using a stack. Instead of
 * recursively calling on the left child, we manually push all left children onto a stack.
 * This ensures that the node at the top of the stack is always the next smallest element.
 *
 * 1.  **Initialization:** The iterator is initialized by pushing the root and all of its
 * left-descendant nodes onto the stack. This primes the iterator so that the smallest
 * element of the BST is at the top of the stack.
 * 2.  **`next()` call:** When `next()` is called, it pops the top element (the next smallest).
 * Before returning its value, it checks if this popped node has a right subtree. If it
 * does, it means the next sequence of nodes to visit are in that right subtree.
 * Therefore, it pushes the right child and all of *its* left descendants onto the stack.
 * 3.  **`hasNext()` call:** The traversal has more elements as long as the stack is not empty.
 *
 * ## Complexity
 * - **Time Complexity:**
 * - `next()`: Amortized O(1). While the helper function `storeLeftNodes` can take O(H) time
 * (where H is the tree height), each node is pushed onto and popped from the stack exactly
 * once over the entire traversal of N nodes. Therefore, the total time for N `next()` calls
 * is O(N), making the average or amortized time for each call O(1).
 * - `hasNext()`: O(1). It's a simple check on the stack's size.
 * - **Space Complexity:** O(H), where H is the height of the tree. The maximum number of nodes
 * stored in the stack at any time is the height of the tree.
 */
class BSTIterator {
public:
    // A stack to store the path of nodes for the in-order traversal.
    stack<TreeNode*> s;

    /**
     * @brief Helper function to push a node and all its left children onto the stack.
     * @param root The starting node.
     */
    void storeLeftNodes(TreeNode* root){
        while(root != nullptr){
            s.push(root);
            root = root->left;
        }
    }

    /**
     * @brief Constructor for the BSTIterator.
     * @param root The root of the BST to iterate over.
     */
    BSTIterator(TreeNode* root) {
        // Initialize the iterator by pushing the root and its entire left chain.
        storeLeftNodes(root);
    }
    
    /**
     * @brief Returns the next smallest number in the BST.
     * @return int The value of the next node in the in-order sequence.
     */
    int next() {
        // The node at the top of the stack is the next smallest element.
        TreeNode *ansNode = s.top();
        s.pop();

        // After processing this node, the next in-order element will be the
        // smallest element in its right subtree. So, we push the right child
        // and all of its left descendants onto the stack.
        storeLeftNodes(ansNode->right);
        
        return ansNode->val;
    }
    
    /**
     * @brief Checks if there are more elements in the traversal.
     * @return bool True if there is a next smallest number, false otherwise.
     */
    bool hasNext() {
        // The traversal has a next element if the stack is not empty.
        return !s.empty();
    }
};

int main() {
    // --- Test Case ---
    // Create a sample BST:
    //         7
    //        / \
    //       3   15
    //          /  \
    //         9    20
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Iterating through the BST:" << endl;
    
    // Instantiate the iterator with the root of the tree.
    BSTIterator* obj = new BSTIterator(root);

    // Use the iterator to print the nodes in sorted order.
    while(obj->hasNext()){
        cout << obj->next() << " ";
    }
    cout << endl; // Expected Output: 3 7 9 15 20

    return 0;
}
