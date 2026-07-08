//Optimize
class Solution {
public:
    struct Item {
        int value, weight;
    };

    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> arr(n);
        
        for (int i = 0; i < n; i++) {
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        double totVal = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= capacity) {
                totVal += arr[i].value;
                capacity -= arr[i].weight;
            } else {
                totVal += ((double)arr[i].value / (double)arr[i].weight) * capacity;
                break;
            }
        }
        
        return totVal;
    }
};