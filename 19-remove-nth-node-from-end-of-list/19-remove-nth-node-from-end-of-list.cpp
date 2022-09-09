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
    
    int findLengthOfLinkedList(ListNode *head){
        
        ListNode *iterator=head;
        int length=0;
        while(iterator!=NULL){
            length++;
            iterator=iterator->next;
        }
        
        return length;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int loop=findLengthOfLinkedList(head)-n;
        ListNode *previous=NULL;
        ListNode *iterator=head;
        while(loop-->0){
            
            previous=iterator;
            iterator=iterator->next;
        }
        
       ListNode *next=iterator->next;
        iterator->next=NULL;
        
        if(previous==NULL){
            return next;
        }
        
        previous->next=next;
        
        
        return head;
        
        
    }
};