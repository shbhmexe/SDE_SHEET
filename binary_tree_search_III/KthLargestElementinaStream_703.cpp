// //Brurte force - sorting , binary search and inseting 
// class KthLargest {
// private:
//     int K;
//     vector<int> stream;

// public:
//     KthLargest(int k, vector<int>& nums) {
//         K = k;
//         stream = nums;
//         sort(stream.begin(), stream.end());
//     }
    
//     int add(int val) {
//         auto it = lower_bound(stream.begin(), stream.end(), val);
//         stream.insert(it, val);
//         return stream[stream.size() - K];
//     }
// };


//Optimize - Min heap(pq)
class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};