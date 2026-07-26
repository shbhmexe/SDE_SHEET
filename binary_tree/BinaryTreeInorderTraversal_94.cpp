// //Recursive
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& result) {
//         if (root == nullptr) {
//             return;
//         }
//         inorder(root->left, result);
//         result.push_back(root->val);
//         inorder(root->right, result);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
// };

// //Stack 
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         TreeNode* node = root;
//         vector<int> inorder;
//         while(true) {
//             if(node != NULL) {
//                 st.push(node);
//                 node = node->left;
//             }
//             else {
//                 if(st.empty() == true) break;
//                 node = st.top();
//                 st.pop();
//                 inorder.push_back(node->val);
//                 node = node->right;
//             }
//         }
//         return inorder;
//     }
// };

//approach - 3 - morris inorder (using inorder predecessor and thread)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};