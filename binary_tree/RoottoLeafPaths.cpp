//Inorder Traversal
class Solution {
private:
    void getPaths(Node* root, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!root) {
            return;
        }
        
        currentPath.push_back(root->data);
        
        if (!root->left && !root->right) {
            result.push_back(currentPath);
        } else {
            getPaths(root->left, currentPath, result);
            getPaths(root->right, currentPath, result);
        }
        
        currentPath.pop_back();
    }
    
public:
    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        getPaths(root, currentPath, result);
        return result;
    }
};