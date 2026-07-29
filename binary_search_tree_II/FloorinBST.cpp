class Solution {
public:
    int findMaxFork(Node* root, int k) {
        int floor = -1;
        while (root != NULL) {
            if (root->data == k) {
                floor = root->data;
                return floor;
            }
            if (k > root->data) {
                floor = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }
};