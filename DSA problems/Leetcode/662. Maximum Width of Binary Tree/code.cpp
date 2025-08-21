// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the queue data structure.
#include <queue>
// Required for using the pair data structure.
#include <utility>
// Required for using the max function.
#include <algorithm>

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
 * @brief Calculates the maximum width of a binary tree.
 *
 * The width of one level is defined as the length between the end-nodes (the leftmost
 * and rightmost non-null nodes), where the null nodes between the end-nodes are also
 * counted into the length calculation.
 *
 * @param root A pointer to the root of the tree.
 * @return int The maximum width among all levels.
 *
 * ## Overall Approach
 * The function uses a level-order traversal (using a queue) to process the tree level by
 * level. To calculate the width, it assigns a 0-based index to every node as if it were
 * in a complete binary tree.
 * - If a node has index `i`, its left child will have index `2*i + 1` and its right child
 * will have index `2*i + 2`.
 *
 * The queue stores pairs of `{Node*, index}`. For each level, the width is calculated as
 * `(index of rightmost node) - (index of leftmost node) + 1`. We keep track of the
 * maximum width found across all levels. Using `unsigned long long` for the index is
 * crucial to prevent integer overflow, as the indices can grow very large in deep trees.
 *
 * ## Time Complexity: O(N)
 * The algorithm performs a level-order traversal, visiting every node (N) in the tree
 * exactly once. Therefore, the time complexity is linear.
 *
 * ## Space Complexity: O(W)
 * The space complexity is determined by the maximum number of nodes in the queue at any
 * time, which corresponds to the maximum width (W) of the tree. In the worst case of a
 * complete, balanced tree, the last level can contain roughly N/2 nodes, making the
 * space complexity O(N).
 */
int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // The queue stores pairs of {Node*, 0-based index}.
    // We use `unsigned long long` to prevent index overflow on deep/wide trees.
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    // Standard level-order traversal loop.
    while (!q.empty()) {
        int currLevelSize = q.size();
        // Get the index of the first node (leftmost) at the current level.
        unsigned long long startIndex = q.front().second;
        // The index of the last node (rightmost) at the current level.
        unsigned long long endIndex = q.back().second;
        // Calculate the width of the current level and update the max width.
        maxWidth = max(maxWidth, (int)(endIndex - startIndex + 1));

        // Process all nodes at the current level.
        for (int i = 0; i < currLevelSize; i++) {
            auto curr = q.front();
            q.pop();
            // Enqueue left child with its calculated index.
            if (curr.first->left) {
                q.push({curr.first->left, 2 * curr.second + 1});
            }
            // Enqueue right child with its calculated index.
            if (curr.first->right) {
                q.push({curr.first->right, 2 * curr.second + 2});
            }
        }
    }
    return maxWidth;
}

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         1
    //        / \
    //       3   2
    //      /     \
    //     5       9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);

    cout << "Calculating the maximum width of the binary tree..." << endl;
    cout << "Maximum Width: " << widthOfBinaryTree(root) << endl;
    // Expected Output: 4
    // Explanation:
    // Level 1: [1] -> width 1
    // Level 2: [3, 2] -> width 2
    // Level 3: [5, null, null, 9] -> width 4 (from node 5 to node 9)

    return 0;
}
