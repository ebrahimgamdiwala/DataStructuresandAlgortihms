// Required for input/output and the queue data structure.
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node with a 'next' pointer.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/**
 * @brief Populates the 'next' pointer for each node to point to its right sibling.
 *
 * @param root The root of a perfect binary tree.
 * @return Node* The root of the modified tree.
 *
 * ## Overall Approach
 * The function uses a Level-Order Traversal (Breadth-First Search or BFS) to process the tree
 * level by level. A queue is the natural data structure for this.
 *
 * 1.  **Level Delimiter:** A `nullptr` is pushed into the queue to act as a separator between
 * levels. When we encounter a `nullptr` during traversal, we know that the current level
 * has been fully processed.
 * 2.  **Tracking Previous Node:** A `prev` pointer is used to keep track of the previously
 * processed node on the *same level*.
 * 3.  **Connecting Nodes:** As we process each node, we set the `next` pointer of the `prev`
 * node to point to the current node. Since we are moving from left to right, this correctly
 * links the siblings. When a new level starts (after a `nullptr`), `prev` is reset to `nullptr`
 * so the last node of the previous level doesn't incorrectly point to the first node of the
 * current level.
 * 4.  **Queue Management:** For each non-null node we visit, we add its children (if they exist)
 * to the queue for the next level's traversal.
 *
 * This process continues until the queue is empty, at which point all `next` pointers will be
 * correctly populated.
 *
 * ## Time Complexity: O(N)
 * We visit each node in the tree exactly once.
 *
 * ## Space Complexity: O(W) or O(N)
 * The space complexity is determined by the maximum number of nodes in the queue at any given
 * time, which corresponds to the maximum width (W) of the tree. For a perfect binary tree, the
 * last level has N/2 nodes, so the space complexity is O(N).
 */
Node* connect(Node* root) {
    // If the tree is empty or has no children, there's nothing to connect.
    if (root == nullptr || root->left == nullptr) {
        return root;
    }

    // A queue to perform level-order traversal.
    queue<Node*> q;
    q.push(root);
    q.push(nullptr); // Use nullptr as a delimiter for levels.

    // 'prev' will point to the previously processed node on the current level.
    Node* prev = nullptr;

    while (q.size() > 0) {
        // Get the current node from the front of the queue.
        Node* curr = q.front();
        q.pop();

        // Check if we've reached the end of a level.
        if (curr == nullptr) {
            // If the queue is empty after popping a nullptr, we are done.
            if (q.size() == 0) {
                break;
            }
            // Otherwise, push another nullptr to mark the end of the next level.
            q.push(nullptr);
        } else { // This is a regular node.
            // Add its children to the queue for the next level.
            // (The problem statement guarantees a perfect binary tree, so children exist
            // for non-leaf nodes).
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
            // If 'prev' is not null (i.e., this isn't the first node of the level),
            // connect the previous node to the current one.
            if (prev != nullptr) {
                prev->next = curr;
            }
        }
        // Update 'prev' to the current node for the next iteration.
        // If curr is nullptr, prev becomes nullptr, effectively resetting for the new level.
        prev = curr;
    }

    return root;
}

/**
 * @brief Helper function to print the tree levels using the 'next' pointers.
 * @param root The root of the connected tree.
 */
void printLevels(Node* root) {
    if (!root) return;
    Node* levelStart = root;
    while (levelStart) {
        Node* curr = levelStart;
        while (curr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "#" << endl;
        levelStart = levelStart->left;
    }
}

int main() {
    // --- Test Case ---
    // Create a perfect binary tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Connecting nodes..." << endl;
    Node* connectedRoot = connect(root);

    cout << "Printing levels using 'next' pointers:" << endl;
    printLevels(connectedRoot);

    // Expected Output:
    // 1 -> #
    // 2 -> 3 -> #
    // 4 -> 5 -> 6 -> 7 -> #

    return 0;
}
