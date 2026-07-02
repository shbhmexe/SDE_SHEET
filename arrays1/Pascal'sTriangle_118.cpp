//Question2 july26
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> result(n);

        for(int i = 0; i < numRows; i++){
            result[i] = vector<int>(i + 1, 1);

            for(int j = 1; j < i; j++){
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }
        return result;
    }
};