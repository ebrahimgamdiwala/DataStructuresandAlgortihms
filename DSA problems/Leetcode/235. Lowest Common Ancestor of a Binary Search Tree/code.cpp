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
 * @brief Finds the lowest common ancestor (LCA) of two given nodes in a Binary Search Tree (BST).
 *
 * @param root A pointer to the root of the BST/subtree.
 * @param p A pointer to the first node.
 * @param q A pointer to the second node.
 * @return TreeNode* A pointer to the lowest common ancestor node.
 *
 * ## Overall Approach
 * This function leverages the inherent properties of a BST to efficiently find the LCA.
 * The core idea is that the LCA of two nodes `p` and `q` is the node where their paths
 * from the root diverge.
 * - If both `p` and `q` have values smaller than the current `root`, their LCA must be in
 * the left subtree.
 * - If both `p` and `q` have values larger than the current `root`, their LCA must be in
 * the right subtree.
 * - If one value is smaller and the other is larger (or if one of them is the root), then
 * the current `root` is the "split point" and therefore must be the LCA.
 *
 * ## Time Complexity: O(H)
 * The time complexity is proportional to the height of the tree (H). In each step, we
 * eliminate the rest of the tree and only traverse one path. For a balanced BST, this is
 * O(log N). For a skewed tree, it is O(N).
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H).
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base Case: If the root is null, we can't find an LCA.
    if (root == nullptr) {
        return nullptr;
    }

    // If both p and q are smaller than the root, the LCA must be in the left subtree.
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    // If both p and q are larger than the root, the LCA must be in the right subtree.
    else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    // Otherwise, we've found the split point. This means the current root is the LCA.
    // This case covers:
    // 1. p is in one subtree and q is in the other.
    // 2. The root itself is p or q.
    else {
        return root;
    }
}

int main() {
    // --- Test Case ---
    // Create a sample BST:
    //         6
    //        / \
    //       2   8
    //      / \ / \
    //     0  4 7  9
    //       / \
    //      3   5
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2, new TreeNode(0), new TreeNode(4, new TreeNode(3), new TreeNode(5)));
    root->right = new TreeNode(8, new TreeNode(7), new TreeNode(9));

    // Define the nodes we want to find the LCA for.
    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->right; // Node with value 8
    cout << "Finding LCA for nodes " << p->val << " and " << q->val << "..." << endl;
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA is: " << lca->val << endl; // Expected: 6
    cout << "---" << endl;

    // Another test case where the LCA is one of the nodes.
    p = root->left; // Node with value 2
    q = root->left->right; // Node with value 4
    cout << "Finding LCA for nodes " << p->val << " and " << q->val << "..." << endl;
    lca = lowestCommonAncestor(root, p, q);
    cout << "LCA is: " << lca->val << endl; // Expected: 2
    cout << "---" << endl;

    return 0;
}
