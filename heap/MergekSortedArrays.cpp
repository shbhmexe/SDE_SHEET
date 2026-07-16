// //Brute force -  O(N .M \log(N.M))
// class Solution {
// public:
//     vector<int> mergeArrays(vector<vector<int>>& mat) {
//         vector<int> ans;
        
//         for (int i = 0; i < mat.size(); i++) {
//             for (int j = 0; j < mat[i].size(); j++) {
//                 ans.push_back(mat[i][j]);
//             }
//         }
        
//         sort(ans.begin(), ans.end());
        
//         return ans;
//     }
// };

//Optimisze - min heap
class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>>& mat) {
        int n = mat.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for (int i = 0; i < n; i++) {
            if (mat[i].size() > 0) {
                pq.push({mat[i][0], {i, 0}});
            }
        }
        
        vector<int> ans;
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int val = top.first;
            int row = top.second.first;
            int col = top.second.second;
            
            ans.push_back(val);
            
            if (col + 1 < mat[row].size()) {
                pq.push({mat[row][col + 1], {row, col + 1}});
            }
        }
        
        return ans;
    }
};