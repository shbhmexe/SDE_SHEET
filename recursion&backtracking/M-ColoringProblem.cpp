//Recursion + backtracing 
class Solution {
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int col) {
        for (auto it : adj[node]) {
            if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, vector<int>& color, int m, int v, vector<vector<int>>& adj) {
        if (node == v) {
            return true;
        }

        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, adj, i)) {
                color[node] = i;
                
                if (solve(node + 1, color, m, v, adj)) return true;
                
                color[node] = 0;
            }
        }
        
        return false;
    }

public:
    bool graphColoring(int v, vector<vector<int>>& edges, int m) {
        vector<vector<int>> adj(v);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> color(v, 0);
        
        return solve(0, color, m, v, adj);
    }
};