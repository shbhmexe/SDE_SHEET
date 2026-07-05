// //Brute Force - extra Space - (3n)
// class Solution {
// private:
//     vector<int> getPrefixMax(const vector<int>& height, int n) {
//         vector<int> prefix(n);
//         prefix[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             prefix[i] = max(prefix[i - 1], height[i]);
//         }
//         return prefix;
//     }

//     vector<int> getSuffixMax(const vector<int>& height, int n) {
//         vector<int> suffix(n);
//         suffix[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             suffix[i] = max(suffix[i + 1], height[i]);
//         }
//         return suffix;
//     }

// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0; 

//         vector<int> prefix = getPrefixMax(height, n);
//         vector<int> suffix = getSuffixMax(height, n);

//         int totalWater = 0;

//         for (int i = 0; i < n; i++) {
//             totalWater += min(prefix[i], suffix[i]) - height[i];
//         }

//         return totalWater;
//     }
// };


// //brute better - o(2n)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0;

//         vector<int> leftMax(n);
//         leftMax[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//         }

//         int rightMax = height[n - 1];
//         int totalWater = 0;

//         for (int i = n - 1; i >= 0; i--) {
//             rightMax = max(rightMax, height[i]);
//             totalWater += min(leftMax[i], rightMax) - height[i];
//         }

//         return totalWater;
//     }
// };

//Optimal - O(1) space and O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int lm = 0;
        int rm = 0;
        int total = 0;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            if(height[l] <= height[r]) {
                if(lm > height[l]) {
                    total += lm - height[l];
                } else {
                    lm = height[l];
                }
                l++; 
            } 
            else {
                if(rm > height[r]) {
                    total += rm - height[r];
                } else {
                    rm = height[r];
                }
                r--; 
            }
        }
        return total;
    }
};