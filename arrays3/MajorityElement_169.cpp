// //brute force - 0(n2)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int cnt = 0;
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = 0; j < nums.size(); j++){
//                 if(nums[i] == nums[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n / 2){
//                 return nums[i];
//             }
//         }
//         return 0;
//     }
// };

/// Better - hashing - O(nlogn + n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mpp;
        
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second > (nums.size() / 2)){
                return it.first;
            }
        }
        return 100000000000000;
    }
};    

//Optimal - moore  voting algo - O(2n) no extra space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if (nums[i] == el){
                cnt++;
            }
            else cnt--;
        }
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == el){
                cnt1++;
            }
            if(cnt1 > (nums.size() / 2)){
                return el;
            }
        }
        return 100000000000;
    }
};   