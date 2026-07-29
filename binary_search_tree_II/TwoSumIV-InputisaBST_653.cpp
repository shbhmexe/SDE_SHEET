// //Brute force - Inorder + two sum O(N)  = O(2n)
// class Solution {
// private:
//     void inorder(TreeNode* root, vector<int>& nums) {
//         if (root == NULL) return;
//         inorder(root->left, nums);
//         nums.push_back(root->val);
//         inorder(root->right, nums);
//     }
// public:
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> nums;
//         inorder(root, nums);
//         int left = 0, right = nums.size() - 1;
//         while (left < right) {
//             int sum = nums[left] + nums[right];
//             if (sum == k) {
//                 return true;
//             } else if (sum < k) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }
//         return false;
//     }
// };

//Optimize- using BST Iterator 
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse; // false = normal inorder (smallest to largest), true = reverse inorder (largest to smallest)

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        if (reverse) {
            pushAll(tmpNode->left);
        } else {
            pushAll(tmpNode->right);
        }
        return tmpNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        // Iterator for the smallest elements (left pointer)
        BSTIterator l(root, false);
        // Iterator for the largest elements (right pointer)
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        
        return false;
    }
};