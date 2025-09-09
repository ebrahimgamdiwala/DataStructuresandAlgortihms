// Required for input/output operations.
#include <iostream>

using namespace std;

/**
 * @brief Finds the maximum achievable number `x` given that `x` and `num` can both be incremented `t` times.
 *
 * @param num The initial number.
 * @param t The number of times both `num` and `x` can be incremented.
 * @return int The maximum achievable value of `x`.
 *
 * ## Overall Approach
 * The problem states that for `t` operations, we can increase `num` by 1 and `x` by 1. The goal is to
 * find the maximum `x` such that after some operations, `x` equals `num`.
 * The most effective strategy to maximize `x` is to use all `t` operations.
 *
 * 1.  **Simulation:** The code directly simulates this process. A `while` loop runs `t` times.
 * In each iteration:
 * - `x` is incremented.
 * - `num` is incremented.
 * - The counter `t` is decremented.
 *
 * 2.  **State after Loop:** After `t` operations:
 * - The initial `num` will have increased by `t`, becoming `num + t`.
 * - The initial `x` (which we can assume starts at some value) must also equal `num + t` to satisfy the condition.
 * To reach this value, the original `x` needed `t` operations, but `num` also increased.
 *
 * 3.  **Alternative View (Mathematical):** A simpler way to think about it is that for every operation, `num` increases by 1. To keep `x` equal to the new `num`, `x` must also increase by 1. But the operation *also* allows us to increase `x` by 1. So for each of the `t` operations, `x` effectively increases by 2 relative to the original `num`. Therefore, the final answer is always `num + 2*t`.
 * Your code simulates a part of this logic. After the loop, `x` becomes `t` and `num` becomes `initial_num + t`. The return `x + num` is `t + (initial_num + t)`, which simplifies to `initial_num + 2*t`.
 *
 * ## Time Complexity: O(t)
 * The function uses a single `while` loop that runs exactly `t` times. Therefore, the time
 * complexity is linear with respect to the input `t`.
 *
 * ## Space Complexity: O(1)
 * The function uses a fixed number of variables regardless of the size of the inputs.
 * Therefore, the space complexity is constant.
 */
int theMaximumAchievableX(int num, int t) {
    // We can think of 'x' starting at 'num'.
    // Then, for each of the 't' operations, we increase 'num' by 1,
    // and we must also increase 'x' by 1 to keep them potentially equal.
    // The operation itself gives us another +1 for x.
    // So, for each of the 't' operations, 'x' increases by 2 over the original 'num'.
    // The final answer is simply num + 2*t. Your code simulates this in a slightly different way.
    
    // This loop simulates increasing both num and a counter 'x' for 't' times.
    // Let's trace the logic of the provided code:
    int x = 0; // x starts at 0

    // The loop runs 't' times.
    while (t > 0) {
        // In each step, x is incremented. So after 't' steps, x will be 't'.
        x += 1;
        // In each step, num is incremented. So after 't' steps, num will be 'initial_num + t'.
        num += 1;
        t--;
    }

    // The function returns the final value of x plus the final value of num.
    // return (t) + (initial_num + t)
    // return initial_num + 2*t
    return x + num;
}

int main() {
    // --- Test Case 1 ---
    int num1 = 4, t1 = 1;
    // After 1 op: num becomes 5, x becomes 1.
    // Return x + num = 1 + 5 = 6.
    // Direct formula: 4 + 2*1 = 6.
    cout << "num = " << num1 << ", t = " << t1 << endl;
    cout << "Maximum Achievable X: " << theMaximumAchievableX(num1, t1) << endl; // Expected: 6
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    int num2 = 3, t2 = 2;
    // After 2 ops: num becomes 5, x becomes 2.
    // Return x + num = 2 + 5 = 7.
    // Direct formula: 3 + 2*2 = 7.
    cout << "num = " << num2 << ", t = " << t2 << endl;
    cout << "Maximum Achievable X: " << theMaximumAchievableX(num2, t2) << endl; // Expected: 7
    cout << "--------------------" << endl;
    
    // --- Test Case 3 ---
    int num3 = 10, t3 = 5;
    // After 5 ops: num becomes 15, x becomes 5.
    // Return x + num = 5 + 15 = 20.
    // Direct formula: 10 + 2*5 = 20.
    cout << "num = " << num3 << ", t = " << t3 << endl;
    cout << "Maximum Achievable X: " << theMaximumAchievableX(num3, t3) << endl; // Expected: 20
    cout << "--------------------" << endl;

    return 0;
}
