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
 * @brief Validates if a given binary tree is a valid Binary Search Tree (BST).
 *
 * ## Overall Approach
 * The function uses a recursive helper that validates the tree by ensuring each node's
 * value falls within a valid range (`min`, `max`). As the function traverses down the
 * tree, this range becomes progressively narrower.
 * - When moving to a left child, the current node's value becomes the new `max` constraint.
 * - When moving to a right child, the current node's value becomes the new `min` constraint.
 * This correctly enforces the BST property throughout the entire tree, where a node must
 * be greater than all values in its left subtree and smaller than all values in its right.
 *
 * ## Time Complexity: O(N)
 * The algorithm visits every node (N) in the tree exactly once.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). In the worst case of a skewed tree, this can be O(N).
 */
class Solution {
public:
    /**
     * @brief Recursive helper to validate the BST within a given range.
     * @param root The current node to check.
     * @param min A pointer to the node representing the exclusive lower bound.
     * @param max A pointer to the node representing the exclusive upper bound.
     * @return bool True if the subtree is a valid BST, false otherwise.
     */
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        // Base Case: An empty tree is a valid BST.
        if (root == nullptr) {
            return true;
        }
        // Check if the current node's value violates the lower bound.
        if (min != nullptr && root->val <= min->val) {
            return false;
        }
        // Check if the current node's value violates the upper bound.
        if (max != nullptr && root->val >= max->val) {
            return false;
        }

        // Recursive Step:
        // For the left subtree, the valid range is (min, current root's value).
        // For the right subtree, the valid range is (current root's value, max).
        // Both subtrees must be valid for the whole tree to be valid.
        return helper(root->left, min, root) && helper(root->right, root, max);
    }

    /**
     * @brief The main function to start the BST validation.
     * @param root The root of the tree to validate.
     * @return bool True if the tree is a valid BST, false otherwise.
     */
    bool isValidBST(TreeNode* root) {
        // Initial call starts with no bounds (null min and max).
        return helper(root, nullptr, nullptr);
    }
};

int main() {
    Solution sol;

    // --- Test Case 1: A valid BST ---
    //         5
    //        / \
    //       3   7
    //      / \ / \
    //     2  4 6  8
    TreeNode* validRoot = new TreeNode(5);
    validRoot->left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    validRoot->right = new TreeNode(7, new TreeNode(6), new TreeNode(8));

    cout << "Checking if the first tree is a valid BST..." << endl;
    cout << "Result: " << (sol.isValidBST(validRoot) ? "Valid" : "Invalid") << endl; // Expected: Valid
    cout << "---" << endl;


    // --- Test Case 2: An invalid BST ---
    //         5
    //        / \
    //       1   4  <-- Invalid: 4 is not > 5
    //          / \
    //         3   6
    TreeNode* invalidRoot = new TreeNode(5);
    invalidRoot->left = new TreeNode(1);
    invalidRoot->right = new TreeNode(4, new TreeNode(3), new TreeNode(6));

    cout << "Checking if the second tree is a valid BST..." << endl;
    cout << "Result: " << (sol.isValidBST(invalidRoot) ? "Valid" : "Invalid") << endl; // Expected: Invalid
    cout << "---" << endl;

    return 0;
}
