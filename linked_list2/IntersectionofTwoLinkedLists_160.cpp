// //Brute force 
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> st;
//         ListNode* temp = headA;

//         while(temp != nullptr){
//             st.insert(temp);
//             temp = temp->next;
//         }

//         temp = headB;
//         while(temp != nullptr){
//             if(st.find(temp) != st.end()){
//                 return temp;
//             }
//             temp = temp->next;
//         }
        
//         return nullptr;
//     }
// };

//Optimal  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        } 
        
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            t1 = t1 == nullptr ? headB : t1->next;
            t2 = t2 == nullptr ? headA : t2->next;
        }
        
        return t1;
    }
};