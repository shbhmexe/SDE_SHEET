// //Brute force 
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
        
//         for (int i = 0; i <= n - k; i++) {
//             int maxVal = nums[i];
//             for (int j = i; j < i + k; j++) {
//                 maxVal = max(maxVal, nums[j]);
//             }
//             ans.push_back(maxVal);
//         }
        
//         return ans;
//     }
// };

//Optimize - deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};