// Required for input/output operations, like printing to the console, and for using vectors.
#include <iostream>
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
 * @brief Recursive helper function to construct the height-balanced BST.
 * @param nums The sorted array of numbers.
 * @param st The starting index of the current sub-array.
 * @param end The ending index of the current sub-array.
 * @return TreeNode* A pointer to the root of the constructed subtree.
 */
TreeNode* helper(vector<int>& nums, int st, int end) {
    // Base Case: If the start index has crossed the end index, it means this
    // sub-array is empty, so we return a null pointer.
    if (st > end) {
        return nullptr;
    }

    // STEP 1: Find the middle element of the current sub-array.
    // This middle element will become the root of the current subtree.
    // This choice ensures that the resulting tree is height-balanced.
    int mid = st + (end - st) / 2; // Avoids potential overflow vs. (st+end)/2
    TreeNode* root = new TreeNode(nums[mid]);

    // STEP 2: Recursively build the left subtree.
    // The left subtree will be formed from the left half of the current sub-array
    // (elements from `st` to `mid - 1`).
    root->left = helper(nums, st, mid - 1);

    // STEP 3: Recursively build the right subtree.
    // The right subtree will be formed from the right half of the current sub-array
    // (elements from `mid + 1` to `end`).
    root->right = helper(nums, mid + 1, end);

    return root;
}

/**
 * @brief Converts a sorted array to a height-balanced Binary Search Tree (BST).
 *
 * @param nums A vector of integers sorted in ascending order.
 * @return TreeNode* A pointer to the root of the newly created BST.
 *
 * ## Overall Approach
 * The function uses a recursive, divide-and-conquer strategy. The core idea is to
 * pick the middle element of the current array (or sub-array) to be the root of the
 * tree (or subtree). This naturally places an equal number of smaller elements to the
 * left and larger elements to the right, which is the key to creating a height-balanced tree.
 * The process is then applied recursively to the left and right halves of the array to
 * build the left and right subtrees.
 *
 * ## Time Complexity: O(N)
 * The algorithm visits every element in the input array exactly once to create one
 * corresponding tree node. Therefore, the time complexity is linear with respect to the
 * number of elements (N).
 *
 * ## Space Complexity: O(log N)
 * The space complexity is determined by the maximum depth of the recursion stack. Because
 * we are always choosing the middle element, the resulting tree is height-balanced. The
 * height of a balanced tree is O(log N), which corresponds to the maximum depth of the
 * recursion.
 */
TreeNode* sortedArrayToBST(vector<int>& nums) {
    // Kick off the recursion with the entire array range.
    return helper(nums, 0, nums.size() - 1);
}

// Helper function to print the tree using preorder traversal for verification.
void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // --- Test Case ---
    vector<int> nums = {-10, -3, 0, 5, 9};

    cout << "Converting sorted array to a height-balanced BST..." << endl;
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    // Expected Output could be: 0 -3 -10 9 5 (or other valid balanced BST preorder)
    cout << endl;

    return 0;
}
