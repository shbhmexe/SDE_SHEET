//Recursion only - tle 
// class Solution {
// public:
//     unordered_set<string> st;
//     int n;

//     bool solve(int idx, string &s) {
//         if (idx == n) return true;

//         for (int l = 1; idx + l <= n; l++) {
//             string temp = s.substr(idx, l);
            
//             if (st.find(temp) != st.end() && solve(idx + l, s)) {
//                 return true;
//             }
//         }
        
//         return false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         n = s.length();

//         for (string &word : wordDict) {
//             st.insert(word);
//         }

//         return solve(0, s);
//     }
// };


//Memo 
// class Solution {
// public:
//     unordered_set<string> st;
//     int n;
//     vector<int> dp;

//     bool solve(int idx, string &s) {
//         if (idx == n) return true;

//         if (dp[idx] != -1) return dp[idx];

//         for (int l = 1; idx + l <= n; l++) {
//             string temp = s.substr(idx, l);
            
//             if (st.find(temp) != st.end() && solve(idx + l, s)) {
//                 return dp[idx] = true;
//             }
//         }
        
//         return dp[idx] = false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         n = s.length();
//         dp.assign(n, -1);

//         for (string &word : wordDict) {
//             st.insert(word);
//         }

//         return solve(0, s);
//     }
// };

//Tabulation 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);

        dp[n] = true;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int l = 1; idx + l <= n; l++) {
                string temp = s.substr(idx, l);
                
                if (st.find(temp) != st.end() && dp[idx + l]) {
                    dp[idx] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};