// Required for input/output operations and the vector data structure.
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Solves the "Number of Islands" problem using Depth-First Search (DFS).
 */
class Solution {
public:
    /**
     * @brief Performs a Depth-First Search (DFS) to find all parts of a single island.
     * @details This function is the core of the island-finding logic. Starting from a '1' (land),
     * it recursively explores all adjacent (top, right, bottom, left) land cells. It marks
     * each visited land cell to ensure it's not counted again.
     *
     * @param i The current row index.
     * @param j The current column index.
     * @param vis A 2D boolean vector to keep track of visited cells.
     * @param grid The 2D grid of characters representing land ('1') and water ('0').
     * @param n The total number of rows in the grid.
     * @param m The total number of columns in the grid.
     */
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {
        // --- Base Cases for Recursion ---
        // These conditions stop the recursive calls from going out of bounds or processing invalid cells.
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
            return;
        }

        // Mark the current cell as visited to avoid re-processing it.
        vis[i][j] = true;

        // --- Recursive Exploration ---
        // Explore all four adjacent neighbors.
        dfs(i - 1, j, vis, grid, n, m); // top
        dfs(i, j + 1, vis, grid, n, m); // right
        dfs(i + 1, j, vis, grid, n, m); // bottom
        dfs(i, j - 1, vis, grid, n, m); // left
    }

    /**
     * @brief Counts the total number of islands in a 2D grid.
     *
     * @param grid A 2D vector of characters where '1' is land and '0' is water.
     * @return int The total number of distinct islands.
     *
     * ## Overall Approach
     * The function iterates through every cell of the grid. When it finds a piece of land ('1')
     * that hasn't been visited yet, it knows it has discovered a new island. It then increments
     * the island count and launches a DFS from that cell. The DFS explores and marks all
     * connected parts of that island. By the time the DFS is complete, the entire island is
     * marked as 'visited', ensuring that we don't count it again.
     *
     * ## Time Complexity: O(N * M)
     * Where N is the number of rows and M is the number of columns.
     * Although we have nested loops and recursion, each cell in the grid is visited at most
     * twice (once by the main loop and once by the DFS). Therefore, the complexity is linear
     * with respect to the number of cells in the grid.
     *
     * ## Space Complexity: O(N * M)
     * The space complexity is determined by two factors:
     * 1. The `vis` (visited) matrix, which takes O(N * M) space.
     * 2. The recursion stack depth for the DFS. In the worst-case scenario (a long, snake-like
     * island that covers the entire grid), the recursion depth could be up to O(N * M).
     * Therefore, the overall space complexity is O(N * M).
     */
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        if (n == 0) return 0; // Handle empty grid edge case.
        int m = grid[0].size();

        // 'vis' (visited) matrix to keep track of cells we've already processed.
        // Initialized to all 'false'.
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Iterate through each cell of the grid.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If we find a piece of land ('1') that we haven't visited yet...
                if (grid[i][j] == '1' && !vis[i][j]) {
                    // ...it means we've found a new island.
                    // Start a DFS from this cell to find all its connected parts.
                    dfs(i, j, vis, grid, n, m);
                    // Increment the island counter.
                    islands++;
                }
            }
        }

        return islands;
    }
};

int main() {
    Solution sol;

    // --- Test Case 1 ---
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "Grid 1:" << endl;
    cout << "Number of islands: " << sol.numIslands(grid1) << endl; // Expected: 1
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Grid 2:" << endl;
    cout << "Number of islands: " << sol.numIslands(grid2) << endl; // Expected: 3
    cout << "--------------------" << endl;

    return 0;
}
