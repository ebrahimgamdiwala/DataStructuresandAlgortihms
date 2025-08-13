// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the queue data structure.
#include <queue>

using namespace std;

/**
 * @class MyStack
 * @brief Implements a LIFO (Last-In, First-Out) stack using two FIFO (First-In, First-Out) queues.
 *
 * ## Overall Approach
 * This implementation simulates a stack's behavior using two queues, `q1` and `q2`. The main
 * idea is to make the `push` operation costly so that `pop` and `top` operations can be
 * efficient (O(1)).
 *
 * When a new element is pushed, it needs to become the "top" of the stack. Since queues
 * only allow adding to the back, we must rearrange the elements. All existing elements
 * from the primary queue (`q1`) are temporarily moved to the secondary queue (`q2`). The new
 * element is then added to the now-empty `q1`. Finally, all elements from `q2` are moved
 * back to `q1`, placing them behind the new element. This ensures the most recently pushed
 * item is always at the front of `q1`, mimicking a stack's top.
 *
 * ## Time Complexity
 * - `push`: O(N), where N is the number of elements in the stack. This is because all N
 * elements must be dequeued and enqueued twice.
 * - `pop`: O(1), as it only involves accessing the front of the primary queue.
 * - `top`: O(1), as it also only involves accessing the front of the primary queue.
 * - `empty`: O(1).
 *
 * ## Space Complexity: O(N)
 * The space required is proportional to the number of elements (N) stored in the queues.
 */
class MyStack {
public:
    // q1 is the primary queue used for storing the stack elements.
    queue<int> q1;
    // q2 is a temporary helper queue used during the push operation.
    queue<int> q2;

    // Constructor for the class.
    MyStack() {}

    /**
     * @brief Pushes an element onto the top of the stack.
     * @param x The integer element to be pushed.
     */
    void push(int x) {
        // STEP 1: Move all elements from the primary queue (q1) to the helper queue (q2).
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // STEP 2: Push the new element into the now-empty primary queue.
        // It is now the only element in q1.
        q1.push(x);

        // STEP 3: Move all elements back from the helper queue to the primary queue.
        // They will be enqueued after the new element.
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        // The result is that `x` is at the front of q1, acting as the top of the stack.
    }

    /**
     * @brief Removes the element on the top of the stack and returns it.
     * @return int The element that was popped.
     */
    int pop() {
        // Because of our push logic, the top of the stack is at the front of q1.
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    /**
     * @brief Gets the top element of the stack.
     * @return int The top element.
     */
    int top() {
        // The top of the stack is simply the front element of q1.
        return q1.front();
    }

    /**
     * @brief Checks if the stack is empty.
     * @return bool True if the stack is empty, false otherwise.
     */
    bool empty() {
        return q1.empty();
    }
};

int main() {
    cout << "Initializing MyStack..." << endl;
    MyStack* stack = new MyStack();

    cout << "Pushing 1..." << endl;
    stack->push(1);
    cout << "Pushing 2..." << endl;
    stack->push(2);

    cout << "Top element: " << stack->top() << endl; // Expected: 2

    cout << "Popping element: " << stack->pop() << endl; // Expected: 2

    cout << "Is stack empty? " << (stack->empty() ? "Yes" : "No") << endl; // Expected: No

    cout << "Top element: " << stack->top() << endl; // Expected: 1

    delete stack; // Clean up memory

    return 0;
}
