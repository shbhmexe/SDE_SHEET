///Optimize
class Solution {
public:
    struct Job {
        int deadline;
        int profit;
    };

    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }

    int findSlot(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = findSlot(parent[i], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<Job> arr(n);
        
        int maxDeadline = -1;
        for (int i = 0; i < n; i++) {
            arr[i].deadline = deadline[i];
            arr[i].profit = profit[i];
            if (deadline[i] > maxDeadline) {
                maxDeadline = deadline[i];
            }
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        int count = 0;
        int maxProfit = 0;
        
        for (int i = 0; i < n; i++) {
            int availableSlot = findSlot(arr[i].deadline, parent);
            
            if (availableSlot > 0) {
                count++;
                maxProfit += arr[i].profit;
                parent[availableSlot] = findSlot(availableSlot - 1, parent);
            }
        }
        
        return {count, maxProfit};
    }
};