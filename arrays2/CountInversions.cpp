// //brute force 
// class Solution {
// public:
//     int inversionCount(vector<int> &arr) {
//         int n = arr.size();
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (arr[i] > arr[j]) {
//                     cnt += 1;
//                 }
//             }
//         }

//         return cnt;
//     }
// };

//optimal 
class Solution {
private:
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;      // Starting index of left half
        int right = mid + 1; // Starting index of right half
        int cnt = 0;

        // Storing elements in the temporary array in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                // arr[left] > arr[right] -> Inversion found!
                // All remaining elements from arr[left] to arr[mid] will also be > arr[right]
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        // Copy remaining elements from left half, if any
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from right half, if any
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy elements from temp back into original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(arr, low, mid);       // Count inversions in left half
        cnt += mergeSort(arr, mid + 1, high);  // Count inversions in right half
        cnt += merge(arr, low, mid, high);     // Count cross inversions during merge

        return cnt;
    }

public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};