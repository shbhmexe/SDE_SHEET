// //DFS
// class Solution {
// private:
//     bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
//         vis[node] = 1;
//         pathVis[node] = 1;

//         // Traverse for adjacent nodes
//         for (auto it : adj[node]) {
//             // When the node is not visited
//             if (!vis[it]) {
//                 if (dfsCheck(it, adj, vis, pathVis) == true)
//                     return true;
//             }
//             // If the node has been previously visited on the same path
//             else if (pathVis[it]) {
//                 return true;
//             }
//         }

//         pathVis[node] = 0;
//         return false;
//     }

// public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<vector<int>>& edges) {
//         // Build directed adjacency list from edges
//         vector<vector<int>> adj(V);
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//         }

//         vector<int> vis(V, 0);
//         vector<int> pathVis(V, 0);

//         for (int i = 0; i < V; i++) {
//             if (!vis[i]) {
//                 if (dfsCheck(i, adj, vis, pathVis) == true)
//                     return true;
//             }
//         }

//         return false;
//     }
// };

//BFS = topological Sort(kahn's algo)
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
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
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return cnt != V;
    }
};

