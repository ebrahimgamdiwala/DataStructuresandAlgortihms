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
 * @brief Prints all nodes at a specific level K in a binary tree.
 *
 * @param root A pointer to the root of the tree/subtree.
 * @param K The target level to print (1-indexed, so the root is at level 1).
 *
 * ## Overall Approach
 * The function uses a pre-order traversal-style recursion to find and print the nodes
 * at the target level `K`. The depth is tracked by decrementing `K` in each recursive
 * call. When `K` reaches 1, it means we have arrived at the target level, and the
 * current node's value is printed.
 *
 * ## Time Complexity: O(N)
 * In the worst-case scenario (when K is greater than the height of the tree), the
 * function will visit every node (N) in the tree. Therefore, the time complexity is
 * linear with respect to the number of nodes.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack. In the
 * worst case of a skewed tree, the height (H) of the tree can be equal to the number of
 * nodes (N), making the space complexity O(N). For a balanced tree, the height is
 * log(N), resulting in O(log N) space complexity.
 */
void KthLevel(TreeNode *root, int K) {
    // Base Case 1: If the current node is null, there's nothing to do, so we return.
    if (root == nullptr) {
        return;
    }
    // Base Case 2: If K is 1, we have reached the target level.
    if (K == 1) {
        // Print the value of the current node and stop going deeper.
        cout << root->val << " ";
        return;
    }

    // Recursive Step:
    // If we are not yet at the target level, continue the search in the left and
    // right subtrees. We pass `K-1` to signify that we are moving one level deeper.
    KthLevel(root->left, K - 1);
    KthLevel(root->right, K - 1);
}

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         1      (Level 1)
    //        / \
    //       2   3    (Level 2)
    //      / \
    //     4   5      (Level 3)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int k_level = 3;
    cout << "Nodes at level " << k_level << ": ";
    KthLevel(root, k_level); // Expected: 4 5
    cout << endl;

    k_level = 2;
    cout << "Nodes at level " << k_level << ": ";
    KthLevel(root, k_level); // Expected: 2 3
    cout << endl;

    return 0;
}
