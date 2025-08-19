// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the queue data structure.
#include <queue>
// Required for using the map data structure (stores key-value pairs in sorted order).
#include <map>
// Required for using the pair data structure.
#include <utility>

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
 * @brief Prints the bottom view of a binary tree from left to right.
 *
 * The bottom view of a binary tree is the set of nodes visible when the tree is viewed
 * from the bottom.
 *
 * @param root A pointer to the root of the binary tree.
 *
 * ## Overall Approach
 * The function uses a level-order traversal (using a queue) to explore the tree from
 * top to bottom. It keeps track of the horizontal distance (HD) of each node from the
 * root (root HD = 0, left child HD = -1, right child HD = +1, etc.).
 *
 * A map is used to store the last node encountered at each unique horizontal distance.
 * Since a level-order traversal explores nodes level by level, if we continuously
 * update the map entry for a given horizontal distance, the final value stored will be
 * from the lowest node at that distance. This is the only change from the "Top View"
 * problem. The `map` automatically keeps the nodes sorted by their horizontal distance,
 * making it easy to print the final view from left to right.
 *
 * ## Time Complexity: O(N log H)
 * Where N is the total number of nodes and H is the horizontal width of the tree.
 * We visit every node once (O(N)). For each node, we perform an insertion/update into
 * the map, which takes O(log H) time as the map is ordered by key (the horizontal distance).
 *
 * ## Space Complexity: O(W + H)
 * Where W is the maximum width of the tree at any level (for the queue) and H is the
 * horizontal width of the tree (for the map). In the worst case of a complete binary
 * tree, this can be O(N).
 */
void bottomViewOfBinaryTree(TreeNode *root) {
    if (root == nullptr) return;

    // The queue stores pairs of {Node*, Horizontal Distance}.
    queue<pair<TreeNode*, int>> q;
    // The map stores pairs of {Horizontal Distance, Node Value}.
    // It will be updated to always hold the *last* node encountered for each HD.
    map<int, int> m;

    // Start the level-order traversal with the root node at horizontal distance 0.
    q.push({root, 0});

    while (!q.empty()) {
        // Get the node and its horizontal distance from the front of the queue.
        TreeNode* curr = q.front().first;
        int currHorizontalDist = q.front().second;
        q.pop();

        // **The Core Logic**:
        // Always update the map with the current node's value for its horizontal distance.
        // Since we traverse level by level, this overwrites previous entries and ensures
        // the final value is the one from the lowest level.
        m[currHorizontalDist] = curr->val;

        // Enqueue the left child with a decreased horizontal distance.
        if (curr->left != nullptr) {
            q.push({curr->left, currHorizontalDist - 1});
        }
        // Enqueue the right child with an increased horizontal distance.
        if (curr->right != nullptr) {
            q.push({curr->right, currHorizontalDist + 1});
        }
    }

    // The map now contains the bottom view, sorted by horizontal distance.
    // Iterate through the map and print the values.
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    // --- Test Case ---
    // Create a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    // Horizontal Distances:
    // 4 -> -2
    // 2 -> -1
    // 1, 5 -> 0
    // 3 -> 1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Bottom view of the binary tree is: ";
    bottomViewOfBinaryTree(root);
    // Expected Output: 4 2 5 3
    // Explanation:
    // At HD -2: 4 is the only node.
    // At HD -1: 2 is the only node.
    // At HD 0: 5 is seen after 1, so it overwrites 1 in the map.
    // At HD 1: 3 is the only node.

    return 0;
}
