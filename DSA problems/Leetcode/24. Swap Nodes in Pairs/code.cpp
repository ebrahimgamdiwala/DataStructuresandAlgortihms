#include <iostream>

using namespace std;

// This is the definition for the ListNode structure for a singly linked list.
// Each node contains an integer value and a pointer to the next node in the list.
class ListNode {
public:
    int val;
    ListNode *next;

    // A simple constructor to easily create a new node with a given value.
    // The 'next' pointer is initialized to nullptr by default.
    ListNode(int _val) {
        val = _val;
        next = nullptr;
    }
};

/**
 * @brief Swaps adjacent nodes in a linked list using the provided iterative logic.
 *
 * @param head A pointer to the head of the linked list.
 * @return ListNode* A pointer to the head of the modified list.
 *
 * ## Overall Approach
 * The function uses an iterative approach to swap nodes in pairs. It uses four pointers
 * to keep track of the nodes involved in a swap and to link the list back together:
 * - `prev`: The node just before the current pair. This is needed to link the
 * previously processed part of the list to the newly swapped pair.
 * - `first`: The first node in the current pair (e.g., node 1 in 1->2).
 * - `second`: The second node in the current pair (e.g., node 2 in 1->2).
 * - `next`: The node immediately after the current pair. This is saved so we don't
 * lose the reference to the rest of the list after the swap.
 *
 * The `while` loop continues as long as there is a valid pair (`first` and `second`
 * are not null) to be swapped. The head of the list is updated only once, during the
 * first iteration when `prev` is null.
 *
 * ## Time Complexity: O(N)
 * The time complexity is linear with respect to the number of nodes (N) in the list.
 * We traverse the list once, visiting each node a constant number of times to perform
 * the pointer manipulations for the swap.
 *
 * ## Space Complexity: O(1)
 * The space complexity is constant because we only use a few extra pointers (`prev`,
 * `first`, `second`, `next`) to perform the swaps. The amount of extra memory used
 * does not depend on the size of the input list.
 */
ListNode* swapPairs(ListNode* head) {
    // Base Case: If the list is empty or has only one node, no swaps can be done.
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initialize the four key pointers as per the original logic.
    ListNode* prev = nullptr;
    ListNode* first = head;
    ListNode* second = first->next;
    ListNode* next = second->next; // This holds the start of the *next* pair.

    // Loop as long as there is a complete pair (`first` and `second`) to swap.
    while (first != nullptr && second != nullptr) {

        // STEP 1: Perform the swap by redirecting pointers.
        first->next = next;   // The original first node now points past the second node.
        second->next = first; // The second node now points back to the first.

        // STEP 2: Connect the previous part of the list to this newly swapped pair.
        if (prev != nullptr) {
            // If this is not the first pair, connect the previous segment's tail (`prev`)
            // to the new head of this pair (`second`).
            prev->next = second;
        } else {
            // If this IS the first pair (`prev` is null), then `second` becomes
            // the new head of the entire list. This happens only once.
            head = second;
        }

        // STEP 3: Move the pointers forward to set up for the next iteration.
        // The `first` node of the pair we just swapped is now the `prev` for the next one.
        prev = first;
        // The new `first` is the start of the next pair, which we saved in `next`.
        first = next;

        // STEP 4: Safely update `second` and `next` for the upcoming iteration.
        // This logic explicitly checks for nulls before assigning the next set of pointers.
        if (first != nullptr) {
            // If there's a `first` node for the next pair...
            second = first->next; // ...then `second` is the node after it.
        } else {
            // Otherwise, there's no next pair.
            second = nullptr;
        }

        if (second != nullptr) {
            // If there's a `second` node for the next pair...
            next = second->next; // ...then `next` is the node after it.
        } else {
            // Otherwise, there's no node after the potential next pair.
            next = nullptr;
        }
    }

    // Return the new head of the list.
    return head;
}


/**
 * @brief A helper function to print the values of a linked list.
 * @param head A pointer to the head of the list to be printed.
 */
void printList(ListNode* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // List: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: " << endl;
    printList(head);
    cout << "Swapping nodes in pairs..." << endl;

    // Call the swapPairs function
    ListNode* swappedHead = swapPairs(head);

    cout << "Modified List: " << endl;
    printList(swappedHead);
    // Expected output: 2 -> 1 -> 4 -> 3 -> 5 -> nullptr

    return 0;
}
