
//Inorder Traversal 
class Solution {
public:
    void inorder(TreeNode* node, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (node == nullptr) {
            return;
        }
        
        // Traverse left child
        inorder(node->left, x - 1, y + 1, nodes);
        
        // Process current node
        nodes[x][y].insert(node->val);
        
        // Traverse right child
        inorder(node->right, x + 1, y + 1, nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        
        // Call the inorder traversal function starting at (0, 0)
        inorder(root, 0, 0, nodes);
        
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};