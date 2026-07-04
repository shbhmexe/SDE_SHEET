// // Brute Force - O(N^3)
// class Solution {
// public:
//     long subarrayXor(vector<int> &arr, int k) {
//         int n = arr.size();
//         long cnt = 0;
        
//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
//                 int xo = 0;
//                 for(int l = i; l <= j; l++){
//                     xo = xo ^ arr[l];
//                 }
//                 if(xo == k){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// //better - O(N^2)
// class Solution {
// public:
//     long subarrayXor(vector<int> &arr, int k) {
//         int n = arr.size();
//         long cnt = 0;
        
//         for(int i = 0; i < n; i++){
//             int xo = 0;
//             for(int j = i; j < n; j++){
//                 xo = xo ^ arr[j];
//                 if(xo == k) cnt++;
//             }
            
             
//         }
//         return cnt;
//     }   
// };    



class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        long cnt = 0;
        int xr = 0;
        map<int ,int> mpp;
        mpp[xr]++;
        
        for(int i = 0; i < n; i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;
            
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }    
};    






















