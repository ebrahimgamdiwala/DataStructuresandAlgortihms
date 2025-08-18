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
 * @brief Helper function to calculate the height of a binary tree.
 * The height is the number of nodes along the longest path from the root down to the
 * farthest leaf node.
 * @param root A pointer to the root of the tree/subtree.
 * @return int The height of the tree.
 */
int heightOfBinaryTree(TreeNode* root) {
    // Base Case: The height of an empty tree is 0.
    if (root == nullptr) {
        return 0;
    }
    // Recursively calculate the height of the left and right subtrees.
    int leftHt = heightOfBinaryTree(root->left);
    int rightHt = heightOfBinaryTree(root->right);

    // The height of the tree is 1 (for the current node) plus the height of the taller subtree.
    return max(leftHt, rightHt) + 1;
}

/**
 * @brief Calculates the diameter of a binary tree.
 * The diameter is the length of the longest path between any two nodes in a tree.
 * This path may or may not pass through the root.
 *
 * @param root A pointer to the root of the tree.
 * @return int The diameter of the tree.
 *
 * ## Overall Approach
 * This function recursively calculates the diameter. For any given node, the longest path
 * (diameter) in the tree rooted at that node is the maximum of three things:
 * 1. The diameter of the left subtree.
 * 2. The diameter of the right subtree.
 * 3. The longest path that passes *through the current node*, which is the height of the
 * left subtree plus the height of the right subtree.
 *
 * The function computes these three values and returns the largest one.
 *
 * ## Time Complexity: O(N^2)
 * This approach is inefficient. For every node in the tree (N nodes), the `diameterOfBinaryTree`
 * function calls `heightOfBinaryTree` twice. The `heightOfBinaryTree` function itself can
 * take up to O(N) time in the worst case (a skewed tree). This leads to a quadratic time
 * complexity, as the height calculation is repeated for the same nodes multiple times.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the depth of the recursion stack. In the worst
 * case of a skewed tree, the height (H) can be equal to the number of nodes (N), making
 * the space complexity O(N). For a balanced tree, it's O(log N).
 */
int diameterOfBinaryTree(TreeNode* root) {
    // Base Case: The diameter of an empty tree is 0.
    if (root == nullptr) {
        return 0;
    }
    // 1. Calculate the diameter of the left subtree recursively.
    int leftDiameter = diameterOfBinaryTree(root->left);
    // 2. Calculate the diameter of the right subtree recursively.
    int rightDiameter = diameterOfBinaryTree(root->right);
    // 3. Calculate the length of the path passing through the current root node.
    int currDiameter = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);

    // The final diameter is the maximum of these three possibilities.
    return max(max(leftDiameter, rightDiameter), currDiameter);
}

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

    cout << "Calculating the diameter of the binary tree..." << endl;
    cout << "Diameter: " << diameterOfBinaryTree(root) << endl; // Expected: 3 (path is 4-2-1-3 or 5-2-1-3)

    return 0;
}
