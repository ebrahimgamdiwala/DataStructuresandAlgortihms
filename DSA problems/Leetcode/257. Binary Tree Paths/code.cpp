// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the string data structure and to_string function.
#include <string>

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
 * @brief Finds all root-to-leaf paths in a binary tree.
 *
 * ## Overall Approach
 * The solution uses a recursive helper function that performs a depth-first search (DFS)
 * or pre-order traversal on the tree. The helper function maintains the current path
 * from the root to the current node as a string.
 *
 * When the traversal reaches a leaf node (a node with no children), it means a complete
 * root-to-leaf path has been found. This path string is then added to the final answer
 * vector. The function then backtracks and explores other paths.
 *
 * ## Time Complexity: O(N * H)
 * Where N is the number of nodes and H is the height of the tree. The algorithm visits
 * every node once. At each node, string concatenation can take time proportional to the
 * length of the path, which is at most the height of the tree (H). In the worst case of
 * a skewed tree, this can be O(N^2).
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the maximum depth of the recursion stack, which is
 * equal to the height of the tree (H). In the worst case of a skewed tree, this can be O(N).
 * This does not include the space required for the output vector, which could also be
 * up to O(N * H) in the worst case.
 */
class Solution {
public:
    /**
     * @brief Recursive helper function to perform DFS and find paths.
     * @param root The current node in the traversal.
     * @param path The string representing the path from the root to the current node's parent.
     * @param ans A reference to the vector that stores the final path strings.
     */
    void helper(TreeNode* root, string path, vector<string>& ans) {
        // Base Case: If the current node is a leaf node (no left or right child).
        if (root->left == nullptr && root->right == nullptr) {
            // We have found a complete root-to-leaf path. Add it to the answer vector.
            ans.push_back(path);
            return;
        }

        // Recursive Step:
        // If there is a left child, continue the DFS on the left subtree.
        if (root->left) {
            // Append the arrow and the child's value to the path and recurse.
            helper(root->left, path + "->" + to_string(root->left->val), ans);
        }
        // If there is a right child, continue the DFS on the right subtree.
        if (root->right) {
            // Append the arrow and the child's value to the path and recurse.
            helper(root->right, path + "->" + to_string(root->right->val), ans);
        }
    }

    /**
     * @brief The main function to initiate the path-finding process.
     * @param root A pointer to the root of the tree.
     * @return vector<string> A vector of strings, where each string is a root-to-leaf path.
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) {
            return ans;
        }
        // Initialize the path string with the root's value.
        string path = to_string(root->val);
        // Call the helper function to start the recursion.
        helper(root, path, ans);
        return ans;
    }
};

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         1
    //        / \
    //       2   3
    //        \
    //         5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    // Create an instance of our solution class.
    Solution sol;
    cout << "Finding all root-to-leaf paths..." << endl;
    vector<string> paths = sol.binaryTreePaths(root);

    // Print the results.
    cout << "Paths:" << endl;
    for (const string& path : paths) {
        cout << "- " << path << endl;
    }
    // Expected Output:
    // - 1->2->5
    // - 1->3

    return 0;
}
