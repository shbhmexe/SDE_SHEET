struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfAllPrefixesExist(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                if (!node->isEnd()) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for (auto &word : words) {
            trie.insert(word);
        }

        string longest = "";

        for (auto &word : words) {
            if (trie.checkIfAllPrefixesExist(word)) {
                if (word.length() > longest.length()) {
                    longest = word;
                } else if (word.length() == longest.length() && word < longest) {
                    longest = word;
                }
            }
        }

        return longest;
    }
};