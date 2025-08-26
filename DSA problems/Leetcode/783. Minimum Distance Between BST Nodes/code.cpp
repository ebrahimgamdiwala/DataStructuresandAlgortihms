// Required for input/output operations and for INT_MAX.
#include <iostream>
#include <climits>
#include <algorithm>

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
 * @brief Finds the minimum absolute difference between the values of any two nodes in a BST.
 *
 * ## Overall Approach
 * The function leverages a key property of Binary Search Trees: an inorder traversal
 * (`Left -> Root -> Right`) visits the nodes in ascending sorted order. The minimum
 * difference between any two values in a sorted list will always be between two
 * adjacent elements.
 *
 * This algorithm performs an inorder traversal. It uses a member variable `prev` to keep
 * track of the previously visited node. When it processes the current `root` node (after
 * visiting its entire left subtree), it calculates the difference between `root->val` and
 * `prev->val`. This is effectively comparing the current node with its immediate predecessor
 * in the sorted sequence. The function keeps track of the minimum such difference found.
 *
 * ## Time Complexity: O(N)
 * The algorithm performs a traversal that visits every node (N) in the tree exactly once.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). In the worst case of a skewed tree, this can be O(N).
 */
class Solution {
public:
    // `prev` keeps track of the previously visited node in the inorder traversal.
    TreeNode* prev = nullptr;
    // `minDiff` stores the minimum difference found so far. Initialized to the max possible value.
    int minDiff = INT_MAX;

    /**
     * @brief The main recursive function to find the minimum difference.
     * @param root The current node in the traversal.
     */
    void findMinDiff(TreeNode* root) {
        // Base Case: If the node is null, do nothing.
        if (root == nullptr) {
            return;
        }

        // 1. Traverse the left subtree first (Inorder traversal).
        findMinDiff(root->left);

        // 2. Process the current node (the "in" part of inorder).
        // If `prev` is not null, it means we have a predecessor to compare with.
        if (prev != nullptr) {
            // Calculate the difference and update the minimum if necessary.
            minDiff = min(minDiff, root->val - prev->val);
        }
        // Update `prev` to be the current node for the next comparison.
        prev = root;

        // 3. Traverse the right subtree.
        findMinDiff(root->right);
    }

    /**
     * @brief Kicks off the process and returns the final result.
     * @param root The root of the BST.
     * @return int The minimum difference.
     */
    int minDiffInBST(TreeNode* root) {
        findMinDiff(root);
        return minDiff;
    }
};

int main() {
    // --- Test Case ---
    // Create a sample BST:
    //         4
    //        / \
    //       2   6
    //      / \
    //     1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    cout << "Finding the minimum difference in the BST..." << endl;
    cout << "Minimum Difference: " << sol.minDiffInBST(root) << endl;
    // Expected Output: 1
    // Explanation: The inorder traversal is [1, 2, 3, 4, 6].
    // The differences between adjacent elements are (2-1)=1, (3-2)=1, (4-3)=1, (6-4)=2.
    // The minimum of these is 1.

    return 0;
}
