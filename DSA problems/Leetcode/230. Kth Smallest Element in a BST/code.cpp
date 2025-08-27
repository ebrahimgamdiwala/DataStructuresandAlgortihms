// Required for input/output operations.
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
 * @brief Finds the k-th smallest element in a Binary Search Tree (BST).
 *
 * ## Overall Approach
 * The function leverages the fundamental property of a BST: an inorder traversal
 * (`Left -> Root -> Right`) visits the nodes in ascending sorted order. This algorithm
 * essentially performs an inorder traversal while keeping a count of the nodes visited.
 * When the count reaches `k`, the value of the current node is the k-th smallest element.
 *
 * A member variable `prevK` acts as a counter for the visited nodes. The recursion
 * explores the left subtree first. If the k-th element is found there, its value is
 * immediately propagated up and returned. If not, the counter is incremented for the
 * current node. If this makes the count equal to `k`, the current node's value is the
 * answer. Otherwise, the search continues in the right subtree.
 *
 * ## Time Complexity: O(N)
 * In the worst case (when `k` is N or the tree is skewed), the algorithm may have to
 * visit all N nodes in the tree.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). In the worst case of a skewed tree, this can be O(N).
 */
class Solution {
public:
    // `prevK` acts as a counter to track the number of nodes visited in inorder sequence.
    int prevK = 0;

    /**
     * @brief The main recursive function to find the k-th smallest element.
     * @param root The current node in the traversal.
     * @param k The target rank (e.g., 1st smallest, 2nd smallest, etc.).
     * @return int The value of the k-th smallest element, or -1 if not found.
     */
    int kthSmallest(TreeNode* root, int k) {
        // Base Case: If the node is null, we've reached the end of a branch.
        if (root == nullptr) {
            return -1;
        }

        // 1. Traverse the left subtree first (Inorder traversal).
        if (root->left) {
            int leftAns = kthSmallest(root->left, k);
            // If the answer was found in the left subtree, propagate it up.
            if (leftAns != -1) {
                return leftAns;
            }
        }

        // 2. Process the current node (the "in" part of inorder).
        // After visiting the entire left subtree, we visit the root.
        // Increment our counter.
        prevK++;
        // If the counter now equals k, this is the node we're looking for.
        if (prevK == k) {
            return root->val;
        }

        // 3. Traverse the right subtree.
        if (root->right) {
            int rightAns = kthSmallest(root->right, k);
            // If the answer was found in the right subtree, propagate it up.
            if (rightAns != -1) {
                return rightAns;
            }
        }

        // If the k-th element was not found in this subtree, return -1.
        return -1;
    }
};

int main() {
    // --- Test Case ---
    // Create a sample BST:
    //         3
    //        / \
    //       1   4
    //        \
    //         2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1, nullptr, new TreeNode(2));
    root->right = new TreeNode(4);

    Solution sol;
    int k = 1;
    cout << "Finding the " << k << "st smallest element..." << endl;
    cout << "Result: " << sol.kthSmallest(root, k) << endl; // Expected: 1

    // Reset for the next test
    Solution sol2;
    k = 3;
    cout << "Finding the " << k << "rd smallest element..." << endl;
    cout << "Result: " << sol2.kthSmallest(root, k) << endl; // Expected: 3

    return 0;
}
