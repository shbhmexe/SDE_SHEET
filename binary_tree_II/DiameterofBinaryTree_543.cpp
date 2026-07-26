// //Brute force 
// class Solution {
// private:
//     int height(TreeNode* node) {
//         if (!node) return 0;
//         return 1 + max(height(node->left), height(node->right));
//     }

// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         if (!root) return 0;
        
//         int lh = height(root->left);
//         int rh = height(root->right);
//         int current = lh + rh;
        
//         int leftSub = diameterOfBinaryTree(root->left);
//         int rightSub = diameterOfBinaryTree(root->right);
        
//         return max({current, leftSub, rightSub});
//     }
// };


//Optimize - hieght of tree 
class Solution {
private:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        
        diameter = max(diameter, lh + rh);
        
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};