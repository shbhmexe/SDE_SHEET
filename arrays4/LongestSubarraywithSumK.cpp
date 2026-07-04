// //better brute force - O(N^2)
// class Solution {
// public:
//     int longestSubarray(vector<int>& arr, int k) {
//         int n = arr.size();
//         int len = 0;
        
//         for(int i = 0; i < n; i++){
//             long long sum = 0; 
//             for(int j = i; j < n; j++){ 
//                 sum += arr[j];
//                 if(sum == k){
//                     len = max(len, j - i + 1);
//                 }
//             }
//         }
//         return len;
//     }
// };


// //optimal for + & - element  = extra space 
// class Solution {
// public:
//     int longestSubarray(vector<int>& arr, int k) {
//         int n = arr.size();
//         int maxLen = 0;
//         map<long long, int> preSumMpp;
//         long long sum = 0;
        
//         for(int i = 0; i < n; i++){
//             sum += arr[i];
            
//             if(sum == k){
//                 maxLen = max(maxLen, i + 1);
//             }
            
//             long long rem = sum - k;
            
//             if(preSumMpp.find(rem) != preSumMpp.end()){
//                 int len = i - preSumMpp[rem];
//                 maxLen = max(maxLen, len);
//             }
            
//             if(preSumMpp.find(sum) == preSumMpp.end()){
//                 preSumMpp[sum] = i;
//             }
//         }
//         return maxLen;
//     }   
// };


//Optimal - for only + and 0's element 
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;
        int l = 0;
        int r = 0;
        long long sum = arr[0];
        
        while(r < n){
            while(l <= r && sum > k){
                sum -= arr[l];
                l++;
            }
            if(sum == k) maxLen = max(maxLen, r - l + 1);
            r++;
            
            if(r < n) sum += arr[r];
        }
        return maxLen;
    }    
};