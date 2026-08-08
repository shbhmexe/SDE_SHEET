// //Recursion - tle
// class Solution {
// private:
//     int f(int i, int j, vector<vector<int>> &grid) {
//         // Base case 1: Reached top-left starting cell
//         if (i == 0 && j == 0) return grid[0][0];
        
//         // Base case 2: Out of grid bounds
//         if (i < 0 || j < 0) return 1e9; // 1e9 avoids integer overflow when adding grid[i][j]

//         // Moving up and left
//         int up = grid[i][j] + f(i - 1, j, grid);
//         int left = grid[i][j] + f(i, j - 1, grid);

//         return min(up, left);
//     }

// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         return f(n - 1, m - 1, grid);
//     }
// };

// //memoization 
// class Solution {
// private:
//     int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
//         // Base case 1: Reached top-left starting cell
//         if (i == 0 && j == 0) return grid[0][0];
        
//         // Base case 2: Out of grid bounds
//         if (i < 0 || j < 0) return 1e9;

//         // Base case 3: Return memoized answer if already calculated
//         if (dp[i][j] != -1) return dp[i][j];

//         // Moving up and left
//         int up = grid[i][j] + f(i - 1, j, grid, dp);
//         int left = grid[i][j] + f(i, j - 1, grid, dp);

//         return dp[i][j] = min(up, left);
//     }

// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
        
//         return f(n - 1, m - 1, grid, dp);
//     }
// };

//tabulation 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    int up = grid[i][j] + (i > 0 ? dp[i - 1][j] : 1e9);
                    int left = grid[i][j] + (j > 0 ? dp[i][j - 1] : 1e9);
                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};