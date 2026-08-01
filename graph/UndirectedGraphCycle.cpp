// //BFS
// class Solution {
// private:
//     bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
//         vis[src] = 1;
//         queue<pair<int, int>> q; // {node, parent}
//         q.push({src, -1});
        
//         while (!q.empty()) {
//             int node = q.front().first;
//             int parent = q.front().second;
//             q.pop();
            
//             for (auto adjacentNode : adj[node]) {
//                 if (!vis[adjacentNode]) {
//                     vis[adjacentNode] = 1;
//                     q.push({adjacentNode, node});
//                 }
//                 else if (parent != adjacentNode) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

// public:
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // Build adjacency list from edges
//         vector<vector<int>> adj(V);
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
        
//         vector<int> vis(V, 0);
//         for (int i = 0; i < V; i++) {
//             if (!vis[i]) {
//                 if (detect(i, adj, vis)) return true;
//             }
//         }
//         return false;
//     }
// };


//DFS
class Solution {
private:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, vis, adj)) {
                    return true;
                }
            } else if (adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list from edges
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};