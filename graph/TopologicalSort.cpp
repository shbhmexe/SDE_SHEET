//DFS
class Solution {
private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


//BFS
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};