// //Brute force 
// class StockSpanner {
//     vector<int> arr;

// public:
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         arr.push_back(price);
//         int cnt = 1;
        
//         for (int i = arr.size() - 2; i >= 0; i--) {
//             if (arr[i] <= price) {
//                 cnt++;
//             } else {
//                 break;
//             }
//         }
        
//         return cnt;
//     }
// };

//Optimize - stack 
class StockSpanner {
    stack<pair<int, int>> st;
    int ind;

public:
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind = ind + 1;
        
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        
        return ans;
    }
};