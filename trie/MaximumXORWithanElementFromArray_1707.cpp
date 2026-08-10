// //brute force - tle 
// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         int q = queries.size();
//         int n = nums.size();
//         vector<int> ans;

//         for (int i = 0; i < q; i++) {
//             int xi = queries[i][0];
//             int ai = queries[i][1];

//             int maxXOR = -1;

//             for (int j = 0; j < n; j++) {
//                 if (nums[j] <= ai) {
//                     maxXOR = max(maxXOR, nums[j] ^ xi);
//                 }
//             }

//             ans.push_back(maxXOR);
//         }

//         return ans;
//     }
// };

//optimal 
struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int q = queries.size();
        vector<vector<int>> offlineQueries(q); // {ai, xi, originalIndex}

        for (int i = 0; i < q; i++) {
            offlineQueries[i] = {queries[i][1], queries[i][0], i};
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(q);
        Trie trie;
        int idx = 0;
        int n = nums.size();

        for (int i = 0; i < q; i++) {
            int ai = offlineQueries[i][0];
            int xi = offlineQueries[i][1];
            int queryIdx = offlineQueries[i][2];

            while (idx < n && nums[idx] <= ai) {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx == 0) {
                ans[queryIdx] = -1;
            } else {
                ans[queryIdx] = trie.getMax(xi);
            }
        }

        return ans;
    }
};