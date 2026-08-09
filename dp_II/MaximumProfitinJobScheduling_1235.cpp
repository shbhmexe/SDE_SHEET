// Recursion - tle
// class Solution {
// public:
//     int n;

//     int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
//         int r = n - 1;
//         int result = n;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (array[mid][0] >= currentJobEnd) {
//                 result = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }

//         return result;
//     }

//     int solve(vector<vector<int>>& array, int i) {
//         if (i >= n) return 0;

//         int next = getNextIndex(array, i + 1, array[i][1]);
//         int taken = array[i][2] + solve(array, next);
//         int notTaken = solve(array, i + 1);

//         return max(taken, notTaken);
//     }

//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         n = startTime.size();
//         vector<vector<int>> array(n, vector<int>(3));

//         for (int i = 0; i < n; i++) {
//             array[i][0] = startTime[i];
//             array[i][1] = endTime[i];
//             array[i][2] = profit[i];
//         }

//         sort(array.begin(), array.end());

//         return solve(array, 0);
//     }
// };

// //memoization 
// class Solution {
// public:
//     int n;
//     vector<int> dp;

//     int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
//         int r = n - 1;
//         int result = n;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (array[mid][0] >= currentJobEnd) {
//                 result = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }

//         return result;
//     }

//     int solve(vector<vector<int>>& array, int i) {
//         if (i >= n) return 0;

//         if (dp[i] != -1) return dp[i];

//         int next = getNextIndex(array, i + 1, array[i][1]);
//         int taken = array[i][2] + solve(array, next);
//         int notTaken = solve(array, i + 1);

//         return dp[i] = max(taken, notTaken);
//     }

//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         n = startTime.size();
//         dp.assign(n, -1);
//         vector<vector<int>> array(n, vector<int>(3));

//         for (int i = 0; i < n; i++) {
//             array[i][0] = startTime[i];
//             array[i][1] = endTime[i];
//             array[i][2] = profit[i];
//         }

//         sort(array.begin(), array.end());

//         return solve(array, 0);
//     }
// };

//tabulation 
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> array(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        sort(array.begin(), array.end());

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1;
            int nextIndex = n;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (array[mid][0] >= array[i][1]) {
                    nextIndex = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            int taken = array[i][2] + dp[nextIndex];
            int notTaken = dp[i + 1];

            dp[i] = max(taken, notTaken);
        }

        return dp[0];
    }
};