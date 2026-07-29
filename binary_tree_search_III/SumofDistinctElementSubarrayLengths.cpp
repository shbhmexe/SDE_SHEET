//Tree aproach  segment treeee - not optimal 
class Solution {
public:
    int sumOfLengths(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        unordered_set<int> st;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            while (st.count(arr[right])) {
                st.erase(arr[left]);
                left++;
            }
            st.insert(arr[right]);
            
            long long len = right - left + 1;
            totalSum = (totalSum + (len * (len + 1) / 2)) % MOD;
        }
        
        return totalSum;
    }
};