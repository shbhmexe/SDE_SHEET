// //Burte force - 
// class Solution {
//   public:
//     int median(vector<vector<int>> &mat) {
//         vector<int> ls;
//         int m = mat.size();
//         int n = mat[0].size();
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 ls.push_back(mat[i][j]);
//             }
//         }
        
//         sort(begin(ls), end(ls));
        
//         return ls[m * n / 2];
//     }
// };

//Optimize - upper bound 
class Solution {
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(matrix[i], x, m);
        }
        return cnt;
    }

public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        
        int req = (n * m) / 2;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int smallEqual = countSmallEqual(mat, n, m, mid);
            
            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};
