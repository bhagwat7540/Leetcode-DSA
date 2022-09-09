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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *iterator1=head;
        ListNode *iterator2=head;
        
        while(n-->0){
            iterator2=iterator2->next;
        }
        ListNode *previous=NULL;
        while(iterator2!=NULL){
            previous=iterator1;
            iterator1=iterator1->next;
            iterator2=iterator2->next;
        }
        
        if(previous==NULL){
            return iterator1->next;
        }
        
        previous->next=iterator1->next;
        
        return head;
        
        
        
    }
};