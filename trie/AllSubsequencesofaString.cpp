// //power set 
// class Solution {
// public:
//     vector<string> powerSet(string &s) {
//         int n = s.length();
//         vector<string> ans;

//         for (int num = 0; num < (1 << n); num++) {
//             string sub = "";
//             for (int i = 0; i < n; i++) {
//                 if (num & (1 << i)) {
//                     sub += s[i];
//                 }
//             }
//             ans.push_back(sub);
//         }

//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };

//trie - tle 
struct Node {
    Node* links[26];
    bool isEnd = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;

    void dfs(Node* node, string current, vector<string>& result) {
        if (node->isEnd) {
            result.push_back(current);
        }

        for (int i = 0; i < 26; i++) {
            if (node->links[i] != nullptr) {
                dfs(node->links[i], current + char('a' + i), result);
            }
        }
    }

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->isEnd = true;
    }

    vector<string> getSortedSubsequences() {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};

class Solution {
private:
    void generateSubsequences(int index, string& s, string current, Trie& trie) {
        if (index == s.length()) {
            trie.insert(current);
            return;
        }

        // Include current character
        generateSubsequences(index + 1, s, current + s[index], trie);

        // Exclude current character
        generateSubsequences(index + 1, s, current, trie);
    }

public:
    vector<string> powerSet(string& s) {
        Trie trie;
        generateSubsequences(0, s, "", trie);
        return trie.getSortedSubsequences();
    }
};