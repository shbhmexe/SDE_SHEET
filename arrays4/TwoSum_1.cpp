// //brute force 
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> ans;

//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] + nums[j] == target){
//                     ans = {i, j};
//                     return ans; 
//                 }
//             }
//         }
//         return ans;
//     }
// };

//better - hashing extra space 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        
        for(int i = 0; i < n; i++){
            int a = nums[i];
            int more = target - a;

            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[a] = i; 
        }
        
        return {};
    }    
};