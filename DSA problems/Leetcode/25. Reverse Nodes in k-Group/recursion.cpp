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
 * @brief Reverses nodes of a linked list k at a time.
 *
 * @param head A pointer to the head of the linked list.
 * @param k The size of the group of nodes to be reversed.
 * @return ListNode* A pointer to the head of the modified list.
 *
 * ## Overall Approach
 * The function uses recursion to solve the problem. The main idea is to pass the
 * responsibility of reversing the rest of the list (from the k+1-th node onwards)
 * to a recursive call. Once that recursive call returns the head of the processed
 * tail, we can focus on reversing just the current group of k nodes.
 *
 * The base case for the recursion is when there are fewer than k nodes left in the
 * list, in which case we don't reverse them and just return the list as is.
 *
 * ## Time Complexity: O(N)
 * Although the solution is recursive, each node in the list is visited a constant
 * number of times. The first loop checks for k nodes, and the second loop reverses
 * them. Since we process each group of k nodes once, the total time complexity is
 * linear with respect to the total number of nodes (N).
 *
 * ## Space Complexity: O(N/k)
 * The space complexity is determined by the depth of the recursion stack. Since we
 * make a recursive call for every group of k nodes, the maximum depth of the stack
 * will be N/k. Therefore, the space complexity is O(N/k).
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    // STEP 1: Check if there are at least k nodes left to reverse.
    // We use a temporary pointer `temp` to traverse k nodes without losing
    // our reference to the original head of this segment.
    ListNode* temp = head;
    int count = 0;
    while (count < k) {
        // If `temp` becomes null before we count to k, it means we have
        // fewer than k nodes left. This is our base case.
        if (temp == nullptr) {
            // Return the head of the remaining part of the list without reversing it.
            return head;
        }
        temp = temp->next;
        count++;
    }
    // At this point, `temp` points to the (k+1)-th node, which is the head
    // of the next segment of the list.

    // STEP 2: Recursively call `reverseKGroup` for the rest of the list.
    // The `temp` pointer is now at the beginning of the next group. The recursive
    // call will handle reversing that group and all subsequent groups.
    // `newHead` will be the head of the fully-processed list that comes *after*
    // our current group.
    ListNode* newHead = reverseKGroup(temp, k);

    // STEP 3: Reverse the current group of k nodes.
    // This is a standard linked list reversal loop, but with a twist. Instead of
    // pointing the new tail's `next` to `nullptr`, we will point it to `newHead`
    // (the head of the next reversed group), effectively stitching the list back together.
    ListNode* nextNode;
    temp = head; // Reset temp to the start of the current group.
    count = 0;
    while (count < k) {
        nextNode = temp->next; // Store the next node before we overwrite the pointer.
        temp->next = newHead;  // Point the current node's `next` to the head of the *next* group.
        newHead = temp;        // Move `newHead` back one step.
        temp = nextNode;       // Move to the next node in the original group.
        count++;
    }

    // After the loop, `newHead` will be pointing to the original k-th node,
    // which is now the head of our reversed group.
    return newHead;
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

// The main function serves as the entry point for the program.
int main() {
    // ## Creating a hardcoded linked list for testing ##
    // List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> nullptr
    cout << "Constructing the linked list..." << endl;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    int k = 3;

    cout << "Original List: " << endl;
    printList(head);
    cout << "Reversing in groups of " << k << "..." << endl;

    // Call the reverseKGroup function
    ListNode* reversedHead = reverseKGroup(head, k);

    cout << "Modified List: " << endl;
    printList(reversedHead);
    // Expected output for k=3: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8 -> nullptr

    return 0;
}
