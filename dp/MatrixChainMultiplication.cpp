// //Recurssion - tle 
// class Solution {
// private:
//     int f(int i, int j, vector<int> &arr) {
//         if (i == j) return 0;
        
//         int mini = 1e9;
//         for (int k = i; k < j; k++) {
//             int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr);
//             if (steps < mini) mini = steps;
//         }
        
//         return mini;
//     }

// public:
//     int matrixMultiplication(vector<int> &arr) {
//         int N = arr.size();
//         return f(1, N - 1, arr);
//     }
// };

//memoization 
// class Solution {
// private:
//     int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
//         if (i == j) return 0;
        
//         if (dp[i][j] != -1) return dp[i][j];
        
//         int mini = 1e9;
//         for (int k = i; k < j; k++) {
//             int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
//             if (steps < mini) mini = steps;
//         }
        
//         return dp[i][j] = mini;
//     }

// public:
//     int matrixMultiplication(vector<int> &arr) {
//         int N = arr.size();
//         vector<vector<int>> dp(N, vector<int>(N, -1));
        
//         return f(1, N - 1, arr, dp);
//     }
// };



//tabulation
class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        // Base case: dp[i][i] = 0 (implicitly handled by initialization to 0)

        for (int i = N - 1; i >= 1; i--) {
            for (int j = i + 1; j < N; j++) {
                int mini = 1e9;
                
                for (int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    if (steps < mini) mini = steps;
                }
                
                dp[i][j] = mini;
            }
        }

        return dp[1][N - 1];
    }
};