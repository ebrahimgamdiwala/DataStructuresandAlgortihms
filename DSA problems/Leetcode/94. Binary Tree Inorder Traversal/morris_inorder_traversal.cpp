// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>

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
 * @brief Performs an inorder traversal of a binary tree using the Morris Traversal algorithm.
 *
 * @param root A pointer to the root of the tree.
 * @return vector<int> A vector containing the inorder traversal of the tree's values.
 *
 * ## Overall Approach
 * Morris Traversal is an advanced iterative technique that performs an inorder traversal
 * without using recursion or an explicit stack, achieving O(1) space complexity. It works
 * by temporarily modifying the tree structure to create "threads" or links.
 *
 * For each node `curr`, it finds its inorder predecessor (the rightmost node in its left
 * subtree). It then creates a temporary link from this predecessor back to `curr`. This
 * thread allows the traversal to return to `curr` after visiting the entire left subtree,
 * simulating the backtracking of a recursive call. The algorithm carefully creates and
 * later removes these threads to restore the tree to its original structure.
 *
 * ## Time Complexity: O(N)
 * Although there is a nested `while` loop, the time complexity is linear. Each node is
 * visited, and each edge is traversed a constant number of times (at most twice, once
 * to create the thread and once to remove it). Therefore, the total work is proportional
 * to the number of nodes (N).
 *
 * ## Space Complexity: O(1)
 * This is the main advantage of Morris Traversal. It does not use a recursion stack or an
 * explicit stack for traversal. The only extra space used is for a few pointers, making
 * the space complexity constant. (This excludes the space for the output vector).
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    while (curr != nullptr) {
        // CASE 1: The current node has no left child.
        if (curr->left == nullptr) {
            // This means we can visit this node.
            ans.push_back(curr->val);
            // Then, move to the right child.
            curr = curr->right;
        }
        // CASE 2: The current node has a left child.
        else {
            // Find the inorder predecessor of the current node.
            // This is the rightmost node in the left subtree.
            TreeNode* IP = curr->left;
            while (IP->right != nullptr && IP->right != curr) {
                IP = IP->right;
            }

            // After the loop, `IP` is the inorder predecessor.
            if (IP->right == nullptr) {
                // If the predecessor's right child is null, we create the thread.
                // This temporary link points from the predecessor back to the current node.
                IP->right = curr;
                // Move to the left to continue exploring the left subtree.
                curr = curr->left;
            } else {
                // If the predecessor's right child already points to `curr`, it means
                // we have already visited the entire left subtree.
                // It's time to break the thread to restore the tree's original structure.
                IP->right = nullptr;
                // Now that the left subtree is done, we can visit the current node.
                ans.push_back(curr->val);
                // Finally, move to the right subtree.
                curr = curr->right;
            }
        }
    }

    return ans;
}

/**
 * @brief A helper function to print the elements of a vector.
 * @param vec The vector to be printed.
 */
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? " " : ", ");
    }
    cout << "]" << endl;
}

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         4
    //        / \
    //       2   5
    //      / \
    //     1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Performing Morris Inorder Traversal..." << endl;
    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal Result: ";
    printVector(result);
    // Expected Output: [ 1, 2, 3, 4, 5 ]

    return 0;
}
