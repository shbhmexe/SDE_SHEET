//Optmiaml 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int mxi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                mxi = max(mxi , cnt);
            }
            else cnt = 0;
        }
        return mxi;
    }
};