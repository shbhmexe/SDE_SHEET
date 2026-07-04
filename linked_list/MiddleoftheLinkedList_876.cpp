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


//two pass solution
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* temp = head;
//         int cnt = 0;

//         while(temp != nullptr){
//             cnt++;
//             temp = temp->next;
//         }
        
//         int midNode = (cnt / 2) + 1;
//         temp = head;
        
//         while(temp != nullptr){
//             midNode = midNode - 1;
//             if(midNode == 0) break;
//             temp = temp->next;
//         }
        
//         return temp;
//     }
// };


//one pass - slow and fast ptr
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};