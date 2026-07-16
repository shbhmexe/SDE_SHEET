// // //burte force - map - 3 pass - O(N \log N)
// // class Solution {
// // public:
// //     vector<int> topKFrequent(vector<int>& nums, int k) {
// //         unordered_map<int, int> mp;
        
// //         for (int i = 0; i < nums.size(); i++) {
// //             mp[nums[i]]++;
// //         }
        
// //         vector<pair<int, int>> v;
// //         for (auto it : mp) {
// //             v.push_back({it.second, it.first});
// //         }
        
// //         sort(v.rbegin(), v.rend());
        
// //         vector<int> ans;
// //         for (int i = 0; i < k; i++) {
// //             ans.push_back(v[i].second);
// //         }
        
// //         return ans;
// //     }
// // };


// //Better - map + min heap
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
        
//         for (int i = 0; i < nums.size(); i++) {
//             mp[nums[i]]++;
//         }
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
//         for (auto it : mp) {
//             pq.push({it.second, it.first});
            
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
        
//         vector<int> ans;
        
//         while (!pq.empty()) {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
        
//         return ans;
//     }
// };

//Optimize - bucktect - sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        vector<vector<int>> bucket(n + 1);
        
        for (auto it : mp) {
            bucket[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                ans.push_back(bucket[i][j]);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        
        return ans;
    }
};