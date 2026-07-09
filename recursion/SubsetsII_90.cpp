class Solution {
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ansList) {
        ansList.push_back(ds);
        
        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ansList);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ansList;
        vector<int> ds;
        
        findSubsets(0, nums, ds, ansList);
        
        return ansList;
    }
};