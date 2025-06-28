#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int maxProfit = 0, bestBuy = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] > bestBuy) {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main() {
    // Hardcoded stock prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = maxProfit(prices);
    cout << "Maximum profit that can be achieved: " << result << endl;

    return 0;
}
