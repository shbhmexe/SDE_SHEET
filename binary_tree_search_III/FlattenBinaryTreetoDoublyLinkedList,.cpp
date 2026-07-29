#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTreeToDLL {
private:
    Node* prev;
    Node* head;

public:
    BinaryTreeToDLL() {
        prev = nullptr;
        head = nullptr;
    }

    void ConvertToDLL(Node* root) {
        if (root == nullptr) return;

        ConvertToDLL(root->left);

        if (prev == nullptr) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        ConvertToDLL(root->right);
    }

    Node* getHead() {
        return head;
    }
};