/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //Recursive - story 
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int l = solve(root -> left);
        int r = solve(root -> right);

        int all = l + r + root -> val;

        int only1 = max(l, r) + root -> val;

        int rootOnly = root -> val;

        maxSum = max({maxSum ,  all , only1 , rootOnly});

        return max(only1,rootOnly);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);
        return maxSum;

    }
};