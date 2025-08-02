#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the Node structure for the linked list.
// It's the same as the class but using 'struct' for simplicity.
struct Node {
    int val;
    Node* next;
    Node* random;

    // Constructor to easily create new nodes.
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/**
 * @brief Creates a deep copy of a linked list with random pointers.
 * * @param head A pointer to the head of the original list.
 * @return Node* A pointer to the head of the newly created copied list.
 */
Node* copyRandomList(Node* head) {
    // If the original list is empty, return NULL immediately.
    if (head == nullptr) {
        return NULL;
    }

    // A hash map to store the mapping from an original node to its copy.
    // Key: Node* (from the original list), Value: Node* (from the new list)
    unordered_map<Node*, Node*> nodeMap;

    // --- First Pass: Create copies of all nodes and link them via 'next' pointer ---
    
    // Create the head of the new list.
    Node* newHead = new Node(head->val);
    nodeMap[head] = newHead; // Map the original head to the new head.

    Node* oldTemp = head->next; // Iterator for the original list.
    Node* newTemp = newHead;    // Iterator for the new list.

    // Loop through the rest of the original list.
    while (oldTemp != nullptr) {
        // Create a copy of the current original node.
        Node* copyNode = new Node(oldTemp->val);
        
        // Map the original node to its new copy.
        nodeMap[oldTemp] = copyNode;

        // Link the previous new node to the current new node.
        newTemp->next = copyNode;
        
        // Move iterators forward.
        newTemp = newTemp->next;
        oldTemp = oldTemp->next;
    }

    // --- Second Pass: Assign the 'random' pointers for the new list ---
    
    // Reset iterators to the start of both lists.
    oldTemp = head;
    newTemp = newHead;

    // Loop through both lists simultaneously.
    while (oldTemp != nullptr) {
        // Find the original node's random pointer (e.g., oldTemp->random).
        // Then, use the map to find the corresponding copied node (nodeMap[oldTemp->random]).
        // Assign this copied node to the new node's random pointer.
        // If oldTemp->random is NULL, map lookup will also result in NULL, which is correct.
        newTemp->random = nodeMap[oldTemp->random];
        
        // Move iterators forward.
        newTemp = newTemp->next;
        oldTemp = oldTemp->next;
    }

    return newHead;
}

// Helper function to print the list for verification.
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Node(val: " << temp->val << ", ";
        if (temp->random) {
            cout << "random: " << temp->random->val << ")\n";
        } else {
            cout << "random: NULL)\n";
        }
        temp = temp->next;
    }
    cout << "---------------------\n";
}

int main() {
    // --- Create a hardcoded linked list for testing ---
    // [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Link 'next' pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Link 'random' pointers
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List:\n";
    printList(n1);

    // --- Call the function to copy the list ---
    Node* copiedHead = copyRandomList(n1);

    cout << "Copied List:\n";
    printList(copiedHead);
    
    // Note: In a real application, you should deallocate the memory
    // for both lists to avoid memory leaks.

    return 0;
}