// //Brute force 
// class Solution {
// public:
//     void sortStack(stack<int>& st) {
//         vector<int> v;
        
//         while (!st.empty()) {
//             v.push_back(st.top());
//             st.pop();
//         }
        
//         sort(v.begin(), v.end());
        
//         for (int i = 0; i < v.size(); i++) {
//             st.push(v[i]);
//         }
//     }
// };

//Optimize - recursion 
class Solution {
    void insertSorted(stack<int>& st, int val) {
        if (st.empty() || st.top() <= val) {
            st.push(val);
            return;
        }
        
        int temp = st.top();
        st.pop();
        
        insertSorted(st, val);
        
        st.push(temp);
    }

public:
    void sortStack(stack<int>& st) {
        if (st.empty()) {
            return;
        }
        
        int temp = st.top();
        st.pop();
        
        sortStack(st);
        
        insertSorted(st, temp);
    }
};