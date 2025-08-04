#include <iostream> // Necessary for input/output operations, like printing to the console.

// standard library components with `std::` (e.g., `std::cout`).
using namespace std;

// This is the definition for the Node structure.
// A multilevel doubly linked list has nodes that, in addition to 'next' and 'prev' pointers,
// also have a 'child' pointer that can point to the head of another doubly linked list.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    // Constructor to easily create a new node.
    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

/**
 * @brief Flattens a multilevel doubly linked list into a single-level doubly linked list.
 * * @param head A pointer to the head of the multilevel list.
 * @return Node* A pointer to the head of the flattened list.
 * * ## Overall Approach
 * The function works by traversing the list level by level, similar to a pre-order traversal
 * or Depth First Search (DFS) on a tree. When it encounters a node with a child, it recursively
 * flattens the child list first. Then, it "splices" this flattened child list into the main list.
 * It carefully cuts the main list, inserts the child list, and then reconnects everything.
 * * ## Time Complexity: O(N)
 * The time complexity is linear with respect to the total number of nodes (N) in the entire
 * structure (across all levels). Although there are nested loops and recursion, each node is
 * visited and processed a constant number of times. The main `while` loop iterates through the
 * nodes, and the recursive calls handle the child levels. Every pointer (`next`, `prev`, `child`)
 * is adjusted at most once. Therefore, the total work is proportional to the total number of nodes.
 * * ## Space Complexity: O(D)
 * The space complexity is determined by the depth of the recursion stack. In the worst-case scenario,
 * the list is structured like a vertical "stick," where each node has a child but no `next` node.
 * In this case, the recursion depth would be equal to the total number of nodes, N.
 * So, the space complexity is O(D), where D is the maximum depth of the child levels, which can be
 * O(N) in the worst case.
 */
Node* flatten(Node* head) {
    // Base Case / Edge Case: If the list is empty, there's nothing to do.
    if (head == nullptr) {
        return nullptr;
    }

    // `curr` is our main iterator, starting from the head of the current list/sub-list.
    Node* curr = head;
    
    // We traverse the main list until we reach the end.
    while (curr != nullptr) {
        
        // The core logic triggers if the current node has a child list.
        if (curr->child != nullptr) {
            
            // STEP 1: Store the next node in the main list.
            // We need to save the rest of the list so we can attach it later.
            // Let's call it `restOfList`.
            Node* restOfList = curr->next;

            // STEP 2: Perform the recursive call to flatten the child list.
            // The `flatten` function will return the head of the now-flattened child sub-list.
            // We then set this flattened sub-list as the `next` of our current node.
            curr->next = flatten(curr->child);
            
            // STEP 3: Connect the flattened sub-list back to `curr`.
            // The new `curr->next` (which is the head of the sub-list) should have its `prev`
            // pointer pointing back to `curr`.
            curr->next->prev = curr;
            
            // STEP 4: Remove the child pointer as it's no longer needed.
            // The child list has been merged into the main list.
            curr->child = nullptr;

            // STEP 5: Find the tail of the newly inserted sub-list.
            // We need to traverse to the end of this sub-list so we can connect
            // it to the `restOfList` we saved in Step 1.
            Node* tailOfSubList = curr;
            while (tailOfSubList->next != nullptr) {
                tailOfSubList = tailOfSubList->next;
            }

            // STEP 6: Connect the tail of the sub-list to the rest of the main list.
            // If `restOfList` is not null (i.e., `curr` was not the last node in its original list),
            // we perform the connection.
            if (restOfList != nullptr) {
                tailOfSubList->next = restOfList; // Tail's next points to the rest of the list.
                restOfList->prev = tailOfSubList; // Rest of the list's prev points back to the tail.
            }

            // After all this splicing, `curr` is now at the tail of the sub-list. The loop's
            // final statement `curr = curr->next` will correctly move it to `restOfList` to
            // continue the traversal of the main list.
        }
        
        // Move to the next node in the list to continue the traversal.
        curr = curr->next;
    }
    
    // Return the head of the now completely flattened list.
    return head;
}

/**
 * @brief A helper function to print the values of a flattened doubly linked list.
 * It traverses from head to tail using the `next` pointer.
 * @param head A pointer to the head of the list to print.
 */
void printList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Flattened List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // ## Creating a hardcoded multilevel doubly linked list ##
    // This structure will look like:
    // 1---2---3---4---5---6--NULL
    //         |
    //         7---8---9---10--NULL
    //             |
    //             11--12--NULL

    // Level 1
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    
    // Level 2
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    
    // Level 3
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    // Connect Level 1 nodes
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Connect Level 2 nodes
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    // Connect Level 3 nodes
    n11->next = n12; n12->prev = n11;

    // Create the child connections
    n3->child = n7;
    n8->child = n11;
    
    // Call the flatten function with the head of our created list
    Node* flattenedHead = flatten(n1);

    // Print the result to verify it's correct
    // Expected output: 1 <-> 2 <-> 3 <-> 7 <-> 8 <-> 11 <-> 12 <-> 9 <-> 10 <-> 4 <-> 5 <-> 6 <-> nullptr
    printList(flattenedHead);

    return 0;
}