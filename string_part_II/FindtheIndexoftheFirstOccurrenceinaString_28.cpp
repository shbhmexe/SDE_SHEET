// //Burte force 
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.length();
//         int m = needle.length();
        
//         if (m == 0) return 0;
//         if (n < m) return -1;
        
//         for (int i = 0; i <= n - m; i++) {
//             int j = 0;
//             while (j < m && haystack[i + j] == needle[j]) {
//                 j++;
//             }
//             if (j == m) {
//                 return i;
//             }
//         }
        
//         return -1;
//     }
// };

//Optimize - -KMP 
class Solution {
private:
    void computeLPS(string& needle, vector<int>& lps) {
        int m = needle.length();
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
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

public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) return 0;
        
        vector<int> lps(m, 0);
        computeLPS(needle, lps);
        
        int i = 0;
        int j = 0;
        
        while (i < n) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }
            
            if (j == m) {
                return i - j;
            } else if (i < n && needle[j] != haystack[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1;
    }
};