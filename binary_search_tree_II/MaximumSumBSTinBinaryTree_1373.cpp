// //Brute force - O(N^2) validate bst + traversal - tle
// class Solution {
// private:
//     bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
//         if (root == nullptr) return true;
//         if (root->val <= minVal || root->val >= maxVal) return false;
//         return isValidBST(root->left, minVal, root->val) && 
//                isValidBST(root->right, root->val, maxVal);
//     }

//     int getSum(TreeNode* root) {
//         if (root == nullptr) return 0;
//         return root->val + getSum(root->left) + getSum(root->right);
//     }

//     void traverse(TreeNode* root, int& maxSum) {
//         if (root == nullptr) return;

//         if (isValidBST(root, LLONG_MIN, LLONG_MAX)) {
//             maxSum = max(maxSum, getSum(root));
//         }

//         traverse(root->left, maxSum);
//         traverse(root->right, maxSum);
//     }

// public:
//     int maxSumBST(TreeNode* root) {
//         int maxSum = 0;
//         traverse(root, maxSum);
//         return maxSum;
//     }
// };


class NodeVal {
public:
    int minValue;
    int maxValue;
    int sum;
    bool isBST;
    
    NodeVal(int minV, int maxV, int s, bool b) {
        minValue = minV;
        maxValue = maxV;
        sum = s;
        isBST = b;
    }
};

class Solution {
private:
    int globalMaxSum = 0;

    NodeVal maxSumBSTHelper(TreeNode* root) {
        if (!root) {
            return NodeVal(INT_MAX, INT_MIN, 0, true);
        }

        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        if (left.isBST && right.isBST && left.maxValue < root->val && root->val < right.minValue) {
            int currentSum = left.sum + right.sum + root->val;
            globalMaxSum = max(globalMaxSum, currentSum);
            return NodeVal(
                min(root->val, left.minValue),
                max(root->val, right.maxValue),
                currentSum,
                true
            );
        }

        return NodeVal(0, 0, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        globalMaxSum = 0;
        maxSumBSTHelper(root);
        return globalMaxSum;
    }
};