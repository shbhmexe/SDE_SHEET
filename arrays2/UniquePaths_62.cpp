// recurssion - tle 
// class Solution {
// private:
//     int solve(int i, int j, int m, int n) {
//         // Base case: Reached the destination (bottom-right corner)
//         if (i == m - 1 && j == n - 1) return 1;
        
//         // Base case: Out of grid bounds
//         if (i >= m || j >= n) return 0;

//         // Move down and move right
//         int down = solve(i + 1, j, m, n);
//         int right = solve(i, j + 1, m, n);

//         return down + right;
//     }

// public:
//     int uniquePaths(int m, int n) {
//         return solve(0, 0, m, n);
//     }
// };

//memoization 
// class Solution {
// private:
//     int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
//         // Base case: Reached the destination
//         if (i == m - 1 && j == n - 1) return 1;

//         // Base case: Out of bounds
//         if (i >= m || j >= n) return 0;

//         // Return cached result if already computed
//         if (dp[i][j] != -1) return dp[i][j];

//         // Move down and right, then store the result
//         int down = solve(i + 1, j, m, n, dp);
//         int right = solve(i, j + 1, m, n, dp);

//         return dp[i][j] = down + right;
//     }

// public:
//     int uniquePaths(int m, int n) {
//         // Memoization table initialized to -1
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(0, 0, m, n, dp);
//     }
// };

//tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Base condition: starting cell
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = 0;
                    int left = 0;

                    if (i > 0) up = dp[i - 1][j];
                    if (j > 0) left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};