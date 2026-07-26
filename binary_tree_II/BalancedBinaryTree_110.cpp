// //Brute force - recursive - O(n^2)
// class Solution {
// private:
//     int height(TreeNode* node) {
//         if (!node) return 0;
//         return 1 + max(height(node->left), height(node->right));
//     }

//     bool check(TreeNode* node) {
//         if (!node) return true;
        
//         int lh = height(node->left);
//         int rh = height(node->right);
        
//         if (abs(rh - lh) > 1) return false;
        
//         bool left = check(node->left);
//         bool right = check(node->right);
        
//         if (!left || !right) return false;
        
//         return true;
//     }

// public:
//     bool isBalanced(TreeNode* root) {
//         return check(root);
//     }
// };

//Optimize - DFS
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    
    int dfsHeight(TreeNode* root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1;
        
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};