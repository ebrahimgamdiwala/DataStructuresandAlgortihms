// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the max function.
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
 * @brief Calculates the diameter of a binary tree using an optimized single-pass approach.
 *
 * The diameter is the length of the longest path between any two nodes in a tree.
 * This path may or may not pass through the root.
 *
 * ## Overall Approach
 * This function uses a single recursive helper function (`heightOfBinaryTree`) to calculate
 * both the height of a subtree and the diameter of the tree in one pass. It uses a member
 * variable `ans` to keep track of the maximum diameter found so far.
 *
 * The `heightOfBinaryTree` function performs a post-order traversal. For each node, it:
 * 1. Recursively calculates the height of its left and right subtrees.
 * 2. Calculates the potential diameter that passes *through the current node* (`leftHt + rightHt`).
 * 3. Updates the global maximum diameter (`ans`) if this new potential diameter is larger.
 * 4. Returns the height of the subtree rooted at the current node (`max(leftHt, rightHt) + 1`).
 *
 * By combining these two calculations, we avoid the repeated calls to the height function
 * that made the previous approach inefficient.
 *
 * ## Time Complexity: O(N)
 * This approach is highly efficient. We traverse every node in the tree exactly once.
 * All operations at each node are constant time. Therefore, the time complexity is linear
 * with respect to the number of nodes (N).
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the depth of the recursion stack. In the worst
 * case of a skewed tree, the height (H) can be equal to the number of nodes (N), making
 * the space complexity O(N). For a balanced tree, it's O(log N).
 */
class Solution {
public:
    // This member variable will store the maximum diameter found during the traversal.
    int ans = 0;

    /**
     * @brief A modified height function that calculates height and updates the diameter.
     * @param root A pointer to the root of the tree/subtree.
     * @return int The height of the subtree rooted at `root`.
     */
    int heightOfBinaryTree(TreeNode* root) {
        // Base Case: The height of an empty tree is 0.
        if (root == nullptr) {
            return 0;
        }
        // Recursively find the height of the left and right subtrees.
        int leftHt = heightOfBinaryTree(root->left);
        int rightHt = heightOfBinaryTree(root->right);

        // **The Core Logic**:
        // The diameter passing through the current node is the sum of the heights
        // of its left and right subtrees. We check if this path is the longest
        // one we've seen so far and update our answer accordingly.
        ans = max(ans, leftHt + rightHt);

        // Return the height of the current node's subtree, which is needed by its parent.
        return max(leftHt, rightHt) + 1;
    }

    /**
     * @brief The main function to kick off the diameter calculation.
     * @param root A pointer to the root of the tree.
     * @return int The diameter of the tree.
     */
    int diameterOfBinaryTree(TreeNode* root) {
        // Call the helper function, which will calculate heights and update `ans`.
        heightOfBinaryTree(root);
        // The final result is stored in the `ans` member variable.
        return ans;
    }
};

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of our solution class.
    Solution sol;
    cout << "Calculating the diameter of the binary tree..." << endl;
    cout << "Diameter: " << sol.diameterOfBinaryTree(root) << endl; // Expected: 3 (path is 4-2-1-3 or 5-2-1-3)

    return 0;
}
