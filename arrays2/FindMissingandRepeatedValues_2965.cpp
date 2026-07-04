// //better - two pass
// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int max_val = n * n;
        
//         vector<int> hash(max_val + 1, 0);

//         for(const auto& row : grid){
//             for(int val : row) {
//                 hash[val]++;
//             }
//         }

//         int repeat = -1, missing = -1;

//         for(int i = 1; i <= max_val; i++){
//             if(hash[i] == 2) {
//                 repeat = i;
//             }
//             else if(hash[i] == 0) {
//                 missing = i;
//             }

//             if(repeat != -1 && missing != -1){
//                 break;
//             }
//         }
        
//         return {repeat, missing};
//     }
// };

//optimal - 1 maths - based
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size(), N = n * n;
        long long S = (N * (N + 1)) / 2, Sn = (N * (N + 1) * (2 * N + 1)) / 6;
        long long s1 = 0, sn2 = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                long long v = grid[i][j];
                s1 += v;
                sn2 += v * v;
            }
        }
        
        long long val1 = s1 - S;
        long long x = (val1 + (sn2 - Sn) / val1) / 2;
        
        return {(int)x, (int)(x - val1)};
    }
};