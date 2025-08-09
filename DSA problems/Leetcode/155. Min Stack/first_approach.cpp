// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>
// Required for using the pair data structure.
#include <utility>
// Required for using the min function.
#include <algorithm>

using namespace std;

/**
 * @class MinStack
 * @brief A stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * ## Overall Approach
 * The core idea is to use a single stack that stores not just the values, but pairs of
 * `{value, current_minimum}`. For every element pushed onto the stack, we also store
 * what the minimum element in the entire stack was *at that moment*.
 *
 * - When we push a new value `val`, the new minimum is `min(val, s.top().second)`.
 * This means the `second` element of the pair always tracks the minimum value up to that point.
 * - This design allows `getMin()` to be extremely efficient, as the current overall minimum
 * is always available right at the top of the stack, without needing to search for it.
 *
 * ## Time Complexity: O(1) for all operations
 * - `push`: Involves a `min` comparison and a `push` to the underlying stack, both are O(1).
 * - `pop`: Involves a `pop` from the underlying stack, which is O(1).
 * - `top`: Involves a `top` call on the underlying stack, which is O(1).
 * - `getMin`: Involves a `top` call on the underlying stack, which is O(1).
 *
 * ## Space Complexity: O(N)
 * The space complexity is linear with respect to the number of elements (N) pushed onto
 * the stack. We store one pair `{value, current_minimum}` for each element, so the space
 * usage is twice that of a standard stack, but still proportional to N.
 */
class MinStack {
public:
    // The stack `s` stores pairs of integers.
    // The first element of the pair is the actual value pushed by the user.
    // The second element is the minimum value in the stack *at the time of the push*.
    stack<pair<int, int>> s;

    // Constructor for the class. It doesn't need to do anything,
    // as the stack is already initialized automatically.
    MinStack() {
    }
    
    /**
     * @brief Pushes a value onto the stack.
     * @param val The integer value to be pushed.
     */
    void push(int val) {
        // Check if the stack is empty.
        if (s.empty()) {
            // If it's the first element, it is both the value and the minimum value.
            s.push({val, val});
        } else {
            // If the stack is not empty, calculate the new minimum.
            // The new minimum is the smaller of the new value and the previous minimum.
            // The previous minimum is stored in the `second` part of the pair at the top of the stack.
            int minVal = min(val, s.top().second);
            // Push the new value and the newly calculated minimum onto the stack.
            s.push({val, minVal});
        }
    }
    
    /**
     * @brief Removes the element on the top of the stack.
     */
    void pop() {
        // Simply pop the top element from the underlying stack.
        // We assume this function is not called on an empty stack, as per standard stack behavior.
        s.pop();
    }
    
    /**
     * @brief Gets the top element of the stack.
     * @return int The value of the top element.
     */
    int top() {
        // The actual value is the `first` element of the pair at the top of the stack.
        return s.top().first;
    }
    
    /**
     * @brief Retrieves the minimum element in the stack.
     * @return int The minimum value currently in the stack.
     */
    int getMin() {
        // The current minimum is always stored as the `second` element of the pair
        // at the top of the stack. This allows for O(1) retrieval.
        return s.top().second;
    }
};

int main() {
    cout << "Initializing MinStack..." << endl;
    MinStack* minStack = new MinStack();

    cout << "Pushing -2..." << endl;
    minStack->push(-2);
    cout << "Pushing 0..." << endl;
    minStack->push(0);
    cout << "Pushing -3..." << endl;
    minStack->push(-3);

    cout << "Current Min: " << minStack->getMin() << endl; // Expected: -3
    cout << "Current Top: " << minStack->top() << endl;   // Expected: -3

    cout << "Popping..." << endl;
    minStack->pop();

    cout << "Current Top: " << minStack->top() << endl;   // Expected: 0
    cout << "Current Min: " << minStack->getMin() << endl; // Expected: -2

    // Clean up the dynamically allocated object.
    delete minStack;

    return 0;
}
