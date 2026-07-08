/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

//Brute force
// class Solution {
// public:
//     Node* convertLL(vector<int>& arr) {
//         if(arr.empty()) {
//             return nullptr;
//         } 
        
//         Node* head = new Node(arr[0]);
//         Node* temp = head;
        
//         for(int i = 1; i < arr.size(); i++) {
//             Node* newNode = new Node(arr[i]);
//             temp->bottom = newNode;
//             temp = temp->bottom;
//         }
        
//         return head;
//     }
    
//     Node* flatten(Node* root) {
//         if (root == nullptr) return nullptr;
        
//         vector<int> arr;
//         Node* temp = root;
        
//         while(temp != nullptr) {
//             Node* t2 = temp;
            
//             while(t2 != nullptr) {
//                 arr.push_back(t2->data);
//                 t2 = t2->bottom;
//             }
//             temp = temp->next;
//         }
        
//         sort(arr.begin(), arr.end());
//         return convertLL(arr);
//     }
// };


//Optimal - recursion and backtracing
class Solution {
    Node* merge(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->data < list2->data) {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = nullptr;
        }
        
        if(list1) res->bottom = list1;
        else res->bottom = list2;
        
        if(dummyNode->bottom) dummyNode->bottom->next = nullptr;
        
        return dummyNode->bottom;
    }

public:
    Node* flatten(Node* root) {
        if (root == nullptr || root->next == nullptr) return root;
        
        Node* mergedHead = flatten(root->next);
        root = merge(root, mergedHead);
        
        return root;
    }
};