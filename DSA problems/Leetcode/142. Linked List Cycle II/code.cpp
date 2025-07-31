#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle and return the starting node of the cycle
ListNode* detectCycle(ListNode* head) {
    /*
    Floyd’s Tortoise and Hare algorithm:
    - Time Complexity: O(n)
    - Space Complexity: O(1)
    */

    ListNode* slow = head;
    ListNode* fast = head;
    bool isCycle = false;

    // Step 1: Detect if a cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move slow by 1
        fast = fast->next->next;     // move fast by 2

        if (slow == fast) {
            isCycle = true;
            break;
        }
    }

    // Step 2: If no cycle, return nullptr
    if (!isCycle) {
        return nullptr;
    }

    // Step 3: Find the entry point of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // starting node of the cycle
}

int main() {
    // ----------- Test Case -----------

    // Create nodes
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Link nodes to form a cycle: 1 -> 2 -> 3 -> 4 -> 5
    //                                      ^         |
    //                                      |_________|
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3; // Cycle starts at node 3

    // Run detection
    ListNode* cycleStart = detectCycle(node1);

    // Output result
    if (cycleStart != nullptr) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
