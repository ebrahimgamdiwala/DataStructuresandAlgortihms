// Required for input/output operations, like printing to the console.
#include <iostream>

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
 * @brief Flattens a binary tree to a linked list in-place using a recursive approach.
 *
 * ## Overall Approach
 * This function uses a recursive, "reverse pre-order" traversal (`Right -> Left -> Root`).
 * It flattens the tree such that each node's right child points to the next node in the
 * pre-order traversal, and its left child is always null.
 *
 * A member variable `nextRight` (or a global/static pointer) is used to keep track of the
 * previously visited node. As the recursion unwinds from the rightmost leaf, each node
 * sets its `right` pointer to this `nextRight` node and then updates `nextRight` to be
 * itself. This effectively builds the linked list from tail to head.
 *
 * ## Time Complexity: O(N)
 * The algorithm performs a traversal that visits every node (N) in the tree exactly once.
 * Therefore, the time complexity is linear.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). In the worst case of a skewed tree, this can be O(N).
 */
class Solution {
public:
    // This pointer keeps track of the head of the already-flattened list segment.
    TreeNode* nextRight = nullptr;

    /**
     * @brief The recursive function to flatten the tree.
     * @param root The current node in the traversal.
     */
    void flatten(TreeNode* root) {
        // Base Case: If the node is null, do nothing.
        if (root == nullptr) {
            return;
        }

        // STEP 1: Recursively flatten the right subtree first.
        // After this call, the entire right subtree is a linked list, and `nextRight`
        // points to the head of that list.
        flatten(root->right);

        // STEP 2: Recursively flatten the left subtree.
        // After this call, the entire left subtree is a linked list, and `nextRight`
        // now points to the head of the flattened left subtree list.
        flatten(root->left);

        // STEP 3: Process the current node (Post-order action).
        // Set the current node's left child to null as required.
        root->left = nullptr;
        // Set the current node's right child to the head of the previously processed list.
        root->right = nextRight;
        // Update `nextRight` to be the current node, making it the new head of the
        // growing flattened list for the parent call.
        nextRight = root;
    }
};

/**
 * @brief A helper function to print the flattened tree (linked list).
 * @param root The root of the flattened tree.
 */
void printFlattenedTree(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->right;
    }
    cout << "nullptr" << endl;
}

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         1
    //        / \
    //       2   5
    //      / \   \
    //     3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    cout << "Flattening the binary tree..." << endl;
    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree (linked list):" << endl;
    printFlattenedTree(root);
    // Expected Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr

    return 0;
}
