//Recusrive 
class Solution {
private:
    Node* rightMostInLeftSubtree(Node* root) {
        Node* ans = NULL;
        while (root != NULL) {
            ans = root;
            root = root->right;
        }
        return ans;
    }

    Node* leftMostInRightSubtree(Node* root) {
        Node* ans = NULL;
        while (root != NULL) {
            ans = root;
            root = root->left;
        }
        return ans;
    }

public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* curr = root;
        Node* pre = NULL;
        Node* succ = NULL;

        while (curr != NULL) {
            if (key < curr->data) {
                succ = curr;
                curr = curr->left;
            } else if (key > curr->data) {
                pre = curr;
                curr = curr->right;
            } else {
                if (curr->left != NULL) {
                    pre = rightMostInLeftSubtree(curr->left);
                }
                if (curr->right != NULL) {
                    succ = leftMostInRightSubtree(curr->right);
                }
                break;
            }
        }
        return {pre, succ};
    }
};