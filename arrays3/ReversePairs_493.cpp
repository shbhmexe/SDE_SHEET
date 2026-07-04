// //brute force - n2
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         int cnt = 0;

//         for(int i = 0; i < n - 1; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] > 2LL * nums[j]){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

//Optimal 
class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int left = l;
        int right = mid + 1;

        while (left <= mid && right <= r) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= r) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    int countPair(vector<int>& arr, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;
        for(int i = low; i <= mid; i++){
            while(right <= high && arr[i] > 2LL * arr[right]){
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if (l < r) {
            int mid = l + (r - l) / 2;
            cnt += mergeSort(arr, l, mid);
            cnt += mergeSort(arr, mid + 1, r);
            cnt += countPair(arr, l, mid, r);
            merge(arr, l, mid, r);
        }
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0 , n - 1);
    }
};