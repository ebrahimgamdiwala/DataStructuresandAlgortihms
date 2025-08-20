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
 * @brief Searches for a target value in a sub-array of the inorder traversal.
 * @param inorder The inorder traversal vector.
 * @param left The starting index of the search range.
 * @param right The ending index of the search range.
 * @param target The value to find.
 * @return int The index of the target, or -1 if not found.
 */
int search(vector<int>& inorder, int left, int right, int target) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Recursive helper function to construct the binary tree.
 * @param preorder The preorder traversal vector.
 * @param inorder The inorder traversal vector.
 * @param preIdx A reference to the current index in the preorder vector.
 * @param left The starting index of the current inorder sub-array.
 * @param right The ending index of the current inorder sub-array.
 * @return TreeNode* A pointer to the root of the constructed subtree.
 */
TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                 int left, int right) {
    // Base Case: If the current sub-array is invalid, return null.
    if (left > right) {
        return nullptr;
    }

    // STEP 1: The first element in the current preorder sequence is the root of the subtree.
    TreeNode* root = new TreeNode(preorder[preIdx]);

    // STEP 2: Find this root's value in the inorder traversal to determine the
    // left and right subtrees.
    int inIdx = search(inorder, left, right, preorder[preIdx]);

    // STEP 3: Increment the preorder index to process the next element in the next call.
    preIdx++;

    // STEP 4: Recursively build the left and right subtrees.
    // The left subtree consists of elements from the inorder array to the left of `inIdx`.
    root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
    // The right subtree consists of elements from the inorder array to the right of `inIdx`.
    root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

    return root;
}

/**
 * @brief Constructs a binary tree from its preorder and inorder traversal sequences.
 *
 * @param preorder A vector representing the preorder traversal.
 * @param inorder A vector representing the inorder traversal.
 * @return TreeNode* A pointer to the root of the constructed binary tree.
 *
 * ## Overall Approach
 * The algorithm leverages the properties of preorder and inorder traversals:
 * 1.  **Preorder (`Root, Left, Right`):** The first element is always the root of the current tree/subtree.
 * 2.  **Inorder (`Left, Root, Right`):** Once the root is identified (from preorder), all elements
 * to its left in the inorder traversal belong to the left subtree, and all elements to its
 * right belong to the right subtree.
 *
 * The function recursively applies this logic. It takes the first element from preorder as the
 * root, finds it in inorder to split the problem, and then recursively builds the left and
 * right subtrees.
 *
 * ## Time Complexity: O(N^2)
 * The recursive `helper` function is called for each of the N nodes. Inside each call, the
 * `search` function performs a linear scan which can take up to O(N) time. This results in
 * a quadratic time complexity. (Note: This can be optimized to O(N) by pre-computing the
 * indices of the inorder traversal into a hash map).
 *
 * ## Space Complexity: O(H)
 * The space complexity is determined by the depth of the recursion stack. In the worst
 * case of a skewed tree, the height (H) can be equal to the number of nodes (N), making
 * the space complexity O(N). For a balanced tree, it's O(log N).
 */
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // `preIdx` keeps track of the current root in the preorder traversal.
    // It is passed by reference to be shared across recursive calls.
    int preIdx = 0;
    return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
}

// Helper function to print the tree using inorder traversal for verification.
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// The main function serves as the entry point for the program.
int main() {
    // --- Test Case ---
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    cout << "Building tree from preorder and inorder traversals..." << endl;
    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root); // Should match the original inorder traversal: 9 3 15 20 7
    cout << endl;

    return 0;
}
