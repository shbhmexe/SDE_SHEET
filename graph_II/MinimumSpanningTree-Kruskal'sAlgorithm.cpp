// Disjoint Set Data Structure
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    // Function to find sum of weights of edges of the MST using Kruskal's Algorithm
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        // Step 1: Reformat edges into {wt, {u, v}} for standard sorting
        vector<pair<int, pair<int, int>>> edgeList;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            edgeList.push_back({wt, {u, v}});
        }

        // Step 2: Sort edges by weight in ascending order
        sort(edgeList.begin(), edgeList.end());

        DisjointSet ds(V);
        int mstWt = 0;

        // Step 3: Iterate through sorted edges and apply Disjoint Set
        for (auto it : edgeList) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // If u and v do not belong to the same component, take this edge
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};