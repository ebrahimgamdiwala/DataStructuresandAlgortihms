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
 * @brief Helper function to print the tree using inorder traversal.
 * This is used to verify the result after the tree has been modified.
 * @param root A pointer to the root of the tree.
 */
void inOrderTraversal(TreeNode *root) {
    // Base Case: If the node is null, do nothing.
    if (root == nullptr) {
        return;
    }
    // Recursively visit the left subtree.
    inOrderTraversal(root->left);
    // Print the current node's value.
    cout << root->val << " ";
    // Recursively visit the right subtree.
    inOrderTraversal(root->right);
}

/**
 * @brief Transforms a binary tree into a Sum Tree in-place.
 * Each node's new value becomes its original value plus the sum of all values
 * in its left and right subtrees.
 *
 * @param root A pointer to the root of the tree/subtree.
 * @return int The sum of the entire subtree rooted at `root` (including the root's original value).
 *
 * ## Overall Approach
 * The function uses a post-order traversal (`Left, Right, Root`) to solve the problem.
 * This traversal order is crucial because to calculate the new value for a parent node,
 * we first need to have the complete sums of its left and right subtrees. The recursive
 * calls return these required sums. The function modifies the tree directly (in-place).
 *
 * ## Time Complexity: O(N)
 * The algorithm visits every node in the tree exactly once, performing constant-time
 * operations at each node. Therefore, the time complexity is linear with respect to the
 * number of nodes (N).
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack. In the
 * worst case of a skewed tree, the height (H) can be equal to the number of nodes (N),
 * making the space complexity O(N). For a balanced tree, it's O(log N).
 */
int sumTree(TreeNode *root) {
    // Base Case: The sum of an empty tree is 0.
    if (root == nullptr) {
        return 0;
    }

    // STEP 1: Recursively calculate the sum of the left subtree.
    int leftSum = sumTree(root->left);
    // STEP 2: Recursively calculate the sum of the right subtree.
    int rightSum = sumTree(root->right);

    // STEP 3: Update the current node's value.
    // The new value is its original value plus the sums from its children.
    root->val += leftSum + rightSum;

    // STEP 4: Return the new value of this node.
    // This returned value will be used by the node's parent as its `leftSum` or `rightSum`.
    return root->val;
}

int main() {
    // --- Test Case ---
    // Create a sample tree:
    // Original Tree:
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

    cout << "Original Tree (Inorder): ";
    inOrderTraversal(root);
    cout << endl;

    // The sumTree function modifies the tree in-place.
    // We don't need to use its return value here.
    sumTree(root);

    cout << "Transformed Sum Tree (Inorder): ";
    inOrderTraversal(root);
    cout << endl;
    // Expected Transformed Tree:
    //         15 (1 + 11 + 3)
    //        /  \
    //       11   3
    //      /  \
    //     4    5
    // Expected Inorder Output: 4 11 5 15 3

    return 0;
}
