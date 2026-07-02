//Question 9 july26 - O(n2 + n)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mat = matrix.size();

        for(int i = 0; i < mat - 1; i++){
            for(int j = i + 1; j < mat; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < mat; i++){
            reverse(matrix[i].begin(), matrix[i].end());
            
        }
    }
};