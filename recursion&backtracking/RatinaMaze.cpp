//Recusrion + backtracing 
class Solution {
  public:
  
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
        return (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0 && maze[x][y] == 1);
    }
  
    void solve(int x, int y, vector<vector<int>>& maze, int n, vector<vector<int>>& visited, string path, vector<string>& ans) {
        
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // Down
        if (isSafe(x + 1, y, n, visited, maze)) {
            solve(x + 1, y, maze, n, visited, path + 'D', ans);
        }
        
        // Left
        if (isSafe(x, y - 1, n, visited, maze)) {
            solve(x, y - 1, maze, n, visited, path + 'L', ans);
        }
        
        // Right
        if (isSafe(x, y + 1, n, visited, maze)) {
            solve(x, y + 1, maze, n, visited, path + 'R', ans);
        }
        
        // Up
        if (isSafe(x - 1, y, n, visited, maze)) {
            solve(x - 1, y, maze, n, visited, path + 'U', ans);
        }
        
        visited[x][y] = 0;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        vector<string> ans;
        int n = maze.size();
        
        if (maze[0][0] == 0)
            return ans;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        
        solve(0, 0, maze, n, visited, path, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};