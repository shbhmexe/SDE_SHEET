// //Qyuestion 4 july26
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int maxi = INT_MIN;
//         int ansStart = -1;
//         int ansEnd = -1;
//         int start = 0;
        
//         for(int i = 0; i < nums.size(); i++){
//             if(sum == 0){
//                 start - i;
//             }
//             sum = sum + nums[i];
            
//             if(sum > maxi){
//                 maxi = sum;
//                 ansStart = start; //track of subarray 
//                 ansEnd = i;
//             }
            
//             if(sum < 0){
//                 sum = 0;
//             }
//         }
//         return maxi;
//     }
// };

//Divide And Conquer

class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        
        int leftMax = helper(nums, left, mid);
        int rightMax = helper(nums, mid + 1, right);
        
        int left_sum = 0;
        int leftCrossMax = -1e5;
        for (int i = mid; i >= left; i--) {
            left_sum += nums[i];
            if (left_sum > leftCrossMax) {
                leftCrossMax = left_sum;
            }
        }
        
        int right_sum = 0;
        int rightCrossMax = -1e5;
        for (int i = mid + 1; i <= right; i++) {
            right_sum += nums[i];
            if (right_sum > rightCrossMax) {
                rightCrossMax = right_sum;
            }
        }
        
        int crossMax = leftCrossMax + rightCrossMax;
        
        return max(max(leftMax, rightMax), crossMax);
    }

    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};