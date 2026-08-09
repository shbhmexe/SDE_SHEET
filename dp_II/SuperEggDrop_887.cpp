// recursion only - tle
// class Solution {
// private:
//     int f(int k, int n) {
//         if (n == 0 || n == 1) return n;
//         if (k == 1) return n;

//         int minMoves = INT_MAX;

//         for (int x = 1; x <= n; x++) {
//             int eggBreaks = f(k - 1, x - 1);
//             int eggSurvives = f(k, n - x);
//             int worstCase = 1 + max(eggBreaks, eggSurvives);
            
//             minMoves = min(minMoves, worstCase);
//         }

//         return minMoves;
//     }

// public:
//     int superEggDrop(int k, int n) {
//         return f(k, n);
//     }
// };

//memo 
class Solution {
private:
    int f(int k, int n, vector<vector<int>>& dp) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;

        if (dp[k][n] != -1) return dp[k][n];

        int minMoves = INT_MAX;
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int eggBreaks = f(k - 1, mid - 1, dp);
            int eggSurvives = f(k, n - mid, dp);

            int worstCase = 1 + max(eggBreaks, eggSurvives);
            minMoves = min(minMoves, worstCase);

            if (eggBreaks < eggSurvives) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return dp[k][n] = minMoves;
    }

public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return f(k, n, dp);
    }
};