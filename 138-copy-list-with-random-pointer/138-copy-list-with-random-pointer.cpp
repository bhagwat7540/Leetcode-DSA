/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
//         map<Node* , Node*> mp;
        
//         Node* ptr = head;
//         while(ptr){
//             mp[ptr] = new Node(ptr->val);
//             ptr = ptr->next;
//         }
        
//         ptr = head;
        
//         while(ptr){
//             mp[ptr]->next = mp[ptr->next];
//             mp[ptr]->random = mp[ptr->random];
//             ptr = ptr->next;
//         }
        
//         return mp[head];
        
        Node* ptr = head;
        
        while(ptr){
            Node* front = ptr->next;
            Node* copy = new Node(ptr->val);
            ptr->next = copy;
            copy->next = front;
            ptr = front;
        }
        
        ptr = head;
        while(ptr){
            if(ptr->random){
               ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next; 
        }
        
        Node* dummy = new Node(0);
        Node* temp = dummy;
        ptr = head;
        
        while(ptr){
            Node* front = ptr->next->next;
            temp->next = ptr->next;
            ptr->next = front;
            ptr = front;
            temp = temp->next;
        }
        
        return dummy->next;
        
    }
};