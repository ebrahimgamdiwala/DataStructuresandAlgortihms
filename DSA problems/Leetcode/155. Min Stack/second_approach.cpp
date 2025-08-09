// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>

using namespace std;

/**
 * @class MinStack
 * @brief A space-optimized stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * ## Overall Approach
 * This implementation uses a single stack and a variable `minVal` to track the current minimum.
 * It avoids storing pairs by using a mathematical trick. When a new value is pushed that is
 * smaller than the current `minVal`, we don't push the value itself. Instead, we push a
 * specially calculated "flag" value (`2 * val - minVal`). This flag is always smaller than the
 * new minimum (`val`), signaling that a new minimum was set at this position.
 *
 * When popping, if we encounter a value on the stack that is smaller than `minVal`, we know
 * it's a flag. We can then use the reverse formula (`minVal = 2 * minVal - s.top()`) to
 * restore `minVal` to its previous state. This allows us to track the minimum value history
 * without using extra space for each element.
 *
 * ## Time Complexity: O(1) for all operations
 * - All methods (`push`, `pop`, `top`, `getMin`) involve a few comparisons and arithmetic
 * operations, which are all constant time.
 *
 * ## Space Complexity: O(N)
 * - The space is determined by the number of elements (N) on the stack. This approach is more
 * space-efficient than storing pairs, as it only stores one `long long` per entry and a
 * single extra variable (`minVal`). We use `long long` to prevent overflow when calculating
 * the flag value.
 */
class MinStack {
public:
    // The stack `s` stores values. It uses `long long` to prevent overflow from our formula.
    stack<long long int> s;
    // A variable to track the current minimum value in the stack.
    long long int minVal;

    // Constructor for the class.
    MinStack() {}

    /**
     * @brief Pushes a value onto the stack.
     * @param val The integer value to be pushed.
     */
    void push(int val) {
        if (s.empty()) {
            // If the stack is empty, this is the first element.
            s.push(val);
            minVal = val;
        } else {
            // If the new value is a new minimum...
            if (val < minVal) {
                // ...push the calculated flag value instead of the actual value.
                // This formula (2*val - minVal) creates a value guaranteed to be less than `val`.
                s.push((long long)2 * val - minVal);
                // Update the minimum value.
                minVal = val;
            } else {
                // If the new value is not a new minimum, just push it normally.
                s.push(val);
            }
        }
    }

    /**
     * @brief Removes the element on the top of the stack.
     */
    void pop() {
        // If the value at the top of the stack is less than our current minimum,
        // it means it's a "flag" that marks a point where the minimum changed.
        if (s.top() < minVal) {
            // We must restore the previous minimum value. The reverse formula
            // `2 * minVal - s.top()` correctly calculates the previous minimum.
            minVal = 2 * minVal - s.top();
        }
        // Pop the top element (either the real value or the flag).
        s.pop();
    }

    /**
     * @brief Gets the top element of the stack.
     * @return int The value of the top element.
     */
    int top() {
        // If the value at the top is a "flag" (i.e., less than the current minVal)...
        if (s.top() < minVal) {
            // ...the actual top element is the current `minVal`.
            return minVal;
        }
        // Otherwise, the value at the top is the correct value.
        return s.top();
    }

    /**
     * @brief Retrieves the minimum element in the stack.
     * @return int The minimum value currently in the stack.
     */
    int getMin() {
        return minVal;
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
