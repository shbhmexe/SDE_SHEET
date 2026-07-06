// //Brute force - set
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         set<int> st;
//         for(int i = 0; i < n; i++){
//             st.insert(nums[i]);
//         }
//         int idx = 0;
//         for(auto it : st){
//             nums[idx] = it;
//             idx++;
//         }
//         return idx;
//     }
// };

//Optimal - Two pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};


