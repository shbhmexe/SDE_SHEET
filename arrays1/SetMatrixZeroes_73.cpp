// brute force 
// class Solution {
// private:
//     void markRow(vector<vector<int>>& matrix, int n, int m, int i) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }

//     void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
//         for (int i = 0; i < n; i++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }

// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     markRow(matrix, n, m, i);
//                     markCol(matrix, n, m, j);
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == -1) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };

// // better 
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int col0 = 1;

//         for (int i = 0; i < n; i++) {
//             if (matrix[i][0] == 0) col0 = 0;
//             for (int j = 1; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = m - 1; j >= 1; j--) {
//                 if (matrix[i][0] == 0 || matrix[0][j] == 0) {
//                     matrix[i][j] = 0;
//                 }
//             }
//             if (col0 == 0) {
//                 matrix[i][0] = 0;
//             }
//         }
//     }
// };

//optimal 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};