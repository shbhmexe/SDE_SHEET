// //Brute force - recursion 
// class Solution {
// public:
//     bool isValid(string s) {
//         if (s.length() == 0) {
//             return true;
//         }
        
//         if (s.find("()") != string::npos) {
//             s.erase(s.find("()"), 2);
//             return isValid(s);
//         }
        
//         if (s.find("[]") != string::npos) {
//             s.erase(s.find("[]"), 2);
//             return isValid(s);
//         }
        
//         if (s.find("{}") != string::npos) {
//             s.erase(s.find("{}"), 2);
//             return isValid(s);
//         }
        
//         return false;
//     }
// };

///Optimize - stack 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};