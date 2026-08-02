// //BFS 
// class Solution {
// private:
//     bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
//         queue<int> q;
//         q.push(start);
//         color[start] = 0;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             for (auto it : graph[node]) {
//                 // If the adjacent node is not yet colored,
//                 // give it the opposite color of the current node
//                 if (color[it] == -1) {
//                     color[it] = !color[node];
//                     q.push(it);
//                 }
//                 // If the adjacent node has the same color,
//                 // the graph is not bipartite
//                 else if (color[it] == color[node]) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<int> color(V, -1);

//         // Check every component in case the graph is disconnected
//         for (int i = 0; i < V; i++) {
//             if (color[i] == -1) {
//                 if (check(i, graph, color) == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };


//DFS

class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;

        for (auto it : graph[node]) {
            // If the node is not colored, color it with the opposite color (!col)
            if (color[it] == -1) {
                if (dfs(it, !col, color, graph) == false) return false;
            }
            // If the adjacent node has the same color, it's not bipartite
            else if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        // Check each component (handles disconnected graphs)
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }
        
        return true;
    }
};