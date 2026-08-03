//Min - Heap
// class Solution {
// public:
//     vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
//         // Use pair<int, int> instead of vector<int> to avoid huge vector allocation overhead
//         vector<vector<pair<int, int>>> adj(V);
//         for (const auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w}); // Graph is undirected
//         }

//         // Min-heap priority queue storing pairs: {distance, node}
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<int> dist(V, 1e9);

//         dist[src] = 0;
//         pq.push({0, src});

//         while (!pq.empty()) {
//             int dis = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();

//             // ⚡ TLE FIX 1: Skip stale entries that were already processed with a shorter distance
//             if (dis > dist[node]) continue;

//             for (const auto& neighbor : adj[node]) {
//                 int adjNode = neighbor.first;
//                 int edgeWeight = neighbor.second;

//                 // Relaxation step
//                 if (dis + edgeWeight < dist[adjNode]) {
//                     dist[adjNode] = dis + edgeWeight;
//                     pq.push({dist[adjNode], adjNode});
//                 }
//             }
//         }

//         return dist;
//     }
// };

//Sets 

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Build Adjacency List: adj[u] = {{v, weight}, ...}
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Graph is undirected
        }

        // Step 2: Set-based Dijkstra
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for (const auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgW = neighbor.second;

                if (dis + edgW < dist[adjNode]) {
                    // Erase existing record if it was updated previously
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};