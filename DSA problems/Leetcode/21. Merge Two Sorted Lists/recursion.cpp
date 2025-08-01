#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive function to merge two sorted linked lists.
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return head1 == nullptr ? head2 : head1;
    }
    if (head1->val <= head2->val) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
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

    // Merging lists
    ListNode* merged = mergeTwoLists(list1, list2);

    // Output the merged list
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
