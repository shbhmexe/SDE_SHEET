// //Recursion only - tle
// class Solution {
// private:
//     int f(int ind, int T, vector<int>& coins) {
//         if (ind == 0) {
//             return (T % coins[0] == 0);
//         }

//         int notTake = f(ind - 1, T, coins);
        
//         int take = 0;
//         if (coins[ind] <= T) {
//             take = f(ind, T - coins[ind], coins);
//         }

//         return notTake + take;
//     }

// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return f(n - 1, amount, coins);
//     }
// };

//memoization 
// class Solution {
// private:
//     int f(int ind, int T, vector<int>& coins, vector<vector<int>>& dp) {
//         if (ind == 0) {
//             return (T % coins[0] == 0);
//         }

//         if (dp[ind][T] != -1) return dp[ind][T];

//         int notTake = f(ind - 1, T, coins, dp);
        
//         int take = 0;
//         if (coins[ind] <= T) {
//             take = f(ind, T - coins[ind], coins, dp);
//         }

//         return dp[ind][T] = notTake + take;
//     }

// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
//         return f(n - 1, amount, coins, dp);
//     }
// };

//tabulation 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));

        // Base case: for ind = 0, fill row using T % coins[0] == 0
        for (int T = 0; T <= amount; T++) {
            dp[0][T] = (T % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int T = 0; T <= amount; T++) {
                unsigned int notTake = dp[ind - 1][T];
                unsigned int take = 0;
                
                if (coins[ind] <= T) {
                    take = dp[ind][T - coins[ind]];
                }

                dp[ind][T] = notTake + take;
            }
        }

        return dp[n - 1][amount];
    }
};