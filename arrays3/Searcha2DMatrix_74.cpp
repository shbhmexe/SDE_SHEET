// //Brute force 
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();

//         for(int i = 0 ; i < row - 1; i++){
//             for(int j = 0; j < col - 1; j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }
//         return false;

//     }
// };

// //Optimal - binary search - 0(n + log m)
// class Solution {
// public:
//     bool binarySearch(vector<int>& arr, int target) {
//         int n = arr.size();
//         int start = 0;
//         int end = n - 1;

//         while(start <= end) {
//             int mid = start + (end - start) / 2;

//             if(arr[mid] == target) {
//                 return true;
//             }

//             if(arr[mid] < target) {
//                 start = mid + 1;
//             } 
//             else {
//                 end = mid - 1;
//             }
//         }
//         return false;
//     }

//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();

//         for(int i = 0; i < row; i++) {
//             if(matrix[i][0] <= target && target <= matrix[i][col - 1]) {
//                 return binarySearch(matrix[i], target);
//             }
//         }
        
//         return false;
//     }
// };

//Optimal - 2 , convert to 1d then Binary seaarch - O(log(m * n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0; 
        int high = (n * m - 1);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};