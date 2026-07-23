// //Brute focre - tle
// class Solution {
// public:
//     vector<int> search(string& pat, string& txt) {
//         vector<int> ans;
//         int n = txt.length();
//         int m = pat.length();
        
//         if (m > n) return ans;
        
//         for (int i = 0; i <= n - m; i++) {
//             int j = 0;
//             while (j < m && txt[i + j] == pat[j]) {
//                 j++;
//             }
            
//             if (j == m) {
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
// };

//opTIMIZE - kmp 
class Solution {
public:
    void computeLPS(string& pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    vector<int> search(string& pat, string& txt) {
        int N = txt.length();
        int M = pat.length();
        vector<int> result;
        
        vector<int> lps(M, 0);
        computeLPS(pat, lps);
        
        int i = 0;
        int j = 0;
        
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            
            if (j == M) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }
};