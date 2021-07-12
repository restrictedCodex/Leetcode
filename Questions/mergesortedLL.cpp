// Merge two sorted linked lists and return it as a sorted list. 
// The list should be made by splicing together the nodes of the first two lists.

// Example 1:
// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                node->next = new ListNode(l1->val);
                l1 = l1->next;
                node = node->next;
            } else {
                node->next = new ListNode(l2->val);
                l2= l2->next;
                node = node->next;
            }
        }
        
        while(l1!=NULL){
            node->next = new ListNode(l1->val);
            l1 = l1->next;
            node = node->next;
        }
        while(l2!=NULL){
            node->next = new ListNode(l2->val);
            l2 = l2->next;
            node = node->next;
        }
        
        return head->next;
    }
};