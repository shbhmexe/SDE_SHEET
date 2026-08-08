// //BRUTE FROCE - TLE (generatee all subsequences)
// class Solution {
// private:
//     bool solve(int ind, int currentSum, int target, vector<int>& arr) {
//         if (currentSum == target) return true;
//         if (ind == arr.size() || currentSum > target) return false;

//         // Choice 1: Include current element in the subset
//         bool take = solve(ind + 1, currentSum + arr[ind], target, arr);
        
//         // Choice 2: Exclude current element from the subset
//         bool notTake = solve(ind + 1, currentSum, target, arr);

//         return take || notTake;
//     }

// public:
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         return solve(0, 0, sum, arr);
//     }
// };

//recursion 
// class Solution {
// private:
//     bool f(int ind, int target, vector<int>& arr) {
//         if (target == 0) return true;
//         if (ind == 0) return (arr[0] == target);

//         bool notTake = f(ind - 1, target, arr);
        
//         bool take = false;
//         if (target >= arr[ind]) {
//             take = f(ind - 1, target - arr[ind], arr);
//         }

//         return take || notTake;
//     }

// public:
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         int n = arr.size();
//         return f(n - 1, sum, arr);
//     }
// };

// //memomization 
// class Solution {
// private:
//     bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
//         if (target == 0) return true;
//         if (ind == 0) return (arr[0] == target);

//         if (dp[ind][target] != -1) return dp[ind][target];

//         bool notTake = f(ind - 1, target, arr, dp);
        
//         bool take = false;
//         if (target >= arr[ind]) {
//             take = f(ind - 1, target - arr[ind], arr, dp);
//         }

//         return dp[ind][target] = (take || notTake);
//     }

// public:
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         int n = arr.size();
//         // dp[n][sum + 1] initialized with -1
//         // (0 = false, 1 = true, -1 = unvisited)
//         vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
//         return f(n - 1, sum, arr, dp);
//     }
// };


//tabulatiom
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case 1: target = 0 is always true
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case 2: ind = 0, target = arr[0]
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = dp[ind - 1][target];
                
                bool take = false;
                if (target >= arr[ind]) {
                    take = dp[ind - 1][target - arr[ind]];
                }

                dp[ind][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }
};
