#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Time Complexity: O(n + m)
// where n = length of list1, m = length of list2
// Each node is processed once and added to the merged list.
// Space Complexity: O(1) — done iteratively, no recursion stack.
// Iterative function to merge two sorted linked lists.
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode dummy(0); // Dummy node to simplify code
    ListNode* tail = &dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val <= head2->val) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes
    tail->next = (head1 != nullptr) ? head1 : head2;

    return dummy.next;
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array.
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

    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    ListNode* list1 = createList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    ListNode* list2 = createList(arr2, sizeof(arr2)/sizeof(arr2[0]));

    // Merging lists iteratively
    ListNode* merged = mergeTwoLists(list1, list2);

    // Output the merged list
    cout << "Merged List (Iterative): ";
    printList(merged);

    return 0;
}
