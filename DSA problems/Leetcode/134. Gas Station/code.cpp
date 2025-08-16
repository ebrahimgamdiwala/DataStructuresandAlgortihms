// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>

using namespace std;

/**
 * @brief Finds the starting gas station's index to complete a circular tour.
 *
 * Given two arrays, `gas` and `cost`, where `gas[i]` is the amount of gas at station `i`
 * and `cost[i]` is the cost to travel from station `i` to `i+1`, this function
 * finds the starting station's index from which a car can travel all stations once
 * in a clockwise direction.
 *
 * @param gas A vector of integers representing the gas at each station.
 * @param cost A vector of integers representing the cost to travel to the next station.
 * @return int The index of the starting station, or -1 if no solution exists.
 *
 * ## Overall Approach
 * This function uses a single-pass greedy approach. The logic is based on two key insights:
 * 1.  If the total amount of gas available is less than the total cost to travel, it's
 * impossible to complete the circuit, regardless of the starting point.
 * 2.  If a car starts at station `A` and runs out of gas before reaching station `B`, then
 * no station between `A` and `B` can be a valid starting point either. This is because
 * starting at any of those intermediate stations would mean starting with less gas than
 * when we passed through them from `A`, leading to an even earlier failure.
 *
 * The algorithm iterates through the stations, keeping track of the current gas in the tank
 * (`currGas`). If `currGas` drops below zero, it means the current `start` point is invalid.
 * Based on insight #2, we then set the *next* station (`i + 1`) as the new potential
 * starting point and reset `currGas` to 0.
 *
 * ## Time Complexity: O(N)
 * The algorithm iterates through the `gas` and `cost` arrays exactly once. All operations
 * inside the loop are constant time. Therefore, the time complexity is linear with respect
 * to the number of stations (N).
 *
 * ## Space Complexity: O(1)
 * The algorithm uses only a few variables to store totals and the current state (`totGas`,
 * `totCost`, `start`, `currGas`). The amount of extra memory used is constant and does not
 * depend on the size of the input arrays.
 */
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totGas = 0;  // Total gas available in the circuit.
    int totCost = 0; // Total cost to travel the entire circuit.
    int start = 0;   // The potential starting station index.
    int currGas = 0; // Current gas in the tank for the current journey attempt.

    // Iterate through each station once.
    for (int i = 0; i < gas.size(); i++) {
        // STEP 1: Keep track of the total gas and cost to check for overall feasibility.
        totGas += gas[i];
        totCost += cost[i];

        // STEP 2: Update the current gas in the tank.
        // `gas[i] - cost[i]` is the net gain/loss of gas after visiting station `i`.
        currGas = currGas + (gas[i] - cost[i]);

        // STEP 3: Check if we can proceed.
        // If `currGas` is negative, it means we've run out of gas.
        if (currGas < 0) {
            // This means we cannot complete the journey starting from the current `start`.
            // Based on the greedy logic, the next station is our new best guess.
            start = i + 1;
            // Reset the tank for the new journey attempt.
            currGas = 0;
        }
    }

    // STEP 4: Final check for feasibility.
    // If the total cost is more than the total gas, no solution is possible.
    // Otherwise, the `start` index we found is the guaranteed correct answer.
    return totGas < totCost ? -1 : start;
}

int main() {
    // Test Case 1: A valid solution exists.
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test Case 1:" << endl;
    cout << "Gas: [1,2,3,4,5], Cost: [3,4,5,1,2]" << endl;
    cout << "Starting station index: " << canCompleteCircuit(gas1, cost1) << endl; // Expected: 3
    cout << "---" << endl;

    // Test Case 2: No solution is possible.
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test Case 2:" << endl;
    cout << "Gas: [2,3,4], Cost: [3,4,3]" << endl;
    cout << "Starting station index: " << canCompleteCircuit(gas2, cost2) << endl; // Expected: -1
    cout << "---" << endl;

    return 0;
}
