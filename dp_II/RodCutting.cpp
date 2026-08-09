// recursion - tle 
// class Solution {
// private:
//     int f(int ind, int N, vector<int>& price) {
//         if (ind == 0) {
//             return N * price[0];
//         }

//         int notTake = 0 + f(ind - 1, N, price);

//         int take = INT_MIN;
//         int rodLength = ind + 1;
//         if (rodLength <= N) {
//             take = price[ind] + f(ind, N - rodLength, price);
//         }

//         return max(take, notTake);
//     }

// public:
//     int cutRod(vector<int> &price) {
//         int n = price.size();
//         return f(n - 1, n, price);
//     }
// };

// //memo 
// class Solution {
// private:
//     int f(int ind, int N, vector<int>& price, vector<vector<int>>& dp) {
//         if (ind == 0) {
//             return N * price[0];
//         }

//         if (dp[ind][N] != -1) return dp[ind][N];

//         int notTake = 0 + f(ind - 1, N, price, dp);

//         int take = INT_MIN;
//         int rodLength = ind + 1;
//         if (rodLength <= N) {
//             take = price[ind] + f(ind, N - rodLength, price, dp);
//         }

//         return dp[ind][N] = max(take, notTake);
//     }

// public:
//     int cutRod(vector<int> &price) {
//         int n = price.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return f(n - 1, n, price, dp);
//     }
// };


//tabulation 
class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: for ind = 0, taking piece of length 1 as many times as possible
        for (int N = 0; N <= n; N++) {
            dp[0][N] = N * price[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int N = 0; N <= n; N++) {
                int notTake = dp[ind - 1][N];

                int take = INT_MIN;
                int rodLength = ind + 1;
                if (rodLength <= N) {
                    take = price[ind] + dp[ind][N - rodLength];
                }

                dp[ind][N] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};