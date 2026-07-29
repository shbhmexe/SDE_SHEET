class Solution {
private:
    int cnt = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        if (root->left != NULL) {
            int leftAns = kthSmallest(root->left, k);
            if (leftAns != -1) {
                return leftAns;
            }
        }

        cnt++;
        if (cnt == k) {
            return root->val;
        }

        if (root->right != NULL) {
            int rightAns = kthSmallest(root->right, k);
            if (rightAns != -1) {
                return rightAns;
            }
        }

        return -1;
    }
};