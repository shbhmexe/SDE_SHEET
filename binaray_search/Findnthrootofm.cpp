// //brute force - -O(n^2)
// class Solution {
// public:
//     int nthRoot(int n, int m) {
//         for (int i = 1; i <= m; i++) {
//             long long val = 1;
            
//             for (int j = 1; j <= n; j++) {
//                 val *= i;
//                 if (val > m) {
//                     break;
//                 }
//             }
            
//             if (val == m) {
//                 return i;
//             }
//             if (val > m) {
//                 break;
//             }
//         }
//         return -1;
//     }
// };

//Optimize 
class Solution {
    int getPow(int mid, int n, int m) {
        long long val = 1;
        for (int i = 1; i <= n; i++) {
            val *= mid;
            if (val > m) return 2;
        }
        if (val == m) return 1;
        return 0;
    }

public:
    int nthRoot(int n, int m) {
        int low = 0, high = m;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = getPow(mid, n, m);
            
            if (val == 1) {
                return mid;
            }
            else if (val == 0) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};