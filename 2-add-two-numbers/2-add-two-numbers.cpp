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
     if(l1==NULL)
         return l2;
        
    if(l2==NULL){
        return l1;
    }
        
        ListNode *iterator1=l1;
        ListNode *iterator2=l2;
        int carry=0;
        
        ListNode *newHead=new ListNode(-1);
        ListNode *tail=newHead;
       
        while(iterator1!=NULL&&iterator2!=NULL){
        int  sum=(iterator1->val+iterator2->val+carry);
            carry=sum/10;
            
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            iterator1=iterator1->next;
            iterator2=iterator2->next;
            
        }
        
        while(iterator1!=NULL){
            
            int sum=(iterator1->val+carry);
            
            carry=sum/10;
            
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            iterator1=iterator1->next;
        
        }
        
        while(iterator2!=NULL){
            
            int sum=(iterator2->val+carry);
            
            carry=sum/10;
            
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            
            iterator2=iterator2->next;
        }
        
        if(carry==1){
            tail->next=new ListNode(1);
        }
        
        return newHead->next;
        
    }
};