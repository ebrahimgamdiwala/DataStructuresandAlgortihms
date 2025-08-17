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
 * @brief Checks if two binary trees are structurally identical and have the same node values.
 *
 * @param p A pointer to the root of the first tree.
 * @param q A pointer to the root of the second tree.
 * @return bool True if the trees are the same, false otherwise.
 *
 * ## Overall Approach
 * The function uses a recursive, pre-order traversal approach to compare the two trees.
 * The core idea is that for two trees to be identical, three conditions must be met:
 * 1. Their root nodes must have the same value.
 * 2. Their left subtrees must be identical.
 * 3. Their right subtrees must be identical.
 *
 * The function breaks the problem down by recursively checking the left and right subtrees.
 * The base cases handle the situations where one or both nodes are null, which stops
 * the recursion.
 *
 * ## Time Complexity: O(N)
 * The time complexity is linear with respect to the number of nodes (N) in the smaller
 * of the two trees. In the worst case, we must visit every node in both trees once to
 * confirm they are identical.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the depth of the recursion stack. In the worst
-case
 * scenario of a skewed tree (like a linked list), the height (H) of the tree can be
 * equal to the number of nodes (N), making the space complexity O(N). For a balanced
 * tree, the height is log(N), resulting in O(log N) space complexity.
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
    // BASE CASE 1: If both nodes are null, they are identical at this position.
    if (p == nullptr && q == nullptr) {
        return true;
    }
    // BASE CASE 2: If one node is null but the other is not, they are not identical.
    if (p == nullptr || q == nullptr) {
        return false;
    }

    // RECURSIVE STEP:
    // For the trees to be the same, the current nodes must have the same value,
    // AND their left subtrees must be the same, AND their right subtrees must be the same.

    // 1. Check if the left subtrees are identical.
    bool isSameLeft = isSameTree(p->left, q->left);
    // 2. Check if the right subtrees are identical.
    bool isSameRight = isSameTree(p->right, q->right);
    // 3. Check if the current nodes' values are the same.
    bool isValSame = (p->val == q->val);

    // Return true only if all three conditions are met.
    return isSameLeft && isSameRight && isValSame;
}

int main() {
    // --- Test Case 1: Identical Trees ---
    cout << "Test Case 1: Identical Trees" << endl;
    // Tree p1:  [1, 2, 3]
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // Tree q1:  [1, 2, 3]
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Are trees p1 and q1 the same? " << (isSameTree(p1, q1) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "---" << endl;

    // --- Test Case 2: Different Trees (structure) ---
    cout << "Test Case 2: Different Structure" << endl;
    // Tree p2:  [1, 2]
    TreeNode* p2 = new TreeNode(1, new TreeNode(2), nullptr);
    // Tree q2:  [1, null, 2]
    TreeNode* q2 = new TreeNode(1, nullptr, new TreeNode(2));
    cout << "Are trees p2 and q2 the same? " << (isSameTree(p2, q2) ? "Yes" : "No") << endl; // Expected: No
    cout << "---" << endl;

    // --- Test Case 3: Different Trees (values) ---
    cout << "Test Case 3: Different Values" << endl;
    // Tree p3:  [1, 2, 1]
    TreeNode* p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    // Tree q3:  [1, 1, 2]
    TreeNode* q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    cout << "Are trees p3 and q3 the same? " << (isSameTree(p3, q3) ? "Yes" : "No") << endl; // Expected: No
    cout << "---" << endl;

    return 0;
}
