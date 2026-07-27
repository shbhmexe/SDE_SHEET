class Solution {
public:
    bool isSumProperty(Node *root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        
        int leftVal = root->left ? root->left->data : 0;
        int rightVal = root->right ? root->right->data : 0;
        
        return (root->data == leftVal + rightVal) && 
               isSumProperty(root->left) && 
               isSumProperty(root->right);
    }
};