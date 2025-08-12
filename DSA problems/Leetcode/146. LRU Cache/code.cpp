// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the unordered_map (hash map) data structure.
#include <unordered_map>

using namespace std;

/**
 * @class LRUCache
 * @brief A data structure that stores key-value pairs up to a certain capacity.
 * When the capacity is exceeded, it discards the least recently used item.
 *
 * ## Overall Approach
 * This implementation uses two data structures working together to achieve high efficiency:
 * 1.  **A Doubly Linked List:** This is used to maintain the order of usage. The most
 * recently used items are kept at the front (near the `head`), and the least recently
 * used items are at the back (near the `tail`). This allows for O(1) removal of the
 * least recently used item and O(1) insertion at the front.
 * 2.  **An Unordered Map (Hash Map):** This maps each key to its corresponding node in the
 * doubly linked list. This provides O(1) access to any node in the list, which is
 * crucial for quickly moving a node to the front when it's accessed.
 *
 * The `head` and `tail` nodes are "dummy" or "sentinel" nodes. They don't store actual
 * data but simplify the logic for adding and deleting nodes by eliminating edge cases
 * (like an empty list or deleting the head/tail).
 *
 * ## Time Complexity: O(1) for both `get` and `put`
 * All operations (map lookups, insertions, deletions, and list manipulations at the
 * head/tail) are performed in constant time on average.
 *
 * ## Space Complexity: O(capacity)
 * The space used is proportional to the capacity of the cache, as we store up to
 * `capacity` nodes in both the hash map and the doubly linked list.
 */
class LRUCache {
public:
    // Inner class to define the structure of the doubly linked list nodes.
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    // Dummy head and tail nodes to simplify list manipulation.
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Hash map for O(1) access to nodes.
    unordered_map<int, Node*> m;
    // The maximum capacity of the cache.
    int limit;

    /**
     * @brief Helper function to add a new node right after the head.
     * This marks the node as the most recently used.
     * @param newNode The node to be added.
     */
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    /**
     * @brief Helper function to delete a node from its current position in the list.
     * @param oldNode The node to be deleted.
     */
    void deleteNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    /**
     * @brief Constructor to initialize the LRUCache with a given capacity.
     * @param capacity The maximum number of items the cache can hold.
     */
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    /**
     * @brief Retrieves the value for a given key. Marks the item as most recently used.
     * @param key The key of the item to retrieve.
     * @return int The value of the item, or -1 if the key does not exist.
     */
    int get(int key) {
        // If the key is not in the map, it's a cache miss.
        if (m.find(key) == m.end()) {
            return -1;
        }

        // If the key exists, we need to move its node to the front of the list.
        Node* ansNode = m[key];
        int ans = ansNode->val;

        // To move it, we delete it from its current position...
        deleteNode(ansNode);
        // ...and add it back to the front.
        addNode(ansNode);

        // The map entry remains valid as the node pointer hasn't changed.
        return ans;
    }

    /**
     * @brief Inserts or updates a key-value pair. Marks the item as most recently used.
     * If the cache is full, it evicts the least recently used item.
     * @param key The key of the item.
     * @param value The value of the item.
     */
    void put(int key, int value) {
        // If the key already exists, we must first remove the old node.
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
            delete oldNode; // Free the memory of the old node.
        }

        // If the cache is at its capacity...
        if (m.size() == limit) {
            // ...we must evict the least recently used item.
            // This is the node right before the dummy tail.
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode; // Free the memory of the evicted node.
        }

        // Create a new node for the new key-value pair.
        Node* newNode = new Node(key, value);
        // Add it to the front of the list (most recently used).
        addNode(newNode);
        // Add its reference to the map.
        m[key] = newNode;
    }
};

int main() {
    cout << "Initializing LRUCache with capacity 2..." << endl;
    LRUCache* cache = new LRUCache(2);

    cout << "put(1, 1)" << endl;
    cache->put(1, 1);
    cout << "put(2, 2)" << endl;
    cache->put(2, 2);

    cout << "get(1): " << cache->get(1) << endl; // returns 1, makes (1,1) most recent

    cout << "put(3, 3)" << endl; // evicts key 2, cache is {1, 3}
    cache->put(3, 3);

    cout << "get(2): " << cache->get(2) << endl; // returns -1 (not found)

    cout << "put(4, 4)" << endl; // evicts key 1, cache is {3, 4}
    cache->put(4, 4);

    cout << "get(1): " << cache->get(1) << endl; // returns -1 (not found)
    cout << "get(3): " << cache->get(3) << endl; // returns 3
    cout << "get(4): " << cache->get(4) << endl; // returns 4

    delete cache; // Clean up memory
    return 0;
}
