// //Brute force - O(n + m)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> merged;
        
//         int i = 0, j = 0;
        
//         while (i < n1 && j < n2) {
//             if (nums1[i] < nums2[j]) {
//                 merged.push_back(nums1[i]);
//                 i++;
//             } else {
//                 merged.push_back(nums2[j]);
//                 j++;
//             }
//         }
        
//         while (i < n1) {
//             merged.push_back(nums1[i]);
//             i++;
//         }
        
//         while (j < n2) {
//             merged.push_back(nums2[j]);
//             j++;
//         }
        
//         int n = n1 + n2;
        
//         if (n % 2 == 1) {
//             return merged[n / 2];
//         } else {
//             return (merged[n / 2] + merged[(n / 2) - 1]) / 2.0;
//         }
//     }
// };

///Better - O(N+M) and O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        
        int ind1el = -1;
        int ind2el = -1;
        
        int i = 0, j = 0, cnt = 0;
        
        while (i < n1 && j < n2) {
            int val = 0;
            if (nums1[i] < nums2[j]) {
                val = nums1[i];
                i++;
            } else {
                val = nums2[j];
                j++;
            }
            
            if (cnt == ind1) ind1el = val;
            if (cnt == ind2) ind2el = val;
            cnt++;
        }
        
        while (i < n1) {
            int val = nums1[i];
            if (cnt == ind1) ind1el = val;
            if (cnt == ind2) ind2el = val;
            cnt++;
            i++;
        }
        
        while (j < n2) {
            int val = nums2[j];
            if (cnt == ind1) ind1el = val;
            if (cnt == ind2) ind2el = val;
            cnt++;
            j++;
        }
        
        if (n % 2 == 1) {
            return (double)ind2el;
        } else {
            return (ind1el + ind2el) / 2.0;
        }
    }
};