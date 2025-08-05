#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(1)
int maximumWealth(vector<vector<int>> &accounts)
{
    int m = accounts.size() - 1;
    int n = accounts[0].size() - 1;
    int maxSum = INT_MIN;
    for (int i = 0; i <= m; i++)
    {
        int sum = 0;
        for (int j = 0; j <= n; j++)
        {
            sum += accounts[i][j];
        }
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int main()
{
    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 5, 1}};

    int result = maximumWealth(accounts);
    cout << "Maximum wealth: " << result << endl;

    return 0;
}
