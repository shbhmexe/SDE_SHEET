class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Convert Edge List into Adjacency List -> adj[u] = {{v, weight}, ...}
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // Undirected graph
        }

        // Step 2: Prim's Algorithm
        // Min-heap storing pairs: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        // Start from node 0 with edge weight 0
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            // Skip if node is already included in the MST
            if (vis[node] == 1) continue;

            // Include node in MST
            vis[node] = 1;
            sum += wt;

            for (const auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edW = neighbor.second;

                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }
};