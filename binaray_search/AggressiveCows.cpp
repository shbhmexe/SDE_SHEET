//Brute force - linear search 
// class Solution {
//     bool canWePlace(vector<int> &arr, int dist, int cows) {
//         int cntCows = 1;
//         int lastPlaced = arr[0];
        
//         for (int i = 1; i < arr.size(); i++) {
//             if (arr[i] - lastPlaced >= dist) {
//                 cntCows++;
//                 lastPlaced = arr[i];
//             }
//             if (cntCows >= cows) {
//                 return true;
//             }
//         }
//         return false;
//     }

// public:
//     int aggressiveCows(vector<int> &arr, int k) {
//         sort(arr.begin(), arr.end());
//         int n = arr.size();
//         int limit = arr[n - 1] - arr[0];
        
//         for (int i = 1; i <= limit; i++) {
//             if (canWePlace(arr, i, k) == false) {
//                 return (i - 1);
//             }
//         }
        
//         return limit;
//     }
// };

//Binary Seaarch
class Solution {
    bool canWePlace(vector<int> &arr, int dist, int cows) {
        int cntCows = 1;
        int lastPlaced = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                cntCows++;
                lastPlaced = arr[i];
            }
            if (cntCows >= cows) {
                return true;
            }
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int low = 1;
        int high = arr[n - 1] - arr[0];
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canWePlace(arr, mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high;
    }
};
