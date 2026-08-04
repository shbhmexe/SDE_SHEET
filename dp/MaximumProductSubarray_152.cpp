// //Burte force 
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;

//         // Outer loop for starting point
//         for (int i = 0; i < n; i++) {
//             // Middle loop for ending point
//             for (int j = i; j < n; j++) {
//                 int prod = 1;
//                 // Inner loop to calculate product of subarray nums[i...j]
//                 for (int k = i; k <= j; k++) {
//                     prod = prod * nums[k];
//                 }
//                 maxi = max(maxi, prod);
//             }
//         }

//         return maxi;
//     }
// };

// //Better 
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             int prod = 1;
//             for (int j = i; j < n; j++) {
//                 prod = prod * nums[j];
//                 maxi = max(maxi, prod);
//             }
//         }

//         return maxi;
//     }
// };

//Optimize
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int pre = 1, suff = 1;
//         int ans = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             // Reset product to 1 if it encountered a 0 in the previous step
//             if (pre == 0) pre = 1;
//             if (suff == 0) suff = 1;

//             // Calculate prefix product from left & suffix product from right
//             pre = pre * nums[i];
//             suff = suff * nums[n - i - 1];

//             // Keep track of the maximum product found so far
//             ans = max(ans, max(pre, suff));
//         }

//         return ans;
//     }
// };

//DP 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Dynamic programming states initialized with the first element
        int max_prod = nums[0];
        int min_prod = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            // Multiplying by a negative flips max to min and min to max
            if (nums[i] < 0) {
                swap(max_prod, min_prod);
            }

            // Transition: either extend previous product or start fresh at nums[i]
            max_prod = max(nums[i], max_prod * nums[i]);
            min_prod = min(nums[i], min_prod * nums[i]);

            ans = max(ans, max_prod);
        }

        return ans;
    }
};