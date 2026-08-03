class Solution {
  public:
    void floydWarshall(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Convert unreachable edges (-1) to infinity (1e9)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if (i == j) matrix[i][j] = 0;
            }
        }

        // Step 2: Core Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], 
                                      matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // Step 3: Check for negative cycle
        for (int i = 0; i < n; i++) {
            if (matrix[i][i] < 0) {
                // Negative cycle present
            }
        }

        // Step 4: Convert infinity (1e9) back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};