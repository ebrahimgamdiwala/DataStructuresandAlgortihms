#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle in a linked list using Floyd's Tortoise and Hare algorithm
bool hasCycle(ListNode* head) {
    // Initialize both slow and fast pointers at the head
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast by 2 steps and slow by 1 step
    // If a cycle exists, fast and slow will eventually meet
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;             // Move slow by 1 node
        fast = fast->next->next;       // Move fast by 2 nodes

        if (fast == slow) {
            // Cycle detected
            return true;
        }
    }

    // No cycle found
    return false;
}

/*
Time Complexity:  O(n)
- In the worst case, the fast pointer traverses the entire list.
- If there's a cycle, the two pointers meet in at most O(n) steps.

Space Complexity: O(1)
- Only two pointers are used regardless of the input size.
*/

int main() {
    // Create nodes: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Uncomment the next line to create a cycle: 5 -> 3
    // fifth->next = third;

    // Check if a cycle exists
    bool result = hasCycle(head);

    // Output the result
    cout << "Cycle detected? " << (result ? "Yes" : "No") << endl;

    // If there's a cycle, skip cleanup to avoid infinite loop
    if (!result) {
        // Free allocated memory (only if no cycle)
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
