//BRute force = linear search - tle 
// class Solution {
//     int countStudents(vector<int>& arr, int pages) {
//         int students = 1;
//         long long pagesStudent = 0;
        
//         for (int i = 0; i < arr.size(); i++) {
//             if (pagesStudent + arr[i] <= pages) {
//                 pagesStudent += arr[i];
//             } else {
//                 students++;
//                 pagesStudent = arr[i];
//             }
//         }
//         return students;
//     }

// public:
//     int findPages(vector<int> &arr, int k) {
//         int n = arr.size();
        
//         if (k > n) {
//             return -1;
//         }

//         int low = arr[0];
//         long long high = 0;
        
//         for (int i = 0; i < n; i++) {
//             low = max(low, arr[i]);
//             high += arr[i];
//         }

//         for (int pages = low; pages <= high; pages++) {
//             if (countStudents(arr, pages) <= k) {
//                 return pages;
//             }
//         }
        
//         return low;
//     }
// };

//OPtimize - binary seaech
class Solution {
    int countStudents(vector<int>& arr, long long pages) {
        int students = 1;
        long long pagesStudent = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if (k > n) {
            return -1;
        }

        long long low = arr[0];
        long long high = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > low) {
                low = arr[i];
            }
            high += arr[i];
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int students = countStudents(arr, mid);
            
            if (students > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};
