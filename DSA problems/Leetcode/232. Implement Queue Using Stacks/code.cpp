// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>

using namespace std;

/**
 * @class MyQueue
 * @brief Implements a FIFO (First-In, First-Out) queue using two LIFO (Last-In, First-Out) stacks.
 *
 * ## Overall Approach
 * This implementation simulates a queue's behavior using two stacks, `s1` and `s2`. The main
 * idea is to make the `push` operation costly so that `pop` and `peek` operations can be
 * efficient (O(1)). This is often called the "push-heavy" approach.
 *
 * When a new element is pushed, it needs to go to the "back" of the queue. Since stacks
 * only allow adding to the top, we must rearrange the elements. All existing elements
 * from the primary stack (`s1`) are temporarily moved to the secondary stack (`s2`). The new
 * element is then pushed onto `s2`. Finally, all elements from `s2` are moved back to `s1`.
 * This process effectively reverses the order twice, placing the new element at the bottom
 * of `s1` and maintaining the correct FIFO order at the top.
 *
 * ## Time Complexity
 * - `push`: O(N), where N is the number of elements in the queue. This is because all N
 * elements must be popped and pushed between the stacks.
 * - `pop`: O(1), as it only involves a `top` and `pop` from the primary stack.
 * - `peek`: O(1), as it only involves a `top` from the primary stack.
 * - `empty`: O(1).
 *
 * ## Space Complexity: O(N)
 * The space required is proportional to the number of elements (N) stored in the stacks.
 */
class MyQueue {
public:
    // s1 is the primary stack used for storing the queue elements in FIFO order.
    stack<int> s1;
    // s2 is a temporary helper stack used during the push operation.
    stack<int> s2;

    // Constructor for the class.
    MyQueue() {}

    /**
     * @brief Adds an element to the back of the queue.
     * @param x The integer element to be pushed.
     */
    void push(int x) {
        // STEP 1: Move all elements from the primary stack (s1) to the helper stack (s2).
        // This reverses their order.
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // STEP 2: Push the new element onto the helper stack.
        // It is now at the top of s2.
        s2.push(x);

        // STEP 3: Move all elements back from the helper stack to the primary stack.
        // This reverses the order again, placing the new element at the bottom of s1
        // and restoring the original order of the other elements on top of it.
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        // The result is that the oldest element is at the top of s1, as required for a queue.
    }

    /**
     * @brief Removes the element from the front of the queue and returns it.
     * @return int The element that was removed.
     */
    int pop() {
        // Because of our push logic, the front of the queue is at the top of s1.
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    /**
     * @brief Gets the front element of the queue.
     * @return int The front element.
     */
    int peek() {
        // The front of the queue is simply the top element of s1.
        return s1.top();
    }

    /**
     * @brief Checks if the queue is empty.
     * @return bool True if the queue is empty, false otherwise.
     */
    bool empty() {
        return s1.empty();
    }
};

int main() {
    cout << "Initializing MyQueue..." << endl;
    MyQueue* queue = new MyQueue();

    cout << "Pushing 1..." << endl;
    queue->push(1);
    cout << "Pushing 2..." << endl;
    queue->push(2);

    cout << "Front element: " << queue->peek() << endl; // Expected: 1

    cout << "Popping element: " << queue->pop() << endl; // Expected: 1

    cout << "Is queue empty? " << (queue->empty() ? "Yes" : "No") << endl; // Expected: No

    cout << "Front element: " << queue->peek() << endl; // Expected: 2

    delete queue; // Clean up memory

    return 0;
}
// This code implements a queue using two stacks using the push-heavy approach.
