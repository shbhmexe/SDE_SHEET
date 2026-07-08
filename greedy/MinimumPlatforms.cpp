// //Brute force - O(n^@2)
// class Solution {
// public:
//     int minPlatform(vector<int>& arr, vector<int>& dep) {
//         int maxCnt = 0;
//         int n = arr.size();
        
//         for (int i = 0; i < n; i++) {
//             int cnt = 1;
            
//             for (int j = i + 1; j < n; j++) {
//                 if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || 
//                     (arr[j] >= arr[i] && arr[j] <= dep[i])) {
//                     cnt++;
//                 }
//             }
            
//             if (cnt > maxCnt) {
//                 maxCnt = cnt;
//             }
//         }
        
//         return maxCnt;
//     }
// };

//Optimal - O(2nlogn + N)
class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int maxCnt = 0;
        int n = arr.size();
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        int cnt = 0;
        int i , j = 0;
        
        while(i < n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};