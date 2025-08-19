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
 * @brief Prints the top view of a binary tree from left to right.
 *
 * The top view of a binary tree is the set of nodes visible when the tree is viewed
 * from the top.
 *
 * @param root A pointer to the root of the binary tree.
 *
 * ## Overall Approach
 * The function uses a level-order traversal (using a queue) to explore the tree from
 * top to bottom. To determine which nodes are visible from the top, it keeps track of
 * the horizontal distance (HD) of each node from the root. The root is at HD = 0, its
 * left child is at HD = -1, right child at HD = +1, and so on.
 *
 * A map is used to store the first node encountered at each unique horizontal distance.
 * Since a level-order traversal explores nodes level by level, the first time we see a
 * node at a particular horizontal distance, it is guaranteed to be the highest one, and
 * thus visible from the top. The `map` automatically keeps the nodes sorted by their
 * horizontal distance, making it easy to print the final view from left to right.
 *
 * ## Time Complexity: O(N log H)
 * Where N is the total number of nodes and H is the horizontal width of the tree.
 * We visit every node once (O(N)). For each node, we might perform an insertion into
 * the map, which takes O(log H) time as the map is ordered by key (the horizontal distance).
 *
 * ## Space Complexity: O(W + H)
 * Where W is the maximum width of the tree at any level (for the queue) and H is the
 * horizontal width of the tree (for the map). In the worst case of a complete binary
 * tree, this can be O(N).
 */
void topViewOfBinaryTree(TreeNode *root) {
    if (root == nullptr) return;

    // The queue stores pairs of {Node*, Horizontal Distance}.
    queue<pair<TreeNode*, int>> q;
    // The map stores pairs of {Horizontal Distance, Node Value}.
    // It will only store the *first* node encountered for each horizontal distance.
    map<int, int> m;

    // Start the level-order traversal with the root node at horizontal distance 0.
    q.push({root, 0});

    while (!q.empty()) {
        // Get the node and its horizontal distance from the front of the queue.
        TreeNode* curr = q.front().first;
        int currHorizontalDist = q.front().second;
        q.pop();

        // **The Core Logic**:
        // If we have not yet recorded a node for this horizontal distance...
        if (m.find(currHorizontalDist) == m.end()) {
            // ...it means this is the highest node at this distance, so we record it.
            m[currHorizontalDist] = curr->val;
        }

        // Enqueue the left child with a decreased horizontal distance.
        if (curr->left != nullptr) {
            q.push({curr->left, currHorizontalDist - 1});
        }
        // Enqueue the right child with an increased horizontal distance.
        if (curr->right != nullptr) {
            q.push({curr->right, currHorizontalDist + 1});
        }
    }

    // The map now contains the top view, sorted by horizontal distance.
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

    cout << "Top view of the binary tree is: ";
    topViewOfBinaryTree(root);
    // Expected Output: 4 2 1 3
    // Explanation:
    // At HD -2: 4 is the only node.
    // At HD -1: 2 is the only node.
    // At HD 0: 1 is seen before 5.
    // At HD 1: 3 is the only node.

    return 0;
}
