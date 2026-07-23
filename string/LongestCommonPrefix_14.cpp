// //Brute froce 
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.empty()) return "";

//         for (int i = 0; i < strs[0].length(); i++) {
//             char c = strs[0][i];
//             for (int j = 1; j < strs.size(); j++) {
//                 if (i == strs[j].length() || strs[j][i] != c) {
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }

//         return strs[0];
//     }
// };




//optimize - wihout trie
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string result = "";
        string first = strs[0];
        string last = strs.back();

        for (int i = 0; i < first.length(); i++) {
            if (i >= last.length() || first[i] != last[i]) {
                break;
            }
            result += first[i];
        }

        return result;
    }
};