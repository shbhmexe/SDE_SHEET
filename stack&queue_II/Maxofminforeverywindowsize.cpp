class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int len = nse[i] - pse[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        vector<int> res(n);
        for (int i = 1; i <= n; i++) {
            res[i - 1] = ans[i];
        }

        return res;
    }
};