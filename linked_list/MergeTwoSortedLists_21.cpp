// //brute force - O(N \log N)
// class Solution {
// public:
//     ListNode* constructLL(vector<int>& arr) {
//         if(arr.empty()) return nullptr;
        
//         ListNode* head = new ListNode(arr[0]);
//         ListNode* temp = head;
        
//         for(int i = 1; i < arr.size(); i++){
//             temp->next = new ListNode(arr[i]);
//             temp = temp->next;
//         }
        
//         return head;
//     }

//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         vector<int> arr;
//         ListNode* temp1 = list1;
//         ListNode* temp2 = list2;
        
//         while(temp1 != nullptr){
//             arr.push_back(temp1->val);
//             temp1 = temp1->next;
//         }
        
//         while(temp2 != nullptr){
//             arr.push_back(temp2->val);
//             temp2 = temp2->next;
//         }

//         sort(arr.begin(), arr.end());
//         ListNode* head = constructLL(arr);
        
//         return head;
//     }
// };


//Optimal  - O(n1+n2)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(t1 != nullptr && t2 != nullptr){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2; 
                temp = t2;
                t2 = t2->next;
            }
        }
        
        if(t1 != nullptr){
            temp->next = t1;
        }
        else {
            temp->next = t2;
        }
        
        return dummyNode->next;
    }
};