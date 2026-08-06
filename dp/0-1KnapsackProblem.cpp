// //Recursion only
// class Solution {
// private:
//     int f(int ind, int W, vector<int> &wt, vector<int> &val) {
//         // Base case: at index 0, take item if weight allows
//         if (ind == 0) {
//             if (wt[0] <= W) return val[0];
//             return 0;
//         }

//         // Option 1: Do not pick the current item
//         int notTake = 0 + f(ind - 1, W, wt, val);

//         // Option 2: Pick current item (if capacity allows)
//         int take = INT_MIN;
//         if (wt[ind] <= W) {
//             take = val[ind] + f(ind - 1, W - wt[ind], wt, val);
//         }

//         return max(take, notTake);
//     }

// public:
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         int n = val.size();
//         return f(n - 1, W, wt, val);
//     }
// };


// //memoization 
// class Solution {
// private:
//     int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
//         // Base case: at index 0, check if remaining capacity can fit item 0
//         if (ind == 0) {
//             if (wt[0] <= W) return val[0];
//             return 0;
//         }

//         // Return cached result if subproblem already solved
//         if (dp[ind][W] != -1) return dp[ind][W];

//         // Option 1: Do not take current item
//         int notTake = 0 + f(ind - 1, W, wt, val, dp);

//         // Option 2: Take current item (if capacity allows)
//         int take = INT_MIN;
//         if (wt[ind] <= W) {
//             take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
//         }

//         return dp[ind][W] = max(take, notTake);
//     }

// public:
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         int n = val.size();
//         // 2D DP table initialized to -1 of size n x (W + 1)
//         vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
//         return f(n - 1, W, wt, val, dp);
//     }
// };



//tabulation 
class Solution {
private:
    int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
        // Base case: at index 0, check if remaining capacity can fit item 0
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        // Return cached result if subproblem already solved
        if (dp[ind][W] != -1) return dp[ind][W];

        // Option 1: Do not take current item
        int notTake = 0 + f(ind - 1, W, wt, val, dp);

        // Option 2: Take current item (if capacity allows)
        int take = INT_MIN;
        if (wt[ind] <= W) {
            take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
        }

        return dp[ind][W] = max(take, notTake);
    }

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        // 2D DP table initialized to -1 of size n x (W + 1)
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        return f(n - 1, W, wt, val, dp);
    }
};



//Space optimize
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W + 1, 0), cur(W + 1, 0);

        // Base case initialization
        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int w = 0; w <= W; w++) {
                int notTake = 0 + prev[w];
                int take = INT_MIN;
                if (wt[ind] <= w) {
                    take = val[ind] + prev[w - wt[ind]];
                }
                cur[w] = max(take, notTake);
            }
            prev = cur;
        }

        return prev[W];
    }
};