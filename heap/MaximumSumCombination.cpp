//Brute force - sorting 
// class Solution {
// public:
//     vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
//         int n = a.size();
//         vector<int> sums;
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 sums.push_back(a[i] + b[j]);
//             }
//         }
        
//         sort(sums.rbegin(), sums.rend());
        
//         vector<int> ans;
//         for (int i = 0; i < k; i++) {
//             ans.push_back(sums[i]);
//         }
        
//         return ans;
//     }
// };

//oPTIMIES  MAxHeap
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        int n = a.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;
        
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});
        
        vector<int> ans;
        
        while (k > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            if (i + 1 < n && vis.find({i + 1, j}) == vis.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }
            
            if (j + 1 < n && vis.find({i, j + 1}) == vis.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
            
            k--;
        }
        
        return ans;
    }
};