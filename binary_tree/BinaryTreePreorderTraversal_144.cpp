// //Recursive
// class Solution {
// public:
//     void preOrder(TreeNode* root, vector<int>& result) {
//         if (root == nullptr) {
//             return;
//         }
//         result.push_back(root->val);
//         preOrder(root->left, result);
//         preOrder(root->right, result);
//     }

//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         preOrder(root, result);
//         return result;
//     }
// };


//Morris - preorder traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;
                
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }
                
                if (IP->right == NULL) {
                    ans.push_back(curr->val);
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};