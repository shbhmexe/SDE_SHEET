// //Brute force - tle 
// class Solution {
// private:
//     int maxLen = 0;

//     // Helper function to check if a subsequence is strictly increasing
//     bool isIncreasing(const vector<int>& sub) {
//         for (int i = 1; i < sub.size(); i++) {
//             if (sub[i] <= sub[i - 1]) return false;
//         }
//         return true;
//     }

//     // Recursive function to generate all subsequences
//     void generateSubsequences(int ind, vector<int>& temp, vector<int>& nums) {
//         // Base case: when we reach the end of the array
//         if (ind == nums.size()) {
//             // Check if the generated subsequence is strictly increasing
//             if (isIncreasing(temp)) {
//                 maxLen = max(maxLen, (int)temp.size());
//             }
//             return;
//         }

//         // Option 1: Pick current element
//         temp.push_back(nums[ind]);
//         generateSubsequences(ind + 1, temp, nums);

//         // Option 2: Backtrack & Non-pick current element
//         temp.pop_back();
//         generateSubsequences(ind + 1, temp, nums);
//     }

// public:
//     int lengthOfLIS(vector<int>& nums) {
//         maxLen = 0;
//         vector<int> temp;
//         generateSubsequences(0, temp, nums);
//         return maxLen;
//     }
// };

// //Memoization + recursion
// class Solution {
// private:
//     int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
//         // Base case: processed all elements
//         if (ind == n) return 0;

//         // Coordinate shift: prev_ind is offset by +1 since prev_ind ranges from -1 to n-1
//         if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

//         // Option 1: Do not pick the current element
//         int len = 0 + f(ind + 1, prev_ind, nums, n, dp);

//         // Option 2: Pick the current element (if strictly increasing)
//         if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
//             len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
//         }

//         return dp[ind][prev_ind + 1] = len;
//     }

// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // DP table of size n x (n + 1) initialized to -1
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return f(0, -1, nums, n, dp);
//     }
// };


// //bottom up 
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
        
//         // DP table of size (n + 1) x (n + 1) initialized to 0
//         // Base case: dp[n][anything] = 0 is naturally handled by zero-initialization
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         // Iterate backwards from n - 1 down to 0
//         for (int ind = n - 1; ind >= 0; ind--) {
//             for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
//                 // Option 1: Do not pick current element
//                 int len = 0 + dp[ind + 1][prev_ind + 1];

//                 // Option 2: Pick current element (if strictly increasing)
//                 if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
//                     len = max(len, 1 + dp[ind + 1][ind + 1]);
//                 }

//                 dp[ind][prev_ind + 1] = len;
//             }
//         }

//         // Result corresponds to starting at index 0 with no previous element (prev_ind = -1)
//         return dp[0][0];
//     }
// };

//Space Optimization 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // Two 1D rows of size (n + 1)
        vector<int> next(n + 1, 0);
        vector<int> cur(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                // Option 1: Do not pick current element
                int len = 0 + next[prev_ind + 1];

                // Option 2: Pick current element (if strictly increasing)
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, 1 + next[ind + 1]);
                }

                cur[prev_ind + 1] = len;
            }
            // Move up to the previous row
            next = cur;
        }

        return next[0];
    }
};