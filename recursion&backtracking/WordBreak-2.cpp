//Recursion only 
class Solution {
    void solve(int idx, string& s, unordered_set<string>& st, string current, vector<string>& ans) {
        if (idx == s.length()) {
            current.pop_back();
            ans.push_back(current);
            return;
        }
        
        string temp = "";
        for (int i = idx; i < s.length(); i++) {
            temp += s[i];
            if (st.find(temp) != st.end()) {
                solve(i + 1, s, st, current + temp + " ", ans);
            }
        }
    }

public:
    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> st(dict.begin(), dict.end());
        vector<string> ans;
        
        solve(0, s, st, "", ans);
        
        return ans;
    }
};