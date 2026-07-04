// //Brute Force - Two Pass
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (head == nullptr) return nullptr;
        
//         int cnt = 0;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             cnt++;
//             temp = temp->next;
//         }
        
//         if (cnt == n) {
//             ListNode* newHead = head->next;
//             delete head;
//             return newHead;
//         }
        
//         int res = cnt - n;
//         temp = head;
//         while (temp != nullptr) {
//             res--;
//             if (res == 0) {
//                 break;
//             }
//             temp = temp->next;
//         }
        
//         ListNode* delNode = temp->next;
//         temp->next = temp->next->next;
//         delete delNode;
        
//         return head;
//     }
// };

//Optimal - One pass - slow and fast ptr
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;
    }
};

