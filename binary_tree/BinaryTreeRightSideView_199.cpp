// //recursive
// class Solution {
// public:
//     void recursion(TreeNode *root, int level, vector<int> &res) {
//         if (root == NULL) return;
//         if (res.size() == level) res.push_back(root->val);
//         recursion(root->right, level + 1, res);
//         recursion(root->left, level + 1, res);
//     }

//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         recursion(root, 0, res);
//         return res;
//     }
// };

// Iterative 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (i == n - 1) res.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return res;
    }
};