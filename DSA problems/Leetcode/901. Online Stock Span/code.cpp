// Required for input/output operations, printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>
// Required for using the pair data structure.
#include <utility>
// Required for using a vector to hold the hardcoded prices.
#include <vector>

using namespace std;

/**
 * @class StockSpanner
 * @brief Calculates the span of a stock's price for each day.
 *
 * The span of the stock's price today is defined as the maximum number of
 * consecutive days (starting from today and going backward) for which the
 * price of the stock was less than or equal to today's price.
 *
 * ## Overall Approach
 * This class uses a monotonic stack to efficiently calculate the span. A monotonic
 * stack is a stack where the elements are always in a sorted order (in this case,
 * decreasing).
 *
 * The stack stores pairs: `{span, price}`.
 * - `price`: The price of a stock on a previous day.
 * - `span`: The calculated span for that previous day's price.
 *
 * When a new price comes in, we pop elements from the stack as long as their
 * price is less than or equal to the current price. While popping, we accumulate
 * their spans. This is because if the current day's price is greater than a
 * previous day's, its span will "absorb" the span of that previous day.
 *
 * ## Time Complexity: O(1) Amortized
 * While the `while` loop inside the `next` method can run multiple times for a
 * single call, each element (price) is pushed onto the stack exactly once and
 * popped from the stack exactly once across all calls to `next()`. Therefore,
 * the total work is proportional to the number of calls, N. This results in an
 * amortized (or average) time complexity of O(1) per call.
 *
 * ## Space Complexity: O(N)
 * In the worst-case scenario (a strictly decreasing sequence of prices like
 * 100, 90, 80...), no elements are ever popped from the stack. The stack will
 * grow to hold an entry for every price. Therefore, the space complexity is O(N),
 * where N is the number of calls to `next()`.
 */
class StockSpanner {
    // A stack to store pairs of {calculated_span, price}.
    // It's a member variable, so it persists across multiple calls to next().
    stack<pair<int, int>> st;

public:
    // Constructor for the class. It doesn't need to do anything,
    // as the stack is already initialized automatically.
    StockSpanner() {
    }

    /**
     * @brief Calculates the span for a new given price.
     * @param price The stock price for the current day.
     * @return int The calculated span for the current price.
     */
    int next(int price) {
        // STEP 1: Initialize the span for the current day to 1 (for the day itself).
        int span = 1;

        // STEP 2: Process previous days' prices from the stack.
        // We look at the top of the stack. As long as the stack is not empty AND
        // the price at the top of the stack is less than or equal to the current price...
        while (!st.empty() && st.top().second <= price) {
            // ...we add its stored span to our current span.
            // This is because the current day's price streak continues over
            // the streak of that previous, smaller price.
            span += st.top().first;
            // And since we've now "absorbed" that previous day's span,
            // we pop it from the stack.
            st.pop();
        }

        // STEP 3: Push the current price and its calculated total span onto the stack.
        // This prepares the stack for future calls.
        st.push({span, price});

        // STEP 4: Return the calculated span for the current day.
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// The main function serves as the entry point for the program.
int main() {
    cout << "Initializing StockSpanner..." << endl;
    // Create an instance of the StockSpanner class.
    StockSpanner* stockSpanner = new StockSpanner();

    // Create a hardcoded list of stock prices to test the spanner.
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    cout << "Processing stock prices:" << endl;

    // Loop through each price, call the next() method, and print the result.
    for (int price : prices) {
        int span = stockSpanner->next(price);
        cout << "Price: " << price << ", Span: " << span << endl;
    }
    // Expected output:
    // Price: 100, Span: 1
    // Price: 80, Span: 1
    // Price: 60, Span: 1
    // Price: 70, Span: 2  (for 70 and 60)
    // Price: 60, Span: 1
    // Price: 75, Span: 4  (for 75, 60, 70, 60)
    // Price: 85, Span: 6  (for 85, 75, 60, 70, 60, 80)

    // Clean up the dynamically allocated object.
    delete stockSpanner;

    return 0;
}
