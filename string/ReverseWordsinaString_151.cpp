//Tc = O(N) , Sc = O(N)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                ans += " " + word;
            }
        }
        return ans.empty() ? "" : ans.substr(1);
    }
};