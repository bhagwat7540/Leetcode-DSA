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
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head , *fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head , *prev = NULL;
        
        while(curr){
            ListNode* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* mid = getMid(head);
        
        ListNode* head1 = mid->next;
        mid->next = NULL;
        
        head1 = reverse(head1);
        
        while(head && head1){
            if(head->val != head1->val) return false;
            head = head->next;
            head1 = head1->next;
        }
        
        return true;
    }
};