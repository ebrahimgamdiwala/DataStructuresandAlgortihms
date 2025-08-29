// Required for input/output operations and for INT_MAX.
#include <iostream>
#include <vector>
#include <climits>

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
 * @brief Constructs a Binary Search Tree from a preorder traversal array.
 *
 * ## Overall Approach
 * The algorithm reconstructs the BST in a single pass of the preorder array, achieving O(N)
 * time complexity. It uses a helper function that recursively builds the tree, keeping track
 * of an upper `bound` for the values allowed in the current subtree.
 *
 * A preorder traversal visits `Root -> Left -> Right`. This means the first element is always
 * the root of the current subtree. We can use this property.
 *
 * The key idea is the `bound`. For any node, all values in its left subtree must be less than
 * the node's own value. So, when we recurse left, the new upper `bound` becomes the parent's
 * value. For the right subtree, the values must be greater than the parent's value but still
 * less than the bound set by an ancestor. The `bound` parameter cleverly manages this constraint.
 *
 * ## Time Complexity: O(N)
 * Each element in the preorder array is processed exactly once.
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). In the worst case of a skewed tree, this can be O(N).
 */
class Solution {
public:
    /**
     * @brief Recursive helper to build the BST.
     * @param preorder The preorder traversal array.
     * @param i The current index in the preorder array (passed by reference).
     * @param bound The upper limit for the value of any node in the current subtree.
     * @return TreeNode* The root of the constructed subtree.
     */
    TreeNode* helper(vector<int>& preorder, int& i, int bound) {
        // Base Case: If we've processed all elements, or the current element
        // is greater than the allowed bound, it means this branch has no more nodes.
        if (i >= preorder.size() || preorder[i] > bound) {
            return nullptr;
        }

        // The current element preorder[i] is the root of this subtree.
        TreeNode* root = new TreeNode(preorder[i++]); // Create the node and advance the index.

        // Recursively build the left subtree.
        // The new bound for the left subtree is the current root's value.
        root->left = helper(preorder, i, root->val);

        // Recursively build the right subtree.
        // The bound for the right subtree remains the same as the current bound.
        root->right = helper(preorder, i, bound);

        return root;
    }

    /**
     * @brief Kicks off the BST construction process.
     * @param preorder The preorder traversal of the BST.
     * @return TreeNode* The root of the newly constructed BST.
     */
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; // Start with the first element of the preorder array.
        // The initial bound is INT_MAX, as there is no upper limit for the root.
        return helper(preorder, i, INT_MAX);
    }
};

/**
 * @brief Helper function to print the inorder traversal of a tree (verifies BST correctness).
 * @param root The root of the tree to print.
 */
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // --- Test Case ---
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    cout << "Building BST from preorder traversal: [8, 5, 1, 7, 10, 12]" << endl;

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST (should be sorted): ";
    printInorder(root);
    cout << endl;
    // Expected Output: 1 5 7 8 10 12

    return 0;
}
