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
 * @brief Finds the lowest common ancestor (LCA) of two given nodes in a binary tree.
 *
 * The lowest common ancestor is defined between two nodes `p` and `q` as the lowest
 * node in the tree that has both `p` and `q` as descendants.
 *
 * @param root A pointer to the root of the tree/subtree.
 * @param p A pointer to the first node.
 * @param q A pointer to the second node.
 * @return TreeNode* A pointer to the lowest common ancestor node.
 *
 * ## Overall Approach
 * This function uses a post-order traversal-style recursion. The core idea is that the
 * function returns a meaningful value from the bottom up. A call to `lowestCommonAncestor`
 * on a subtree will return:
 * - A pointer to `p` or `q` if one of them is found in the subtree.
 * - A pointer to the LCA if it exists within the subtree.
 * - `nullptr` if neither `p` nor `q` is found in the subtree.
 *
 * The key insight is when a node receives non-null return values from *both* its left
 * and right recursive calls. This means `p` was found in one subtree and `q` was found
 * in the other, making the current node the lowest common ancestor.
 *
 * ## Time Complexity: O(N)
 * The algorithm traverses each node in the tree at most once, resulting in a time
 * complexity that is linear with respect to the number of nodes (N).
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack. In the
 * worst case of a skewed tree, the height (H) can be equal to the number of nodes (N),
 * making the space complexity O(N). For a balanced tree, it's O(log N).
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base Case 1: If we've reached the end of a branch, return null.
    if (root == nullptr) {
        return nullptr;
    }
    // Base Case 2: If the current node is one of the nodes we're looking for (`p` or `q`),
    // then this node is a potential ancestor. We return it up the call stack.
    if (root->val == p->val || root->val == q->val) {
        return root;
    }

    // Recursive Step: Search for p and q in the left and right subtrees.
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    // **The Core Logic**: Analyze the results from the children.
    // If both `leftLCA` and `rightLCA` are non-null, it means `p` was found in one
    // subtree and `q` was found in the other. Therefore, the current `root` is
    // their lowest common ancestor.
    if (leftLCA && rightLCA) {
        return root;
    }
    // If only the left subtree returned a non-null value, it means either the LCA
    // is in the left subtree, or one of the nodes (`p` or `q`) was found there.
    // In either case, we pass this value up.
    else if (leftLCA != nullptr) {
        return leftLCA;
    }
    // Otherwise, we pass up the result from the right subtree.
    else {
        return rightLCA;
    }
}

int main() {
    // --- Test Case ---
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Define the nodes we want to find the LCA for.
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1
    cout << "Finding LCA for nodes " << p->val << " and " << q->val << "..." << endl;
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA is: " << lca->val << endl; // Expected: 3
    cout << "---" << endl;

    // Another test case where one node is an ancestor of the other.
    p = root->left; // Node with value 5
    q = root->left->right->right; // Node with value 4
    cout << "Finding LCA for nodes " << p->val << " and " << q->val << "..." << endl;
    lca = lowestCommonAncestor(root, p, q);
    cout << "LCA is: " << lca->val << endl; // Expected: 5
    cout << "---" << endl;

    return 0;
}
