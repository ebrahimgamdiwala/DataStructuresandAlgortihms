// Required for input/output and the swap function.
#include <iostream>
#include <algorithm>
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
 * @brief Recovers a Binary Search Tree where exactly two nodes have been swapped.
 *
 * ## Overall Approach
 * The core idea relies on the property that an inorder traversal of a valid BST produces a
 * sorted sequence of node values. If two nodes are swapped, this sorted order will be
 * violated. This algorithm performs an inorder traversal to find the two nodes that are
 * out of place and then swaps their values to restore the BST property.
 *
 * We use a `prev` pointer to keep track of the previously visited node in the traversal.
 * When we find a node whose value is less than the `prev` node's value, we have found a
 * violation of the sorted order.
 *
 * - The *first* time we find a violation (`prev->val > root->val`), the `prev` node is one of the
 * swapped nodes. We record it as `first`.
 * - The *second* node involved in the swap will be the current `root` at the point of violation.
 * We record this as `second`. If there is a second violation later in the traversal (in the
 * case of non-adjacent swapped nodes), we simply update `second` to the new `root`.
 *
 * After the traversal is complete, `first` and `second` will hold the two nodes that need
 * to be swapped. A simple value swap restores the tree.
 *
 * ## Time Complexity: O(N)
 * We must visit every node in the tree once during the inorder traversal.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). For a balanced tree, this is O(log N). For a skewed
 * tree, it is O(N).
 */
class Solution {
public:
    // Pointers to track the nodes during traversal.
    TreeNode* prev = nullptr;   // Tracks the previous node in the inorder sequence.
    TreeNode* first = nullptr;  // The first node that is out of order.
    TreeNode* second = nullptr; // The second node that is out of order.

    /**
     * @brief Performs an inorder traversal to find the two swapped nodes.
     * @param root The current node in the traversal.
     */
    void inorder(TreeNode* root) {
        // Base case: stop if the node is null.
        if (root == nullptr) {
            return;
        }

        // 1. Traverse the left subtree.
        inorder(root->left);

        // 2. Process the current node.
        // Check for a violation of the sorted order.
        if (prev != nullptr && prev->val > root->val) {
            // If this is the first violation we've found, the 'prev' node is the first swapped node.
            if (first == nullptr) {
                first = prev;
            }
            // The 'root' node is the second swapped node. This might be updated if a second
            // violation is found (for non-adjacent swaps).
            second = root;
        }
        // Update prev to the current node before moving on.
        prev = root;

        // 3. Traverse the right subtree.
        inorder(root->right);
    }

    /**
     * @brief Recovers the BST by finding and swapping the two incorrect nodes.
     * @param root The root of the BST to recover.
     */
    void recoverTree(TreeNode* root) {
        // Call the inorder traversal to populate the 'first' and 'second' pointers.
        inorder(root);
        // Swap the values of the two identified nodes to fix the BST.
        swap(first->val, second->val);
    }
};

/**
 * @brief Helper function to print the inorder traversal of a tree.
 * @param root The root of the tree to print.
 */
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // --- Test Case ---
    // Create an invalid BST where 3 and 7 are swapped.
    // Original correct tree: 1, 3, 4, 6, 7, 8, 10
    // Swapped tree:          1, 7, 4, 6, 3, 8, 10
    //         6
    //        / \
    //       7   8
    //      / \   \
    //     1   4   10
    //        /
    //       3
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7); // Should be 3
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3); // Should be null or part of 3's subtree
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(10);
    // Let's create a more standard swapped tree for clarity.
    // Correct tree: 3 -> 1, 4 -> null, 2
    // Swapped tree: 2 -> 1, 4 -> null, 3
    TreeNode* swappedRoot = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), nullptr));


    cout << "Inorder traversal before recovery: ";
    printInorder(swappedRoot);
    cout << endl; // Expected: 1 3 2 4 (incorrect order)

    Solution sol;
    sol.recoverTree(swappedRoot);

    cout << "Inorder traversal after recovery:  ";
    printInorder(swappedRoot);
    cout << endl; // Expected: 1 2 3 4 (correct sorted order)

    return 0;
}
