// //brute force - tle
// class Solution {
// public:
//     int countSubs(string& s) {
//         int n = s.length();
//         unordered_set<string> st;

//         for (int i = 0; i < n; i++) {
//             string temp = "";
//             for (int j = i; j < n; j++) {
//                 temp += s[j];
//                 st.insert(temp);
//             }
//         }

//         return st.size();
//     }
// };

//optimal - trie
struct Node {
    Node* links[26];

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

class Solution {
public:
    int countSubs(string& s) {
        int n = s.length();
        Node* root = new Node();
        int count = 0;

        for (int i = 0; i < n; i++) {
            Node* node = root;
            for (int j = i; j < n; j++) {
                if (!node->containsKey(s[j])) {
                    count++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }

        return count;
    }
}; 