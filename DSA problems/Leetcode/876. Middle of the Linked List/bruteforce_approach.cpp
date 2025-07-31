#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//Time complexity : O(n) Two passes through the linked list are required
// Function to find the middle node
ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    int middle = (count / 2) + 1;
    temp = head;
    for (int i = 1; i < middle; i++) {
        temp = temp->next;
    }
    return temp;
}

// Main function with hardcoded inputs
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Get the middle node
    ListNode* mid = middleNode(head);

    // Output the value of the middle node
    cout << "Middle node value: " << mid->val << endl;

    // Cleanup for the dynamically allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
