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


 //brute force - o(2n) extra space 
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = head;
//         stack<int> st;

//         while(temp != nullptr){
//             st.push(temp->val);
//             temp = temp->next;
//         }
        
//         temp = head;
//         while(temp != nullptr){
//             temp->val = st.top();
//             st.pop();
//             temp = temp->next;
//         }
        
//         return head;
//     }
// };

//Optimal -  Chaning links O(n)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = head;
//         ListNode* Prev = nullptr;

//         while(temp != NULL){
//             ListNode* Front = temp -> next;
//             temp -> next = Prev;
//             Prev = temp;
//             temp = Front;
//         }
       
//         return Prev;
//     }
// };


//Optimal -  Chaning links O(n)(RECURSION)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* newhead = reverseList(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = nullptr;

        return newhead;
    }
    
};