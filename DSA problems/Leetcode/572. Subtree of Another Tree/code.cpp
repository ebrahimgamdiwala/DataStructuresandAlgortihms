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
 * @brief Helper function to check if two binary trees are structurally identical
 * and have the same node values. (Same as the "isSameTree" problem).
 *
 * @param p A pointer to the root of the first tree.
 * @param q A pointer to the root of the second tree.
 * @return bool True if the trees are identical, false otherwise.
 */
bool isIdentical(TreeNode* p, TreeNode* q) {
    // Base Case 1: If both nodes are null, they are identical at this position.
    if (p == nullptr && q == nullptr) {
        return true;
    }
    // Base Case 2: If one node is null but the other is not, they are not identical.
    if (p == nullptr || q == nullptr) {
        return false;
    }

    // Recursive Step: Check if the current nodes' values are the same,
    // and then recursively check their left and right subtrees.
    bool isIdenticalLeft = isIdentical(p->left, q->left);
    bool isIdenticalRight = isIdentical(p->right, q->right);

    return isIdenticalLeft && isIdenticalRight && (p->val == q->val);
}

/**
 * @brief Checks if a binary tree `subRoot` is a subtree of another binary tree `root`.
 *
 * A subtree of a tree `root` is a tree consisting of a node in `root` and all of its
 * descendants.
 *
 * @param root The main tree.
 * @param subRoot The potential subtree.
 * @return bool True if `subRoot` is a subtree of `root`, false otherwise.
 *
 * ## Overall Approach
 * The function works by traversing the main tree (`root`). At each node of `root`, it
 * performs a check: "Does the subtree starting from this node match `subRoot`?" This
 * check is done by calling the `isIdentical` helper function.
 *
 * If `isIdentical` returns true, we've found our match.
 * If not, the function continues its search by recursively calling itself on the left
 * and right children of the current node in `root`. The `||` (OR) operator ensures
 * that if a match is found in either the left or right branch, the function returns true.
 *
 * ## Time Complexity: O(N * M)
 * In the worst-case scenario, for every node (N) in the main `root` tree, we might have
 * to traverse the entire `subRoot` tree (M nodes) with the `isIdentical` check. This
 * leads to a time complexity of O(N * M).
 *
 * ## Space Complexity: O(H_root + H_subRoot)
 * The space complexity is determined by the maximum depth of the recursion stack. The
 * `isSubtree` calls can go as deep as the height of the `root` tree (H_root), and the
 * `isIdentical` calls can go as deep as the height of the `subRoot` tree (H_subRoot).
 * In the worst case of skewed trees, this can be O(N + M).
 */
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    // Base Case: An empty tree is a subtree of any tree, and no tree is a subtree of an empty tree (except another empty tree).
    if (root == nullptr || subRoot == nullptr) {
        return root == subRoot;
    }

    // Check 1: Is the subtree starting at the *current* `root` node identical to `subRoot`?
    // We check the value first as a quick optimization before the full `isIdentical` call.
    if (root->val == subRoot->val && isIdentical(root, subRoot)) {
        return true;
    }

    // Check 2: If not, is `subRoot` a subtree of `root`'s left child OR `root`'s right child?
    // We recursively search in the left and right branches.
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    // --- Test Case 1: Is a subtree ---
    cout << "Test Case 1: Is a subtree" << endl;
    // root:      [3, 4, 5, 1, 2]
    TreeNode* root1 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    // subRoot:   [4, 1, 2]
    TreeNode* subRoot1 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    cout << "Is it a subtree? " << (isSubtree(root1, subRoot1) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "---" << endl;

    // --- Test Case 2: Not a subtree ---
    cout << "Test Case 2: Not a subtree" << endl;
    // root:      [3, 4, 5, 1, 2, null, null, null, null, 0]
    TreeNode* root2 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)), new TreeNode(5));
    // subRoot:   [4, 1, 2]
    TreeNode* subRoot2 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    cout << "Is it a subtree? " << (isSubtree(root2, subRoot2) ? "Yes" : "No") << endl; // Expected: No
    cout << "---" << endl;

    return 0;
}
