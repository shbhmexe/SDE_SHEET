// //Brute force 
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> vals;
        
//         for (int i = 0; i < lists.size(); i++) {
//             ListNode* curr = lists[i];
//             while (curr != nullptr) {
//                 vals.push_back(curr->val);
//                 curr = curr->next;
//             }
//         }
        
//         sort(vals.begin(), vals.end());
        
//         ListNode* dummy = new ListNode(0);
//         ListNode* temp = dummy;
        
//         for (int i = 0; i < vals.size(); i++) {
//             temp->next = new ListNode(vals[i]);
//             temp = temp->next;
//         }
        
//         return dummy->next;
//     }
// };

// //Better - Merge 2 list 
// class Solution {
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* temp = dummy;
        
//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val <= l2->val) {
//                 temp->next = l1;
//                 l1 = l1->next;
//             } else {
//                 temp->next = l2;
//                 l2 = l2->next;
//             }
//             temp = temp->next;
//         }
        
//         if (l1 != nullptr) {
//             temp->next = l1;
//         }
//         if (l2 != nullptr) {
//             temp->next = l2;
//         }
        
//         return dummy->next;
//     }

// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (lists.size() == 0) {
//             return nullptr;
//         }
        
//         ListNode* head = lists[0];
        
//         for (int i = 1; i < lists.size(); i++) {
//             head = mergeTwoLists(head, lists[i]);
//         }
        
//         return head;
//     }
// };

//OPtimisze - min heap
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            if (it.second->next != nullptr) {
                pq.push({it.second->next->val, it.second->next});
            }
            
            temp->next = it.second;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};