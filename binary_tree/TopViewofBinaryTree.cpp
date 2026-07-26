class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        map<int, int> m;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* curr = it.first;
            int hd = it.second;
            
            if (m.find(hd) == m.end()) {
                m[hd] = curr->data;
            }
            
            if (curr->left != NULL) {
                q.push({curr->left, hd - 1});
            }
            
            if (curr->right != NULL) {
                q.push({curr->right, hd + 1});
            }
        }
        
        for (auto it : m) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};