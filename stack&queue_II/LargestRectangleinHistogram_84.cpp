// //Brute force - nse & pse
// class Solution {
//     vector<int> getPSE(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> pse(n, -1);
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (heights[j] < heights[i]) {
//                     pse[i] = j;
//                     break;
//                 }
//             }
//         }
        
//         return pse;
//     }

//     vector<int> getNSE(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> nse(n, n);
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (heights[j] < heights[i]) {
//                     nse[i] = j;
//                     break;
//                 }
//             }
//         }
        
//         return nse;
//     }

// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> pse = getPSE(heights);
//         vector<int> nse = getNSE(heights);
        
//         int maxArea = 0;
        
//         for (int i = 0; i < n; i++) {
//             int area = heights[i] * (nse[i] - pse[i] - 1);
//             maxArea = max(maxArea, area);
//         }
        
//         return maxArea;
//     }
// };

//Optimize - stack annd precompute nse and pse
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            
            int pse = st.empty() ? -1 : st.top();
            
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        
        return maxArea;
    }
};