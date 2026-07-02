//Question 5 julu 26
// //TWO PASS = O(2n)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int cnt1 = 0;
//         int cnt0 = 0;
//         int cnt2 = 0;

//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == 0){
//                 cnt0++;
//             }
//             if(nums[i] == 1){
//                 cnt1++;
//             }
//             if(nums[i] == 2){
//                 cnt2++;
//             }
//         }

//         int i = 0;
//         while(cnt0 > 0){
//             nums[i] = 0;
//             i++;
//             cnt0--;
//         }

//         while(cnt1 > 0){
//             nums[i] = 1;
//             i++;
//             cnt1--;
//         }

//         while(cnt2 > 0){
//             nums[i] = 2;
//             i++;
//             cnt2--;
//         }
//     }
// };

//One pass

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;

            }else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};    