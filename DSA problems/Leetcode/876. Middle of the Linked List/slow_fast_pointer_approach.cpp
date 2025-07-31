#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Time complexity : O(n) Only single pass through the linked list is required
// Function to find the middle node using slow and fast pointers
ListNode* middleNode(ListNode* head) {
    // Initialize both slow and fast pointers at the head of the list
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast by 2 steps and slow by 1 step until fast reaches the end
    // When fast reaches the end, slow will be at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;             // Move slow pointer by 1 node
        fast = fast->next->next;       // Move fast pointer by 2 nodes
    }

    // When loop ends, slow points to the middle node
    return slow;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6); // Uncomment for even-length test

    // Find the middle node using the two-pointer technique
    ListNode* mid = middleNode(head);

    // Print the value of the middle node
    cout << "Middle node value: " << mid->val << endl;

    // Free the dynamically allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
