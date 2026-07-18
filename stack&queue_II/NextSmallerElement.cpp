//Brute force 
// class Solution {
// public:
//     vector<int> nextSmallerEle(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nse(n, -1);
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (arr[j] < arr[i]) {
//                     nse[i] = arr[j];
//                     break;
//                 }
//             }
//         }
        
//         return nse;
//     }
// };

//Optimize - stack 
class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            
            if (!st.empty()) {
                nse[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return nse;
    }
};