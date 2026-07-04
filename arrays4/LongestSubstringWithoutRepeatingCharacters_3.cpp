// //brute force - O(n2)
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length(); 
//         int maxlen = 0;
        
//         for (int i = 0; i < n; i++) {
//             int hash[256] = {0}; 
            
//             for (int j = i; j < n; j++) {
//                 if (hash[s[j]] == 1) {
//                     break;
//                 }
                
//                 int len = j - i + 1;
//                 maxlen = max(maxlen, len);
//                 hash[s[j]] = 1; 
//             }
//         }
//         return maxlen;
//     }
// };

// optimal - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(); 
        int maxlen = 0;
        vector<int> hash(256, -1); 
        int r = 0, l = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};