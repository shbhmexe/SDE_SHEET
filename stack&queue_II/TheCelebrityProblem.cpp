// //Burte force 
// class Solution {
// public:
//     int celebrity(vector<vector<int>>& mat) {
//         int n = mat.size();
//         vector<int> knowMe(n, 0);
//         vector<int> IKnow(n, 0);

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == 1 && i != j) {
//                     knowMe[j]++;
//                     IKnow[i]++;
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             if (knowMe[i] == n - 1 && IKnow[i] == 0) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

//oPTIMIZE -
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        
        while (top < down) {
            if (mat[top][down] == 1) {
                top++;
            } else if (mat[down][top] == 1) {
                down--;
            } else {
                top++;
                down--;
            }
        }
        
        if (top > down) return -1;
        
        for (int i = 0; i < n; i++) {
            if (i == top) continue;
            
            if (mat[top][i] == 0 && mat[i][top] == 1) {
                continue;
            } else {
                return -1;
            }
        }
        
        return top;
    }
};