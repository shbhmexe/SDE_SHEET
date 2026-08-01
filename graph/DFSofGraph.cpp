class Solution {
private:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;
        ls.push_back(node);
        
        // Traverse all its neighbours
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsHelper(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0); // Visited array initialized to 0
        vector<int> ls;        // To store the DFS traversal
        
        // Start DFS from node 0
        dfsHelper(0, adj, vis, ls);
        
        return ls;
    }
};