/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//Extra Space - hashmap - O(2n)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* temp = head;
//         unordered_map<Node*, Node*> mpp;

//         while(temp != nullptr){
//             Node* newNode = new Node(temp->val);
//             mpp[temp] = newNode;
//             temp = temp->next;
//         }
        
//         temp = head;
//         while(temp != nullptr){
//             Node* copyNode = mpp[temp];
//             copyNode->next = mpp[temp->next];
//             copyNode->random = mpp[temp->random];
//             temp = temp->next;
//         }
        
//         return mpp[head];
//     }
// };

//Optimize without any extra space
class Solution {
private:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            
            copy->next = nextElement;
            temp->next = copy;
            
            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = temp->next;
            
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }
            
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        
        while (temp != nullptr) {
            // creating new list
            res->next = temp->next;
            res = res->next;
            
            // disconnecting and going back to initial state of the LL
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};