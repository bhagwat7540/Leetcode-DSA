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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(l1 || l2 || carry){
            ListNode* temp = new ListNode(0);
            
            curr->next = temp;
            
            temp->val += l1 ? l1->val : 0;
            temp->val += l2 ? l2->val : 0;
            temp->val += carry ? carry : 0;
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            carry = temp->val/10;
            temp->val = temp->val%10;
            
            curr = temp;
        }
        
        return dummy->next;
    }
};