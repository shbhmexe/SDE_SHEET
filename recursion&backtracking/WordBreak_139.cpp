//Recursion only - tle 
class Solution {
public:
    unordered_set<string> st;
    int n;

    bool solve(int idx, string &s) {
        if (idx == n) return true;

        for (int l = 1; idx + l <= n; l++) {
            string temp = s.substr(idx, l);
            
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return true;
            }
        }
        
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};