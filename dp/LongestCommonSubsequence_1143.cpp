// //Recursion only - exponetial
// class Solution {
// private:
//     int f(int i, int j, string &s, string &t) {
//         // Base case: if either string index goes below 0
//         if (i < 0 || j < 0) return 0;

//         // Matching character case
//         if (s[i] == t[j]) return 1 + f(i - 1, j - 1, s, t);

//         // Non-matching character case
//         return max(f(i - 1, j, s, t), f(i, j - 1, s, t));
//     }

// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();

//         return f(n - 1, m - 1, text1, text2);
//     }
// };

//Memoization 
class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);

        return dp[i][j] = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, text1, text2, dp);
    }
};

//Tablulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // DP table initialized to 0
        // Base cases dp[0][j] = 0 and dp[i][0] = 0 are automatically handled
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // If characters do not match
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

//space optimize 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int j = 0; j <= m; j++) prev[j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};