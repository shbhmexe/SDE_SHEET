// //Burte force - O(N^2)
// class Solution {
// public:
//     bool linearSearch(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     int longestConsecutive(vector<int>& nums) {
//         int longSeq = 0;

//         for(int i = 0; i < nums.size(); i++) {
//             int x = nums[i];
//             int cnt = 1;

//             while(linearSearch(nums, x + 1) == true) {
//                 x++;
//                 cnt++;
//             }
//             longSeq = max(longSeq, cnt);
//         }
//         return longSeq; 
//     }
// };


//better  - O(N)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0) return 0;
//         int longSeq = 1;
//         int lastSmaller = INT_MIN;
//         int cnt = 0;
//         sort(nums.begin(), nums.end());

//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i]  - 1 == lastSmaller){
//                 cnt++;
//                 lastSmaller = nums[i];
//             }
//             else if(nums[i] != lastSmaller){
//                 cnt = 1;
//                 lastSmaller = nums[i];
//             }
//             longSeq = max(longSeq , cnt);
//         } 
//         return longSeq;
//     }
// };



//optimal   - O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int longSeq = 1;
        int cnt = 0;
        unordered_set<int>st;

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                cnt = 1;
                int x = it;

                while(st.find(x + 1) != st.end()){
                    x++;
                    cnt++;
                }
                longSeq = max(longSeq , cnt);
            }
        }
        return longSeq;
    }
};