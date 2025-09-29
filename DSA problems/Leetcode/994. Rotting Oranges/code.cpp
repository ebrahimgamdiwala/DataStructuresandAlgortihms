// Required for input/output, vector, queue, and pair.
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair

using namespace std;

/**
 * @brief Solves the "Rotting Oranges" problem using Breadth-First Search (BFS).
 */
class Solution {
public:
    /**
     * @brief Calculates the minimum time required for all fresh oranges to become rotten.
     *
     * @param grid A 2D vector where 0 is an empty cell, 1 is a fresh orange, and 2 is a rotten orange.
     * @return int The minimum time required, or -1 if some oranges can never become rotten.
     *
     * ## Overall Approach: Multi-Source Breadth-First Search (BFS)
     * This problem can be modeled as finding the shortest path from a set of sources (initially rotten oranges)
     * to all reachable nodes (fresh oranges). BFS is the perfect algorithm for this because it explores the grid
     * layer by layer, where each layer represents one minute of time passing.
     *
     * 1.  **Initialization:** We first identify all initially rotten oranges (value 2) and add them to a queue. These are our "sources." The queue will store the coordinates of an orange and the time it became rotten.
     * 2.  **BFS Traversal:** We process the queue. In each step, we dequeue a rotten orange. We then check its four adjacent neighbors (top, right, bottom, left). If a neighbor is a fresh orange (value 1), it becomes rotten. We then enqueue this newly rotten orange with an incremented timestamp (`time + 1`).
     * 3.  **Tracking Time:** The maximum timestamp encountered during the BFS will be the minimum time required for the rot to reach the farthest fresh orange.
     * 4.  **Final Check:** After the BFS is complete, we must iterate through the grid one last time to ensure no fresh oranges are left. If we find a fresh orange that was never visited, it means it was unreachable, and we should return -1.
     *
     * ## Time Complexity: O(N * M)
     * Where N is the number of rows and M is the number of columns. Each cell is visited at most a constant number of times (during the initial scan, when enqueued/dequeued, and during the final check).
     *
     * ## Space Complexity: O(N * M)
     * In the worst-case scenario (a grid full of oranges), the queue and the visited matrix could both hold up to O(N * M) elements.
     */
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int ans = 0; // This will store the maximum time, which is the answer.

        // A visited matrix to prevent processing the same fresh orange multiple times.
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // The queue for our BFS. It stores a pair: {{row, col}, time}.
        queue<pair<pair<int, int>, int>> q;

        // Step 1: Find all initially rotten oranges and add them as sources to the queue.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true; // Mark rotten oranges as visited from the start.
                }
            }
        }

        // Step 2: Perform the BFS traversal.
        while (q.size() > 0) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            // Update the answer with the maximum time encountered so far.
            ans = max(ans, time);

            // Explore the four adjacent neighbors.
            // Top neighbor
            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }
            // Right neighbor
            if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }
            // Bottom neighbor
            if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }
            // Left neighbor
            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
        }

        // Step 4: Check if any fresh oranges were left untouched.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If we find a fresh orange that was not visited, it's unreachable.
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // --- Test Case 1 ---
    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << "Grid 1:" << endl;
    cout << "Minimum time to rot all oranges: " << sol.orangesRotting(grid1) << endl; // Expected: 4
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    vector<vector<int>> grid2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    cout << "Grid 2:" << endl;
    cout << "Minimum time to rot all oranges: " << sol.orangesRotting(grid2) << endl; // Expected: -1
    cout << "--------------------" << endl;

    // --- Test Case 3 ---
    vector<vector<int>> grid3 = {
        {0, 2}
    };
    cout << "Grid 3:" << endl;
    cout << "Minimum time to rot all oranges: " << sol.orangesRotting(grid3) << endl; // Expected: 0
    cout << "--------------------" << endl;

    return 0;
}
