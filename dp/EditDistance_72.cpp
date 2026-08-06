// //recusrion only tle 
// class Solution {
// private:
//     int f(int i, int j, string &s1, string &s2) {
//         // Base cases: if one string is exhausted, remaining characters must be inserted/deleted
//         if (i < 0) return j + 1;
//         if (j < 0) return i + 1;

//         // If characters match, no operation needed
//         if (s1[i] == s2[j]) return f(i - 1, j - 1, s1, s2);

//         // 1 + min(Delete, min(Insert, Replace))
//         return 1 + min(f(i - 1, j, s1, s2), min(f(i, j - 1, s1, s2), f(i - 1, j - 1, s1, s2)));
//     }

// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         return f(n - 1, m - 1, word1, word2);
//     }
// };

//Memoization 
// class Solution {
// private:
//     int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
//         // Base cases: if one string is exhausted, returning remaining length
//         if (i < 0) return j + 1;
//         if (j < 0) return i + 1;

//         // Return memoized result if calculated
//         if (dp[i][j] != -1) return dp[i][j];

//         // If characters match
//         if (s1[i] == s2[j]) return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);

//         // 1 + min(Delete, Insert, Replace)
//         return dp[i][j] = 1 + min(f(i - 1, j, s1, s2, dp), 
//                               min(f(i, j - 1, s1, s2, dp), 
//                                   f(i - 1, j - 1, s1, s2, dp)));
//     }

// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         return f(n - 1, m - 1, word1, word2, dp);
//     }
// }; 

//Tabulation 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases initialization
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // 1 + min(Delete, Insert, Replace)
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j], 
                                   min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }

        return dp[n][m];
    }
};

//space optimize
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Base case: dp[0][j] = j
        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            // Base case: dp[i][0] = i
            cur[0] = i; 

            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};q