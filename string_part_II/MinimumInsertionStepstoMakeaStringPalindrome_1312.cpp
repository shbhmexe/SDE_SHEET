//Brute force - tle 
class Solution {
public:
    int solve(string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        
        if (s[i] == s[j]) {
            return solve(s, i + 1, j - 1);
        }
        
        return 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }

    int minInsertions(string s) {
        return solve(s, 0, s.length() - 1);
    }
};

//Optimize - dp 