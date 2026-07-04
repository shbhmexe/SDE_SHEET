// //Brute force - 0(n2)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int cnt = 0;
//         vector<int> ls; 

//         for(int i = 0; i < n; i++){ 
//             if(ls.size() == 0 || ls[0] != nums[i]){
//                 cnt = 0;
//                 for(int j = 0; j < n; j++){ 
//                     if(nums[j] == nums[i]){
//                         cnt++;
//                     }
//                 }
//                 if(cnt > n / 3){
//                     ls.push_back(nums[i]); 
//                 }
//             }
//             if(ls.size() == 2) break;
//         }
//         return ls;
//     }
// };

// //better 
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         map<int, int>mpp;
//         vector<int> ls;
//         int minVal = (int)(n / 3) + 1;
        
//         for(int i = 0; i < nums.size(); i++){
//             mpp[nums[i]]++;

//             if(mpp[nums[i]] == minVal){
//                 ls.push_back(nums[i]);
//             }
//             if(ls.size() == 2){
//                 break;
//             }
//         }
//         return ls;
//     }
// };


//Optimal class Solution {
class Solution{
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1, el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2 = 1, el2 = nums[i];
            }
            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else{
                cnt1-- , cnt2--;
            }
        }
        
        vector<int>ls;
        cnt1 = 0, cnt2 = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++; 
        }
        
        int minVal = (int) (n / 3) + 1;
        if(cnt1 >= minVal) ls.push_back(el1);
        if(cnt2 >= minVal) ls.push_back(el2);

        return ls;
    }
};