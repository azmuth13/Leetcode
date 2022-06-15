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
        if(!head)
            return head;
        
        Node* head1 = head;
        
        Node* copy = new Node(head1->val);
        
        Node* copy1 = copy;
        Node* copy2 = copy;
        
        head1 = head1->next;
        
        while(head1)
        {
            Node* temp = new Node(head1->val);
            copy1->next = temp;
            copy1 = copy1->next;
            head1 = head1->next;
        }
        
        Node* concat = head;
        Node* concat2 = concat;
        Node* concat3 = concat;
        
        while(concat)
        {
            Node* store = concat->next;
            concat->next = copy2;
            copy2 = copy2->next;
            
            concat = concat->next;
            concat->next = store;
            concat = concat->next;
        }
        
        while(concat2)
        {
            if(concat2->random)
                concat2->next->random = concat2->random->next;
            else
                concat2->next->random = NULL;
            
            concat2 = concat2->next;
            concat2 = concat2->next;
        }
        
        Node* ans = concat3->next;
        Node* res = concat3->next;
        
        while(concat3)
        {
            concat3->next = res->next;
            
            if(res->next)
                res->next = res->next->next;
            
            concat3 = concat3->next;
            res = res->next;
        }
        
        return ans;
    }
};