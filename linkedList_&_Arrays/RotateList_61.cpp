/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
 
 class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp != nullptr){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    } 
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* tail = head;
        
        int len = 1; 
        
        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }
        
        if(k % len == 0){
            return head;
        }
        
        k = k % len;
        tail->next = head;

        ListNode* newlastNode = findNthNode(head, len - k);
        head = newlastNode->next;
        newlastNode->next = nullptr;

        return head;
    }
};