// //brute force extra space 
// class MinStack {
//     stack<pair<int, int>> st;

// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if (st.empty()) {
//             st.push({val, val});
//         } else {
//             st.push({val, min(val, st.top().second)});
//         }
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

//optimize - no extra space - o(n)
class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long v = val;
        if (st.empty()) {
            mini = v;
            st.push(v);
        } else {
            if (v >= mini) {
                st.push(v);
            } else {
                st.push(2 * v - mini);
                mini = v;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long x = st.top();
        st.pop();
        
        if (x < mini) {
            mini = 2 * mini - x;
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        
        long long x = st.top();
        if (x < mini) {
            return mini;
        }
        return x;
    }
    
    int getMin() {
        return mini;
    }
};