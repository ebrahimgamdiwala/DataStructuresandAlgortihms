#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    // Iteratively reverse the pointers of the list
    while (curr != nullptr) {
        next = curr->next;    // Store next node
        curr->next = prev;    // Reverse current node's pointer
        prev = curr;          // Move prev one step forward
        curr = next;          // Move curr one step forward
    }
    return prev;  // New head of reversed list
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from array
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Hardcoded input list: [1, 2, 3, 4, 5]
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    ListNode* reversed = reverseList(head);

    cout << "Reversed list: ";
    printList(reversed);

    return 0;
}
