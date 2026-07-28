// //Brute force 
// class Solution {
// private:
//     TreeNode* insert(TreeNode* root, int val) {
//         if (root == NULL) {
//             return new TreeNode(val);
//         }
//         if (val < root->val) {
//             root->left = insert(root->left, val);
//         } else {
//             root->right = insert(root->right, val);
//         }
//         return root;
//     }

// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root = NULL;
//         for (int i = 0; i < preorder.size(); i++) {
//             root = insert(root, preorder[i]);
//         }
//         return root;
//     }
// };


//Optimizw
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int &i, int bound) {
        if (i >= preorder.size() || preorder[i] > bound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};