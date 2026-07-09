// //Burte force - 
// class Solution {
// public:
//     vector<int> subsetSums(vector<int>& arr) {
//         int n = arr.size();
//         int totalSubsets = 1 << n;
//         vector<int> result;
        
//         for (int i = 0; i < totalSubsets; i++) {
//             int currentSum = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i & (1 << j)) {
//                     currentSum += arr[j];
//                 }
//             }
//             result.push_back(currentSum);
//         }
        
//         return result;
//     }
// };


 
class Solution {
    void func(int ind, int sum, vector<int>& arr, int N, vector<int>& sumSubset) {
        if (ind == N) {
            sumSubset.push_back(sum);
            return;
        }
        
        func(ind + 1, sum + arr[ind], arr, N, sumSubset);
        
        func(ind + 1, sum, arr, N, sumSubset);
    }

public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sumSubset;
        int N = arr.size();
        
        func(0, 0, arr, N, sumSubset);
        
        sort(sumSubset.begin(), sumSubset.end());
        
        return sumSubset;
    }
};